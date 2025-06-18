#include <iostream>

/**
 * Serwis `oop` przechowujący klasę szablonową Array
 */
namespace oop{
    /**
     * Klasa szablonowa Array
     */
    template<typename T>
    class Array{
    private:
        T* data; /** Tablica przechowująca dane */
        int maxIndex; /** Określa ilość elementów w tablicy */
    public:
        using value_type = T; /** Tworzy alians typu wykorzystanego w klasie */

        /**
         * Konstruktor alokujący pamięć tablicy oraz przypisujący wartość 0 elementów
         */
        Array(size_t size) : maxIndex(0) {
            data = new T[size];
        }

        /**
         * Funkcja insert zwracająca referencję obiektu, dodająca nowy element i zwiększając wartość `maxIndex`
         */
        Array& insert(T newElement) {
            data[maxIndex++] = newElement;
            return *this;
        }

        /**
         * Operator dodawania zwracający referencję obiektu wykorzystując metodę insert, dodająca nowy element
         */
        Array& operator+(T newElement){
            return insert(newElement);
        }

        /**
         * operator [] zwracający element tablicy o indeksie `index`
         */
        T operator[](size_t index){
            return data[index];
        }

        /**
         * Operator ~ zwracający ilość elementów w tablicy
         */
        size_t operator~(){
            return maxIndex;
        }

    };
}

namespace std{
    class vector{};
    class list{};
    class deque{};
    class set{};
    class map{};
}

#include<cstdlib>
#include <iostream>

int main(){

    typedef oop::Array<char> type;
    type a( rand() % 10 + 6 );

    a.insert('#').insert('C') + type::value_type('+') + '+' + '0' + ('0' + 3 );

    for(unsigned i = 0; i!= ~a; ++i)
        std::cout<< a[i] << (i+1 != ~a ? "" : "\n"  );
}

/*
  #C++03
*/