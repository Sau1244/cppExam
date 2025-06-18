#include <iostream>

/**
 * Klasa szablonowa przyjmująca zwykły typ parametru
 */
template<typename T>
class B{
public:
    /**
     * Konstruktor inicjalizujący nową wartość `data`
     */
    B(T newData) : data(newData){}

    /**
     * Metoda zwracająca element `data`
     */
    T get() const{ return data; }
private:
    T data; /** Zmienna `data` typu `T` */
};

/**
 * Klasa szablonowa przyjmująca typ parametru ze wskaźnikiem
 */
template<typename T>
class B<T*>{
public:
    using value_type = T; /** Tworzy alians value_type dla typu */
    B(T* arg) : data(arg){} /** Konstruktor przyjmujący wskaźnik do nowego elementu */
    ~B(){delete data;} /** Destruktor zwalniający pamięć */
    B(const B& other) = delete; /** Konstruktor kopiujący RuleOfThree - ma nie pozwalać na stworzenie nowego skopiowanego obiektu */
    B& operator=(const B& other) = delete; /** Operator kopiujący RuleOfThree - ma nie pozwalać na kopiowanie do istniejącego obiektu */
    T& get() const{ return *data; } /** Metoda zwracająca elemenent */
private:
    T* data;
};

int main()
{
    typedef B<int> int_b;
    typedef B<int*> int_p_b;        //jednak typedef

    int_b a(1);
    int_b a_copy(a);
    int_p_b b(new int_p_b::value_type{2});
//     int_p_b e = b; //error
//     b=b //error

    std::cout << "a=" << a.get() << std::endl;
    std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
    std::cout <<" b=" << b.get()+1 << std::endl;
}
/*
a=1
a_copy=2
 b=3
*/