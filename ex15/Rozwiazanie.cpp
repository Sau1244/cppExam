#include <iostream>

/**
 * Struktura A, zawierająca konstruktor domyślny oraz destruktor z wypisanie jego użycia
 */
struct A{
    A() = default;
    ~A() { std::cout << "~A()\n"; }
};

/**
 * Struktura szablonowa dziedzicząca po strukturze A
 */
template<typename T>
struct B : public A{
    T data = T(); /** Zawiera element typu wywołujący jego konstruktor domyślny */
    B() = default; /** Konstruktor domyślny z `default` ustawia jego domyślne działanie */


    /** Konstruktor kopiujący - kopiuje wartość drugiego obiektu i wyświetla informacje o kopiowaniu
     * `typeid(B<T>).name() zawiera nazwę całego obiektu a nie tylko typu
     */
    B(const B& other) : data(other.data){
        std::cout << "Copy " << typeid(B<T>).name() << "()\n";
    }

    /** Zgodnie z zasadą RuleOfThree */
    ~B() = default; /** Destruktor ustawia jego domyślne działanie */
    B& operator=(const B& other) = delete; /** operator kopiujący - usunięty, nie pozwala na ruch */
};

int main()
{
    typedef B<A> B_A;
    using TypeName = B<B_A>;
    TypeName a = TypeName(TypeName{});
    TypeName b(a);
}

/*
Copy 1BI1AE()
Copy 1BIS_I1AEE()
~A()
~A()
~A()
~A()
~A()
~A()
 */
