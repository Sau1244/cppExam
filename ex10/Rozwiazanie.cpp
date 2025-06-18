#include <iostream>
#include <utility>

/**
 * Struktura szablonowa, z szablonem domyślnym float
 */
template<typename T = float>
struct Type_t{
    T _v; /** Argument typu T (domyślnie float) */

    Type_t() = default; /** Konstruktor domyślny */
    Type_t(T num) : _v(num){}; /** Konstruktor inicjalizujący wartość argumentu - na potrzeby tego kodu jest niepotrzebny */

    /**
     * Przeciążenie operatora << wyświetlający wartość _v
     * */
    friend std::ostream& operator<<(std::ostream& os, const Type_t& t){
        return os << t._v;
    }
};

/**
 * Klasa szablonowa przechowująca wskaźnik
 */
template<typename T>
class ptr{
private:
    T* data; /** Wskaźnik przechowywanej wartości */
public:
    using value_type = T; /** Alians typu */
    ptr() = default; /** Konstruktor domyślny - tutaj niepotrzebny */

    /**
     * Konstruktor inicjalizujący wartość
     * `explicit` podany, aby jedyne możliwe wywołanie konstruktora było jawne
     */
    explicit ptr(T* newData) : data(newData){}

    /** Rule of Five **/

    /** Destruktor - zwalnia pamięć wskaźnika */
    ~ptr() {delete data;}

    /** Konstruktor kopiujący - nie zezwala na tworzenie obiektu z kopią */
    ptr(const ptr& other) = delete;
    /** Operator kopiujący - nie zezwala na kopiowanie do istniejącego obiektu */
    ptr& operator=(const ptr& other) = delete;
    /** Operator przenoszący - nie zezwala na przenoszenie do istniejącego obiektu */
    ptr& operator=(ptr&& other) = delete;
    /** Konstruktor przenoszący */
    ptr(ptr&& other){
        data = other.data;
        other.data = nullptr;
    }

    /** Operator * zwracający referencję do wskaźnika elementu `const` */
    T& operator*() const{
        return *data;
    }

    /** Operator -> zwracający wskaźnik wartości `const` */
    T* operator->() const{
        return data;
    }
};

using Float_t = Type_t<>;

int main()
{
    using Type_t = ptr<std::pair<Float_t, Float_t>>;

    Type_t t1{new Type_t::value_type{}};
    // Type_t t2 = t1;
    // Type_t t2; t2 = t1;
//     Type_t t2 = new Type_t::value_type();
    // Powyższe się mają nie kompilować
    (*t1).first = Type_t::value_type::first_type{1.};
    t1->second = Type_t::value_type::second_type{2.5};

    Type_t t2 = std::move(t1);

    // t3=std::move(t2); 
    const Type_t t3{new Type_t::value_type{}};
    //(*t3).first= 13;
    // t3->second = 13;
    // Powyższe się mają nie kompilować
    (*t3).first = Type_t::value_type::first_type{1};
    t3->second = Type_t::value_type::second_type{2.5};


    std::cout << (*t3).first._v << ", " << t3->second << std::endl;
}
/* output:
1, 2.5
*/