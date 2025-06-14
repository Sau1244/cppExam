#include <iostream>
#include <cstdlib>
#include <vector>

/** Szablon z którego korzystamy w trakcie zadania */
namespace OOP{
    template<typename T> // Templatka okreslajaca typ klasy
    class Array{
    private:
        std::vector<T> vec; // wektor mający elementy klasy
    public:
        using value_type = T; // alians będący `T` - pełnić rolę może rzutowania
        Array(int size){} // konstruktor przyjmujący parametr wielkości (cokolwiek)

        /** Metoda dodająca kolejny znak do wektora*/
        Array& insert(char c){
            vec.push_back(c);
            return *this;
        }

        /** operator % korzystający z funkcji `insert`*/
        Array& operator%(char c){
            return insert(c);
        }

        /** Operator [] zwracający wartość o danym indexie*/
        T& operator[](int index){
            return vec[index];
        }

        /** Operator ~ zwracający wielkość wektora */
        int operator~(){
            return vec.size();
        }
    };
}

int main()
{
    typedef ::OOP::Array<int> type;
    type a(rand() % 100 + 10); // nie trzeba seedować żeby program się wykonał

    a.insert('#' - 1).insert('P') % type::value_type('O') % ('-') % ('E') % ('G') % ('Z') % ('1');

    ++a[0];
    for (unsigned i = 0; i != ~a; i++){
        std::cout << static_cast<char>(a[i]) << (i + 1 != ~a ? '_' : '\n');
    }
}
//#_P_O_-_E_G_Z_1