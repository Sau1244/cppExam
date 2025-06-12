#include <iostream>
#include <string>

struct A{
    std::string s;

    /*uzupełnij 1*/
    /** Konstruktor przyjmujący nadaną mu nazwę z wyświetlającym się komentarzem o tworzeniu
     * argument `name` jest constem, żeby zapewnić, iż jego nazwa się nie zmieni przy przypisywaniu */
    A(const std::string& name) : s(name) { std::cout << "Tworzenie: " << name << std::endl; }

    /** Destruktor - w tym przykładzie niepotrzebny, ważny jest by zachować zasadę RuleOfFive */
    ~A() = default;

    /** Konstruktor kopiujący - kopiujący nazwę obiektu dla nowego utworzonego obiektu
     * wyświetla informacje o jego wykorzystaniu
     */
    A(const A& other) : s(other.s) { std::cout << "Kopiowanie wersja 2\n"; }

    /** Operator kopiujący - kopiujący nazwę obiektu dla istniejącego obiektu
     * wyświetla informacje o jego wykorzystaniu
     * warunek if zapewnia, że nie będzie kopiowany ten sam obiekt
     * */
    A& operator=(const A& other){
        std::cout << "Kopiowanie wersja 1\n";
        if(this != &other)
            s = other.s;
        return *this;
    }

    /** Konstruktor przenoszący - przenosi nazwę obiektu dla nowego utworzonego obiektu
    * wyświetla informacje o jego wykorzystaniu
     * `noexcept` zapewnia, że kontenery STL użyją przenoszenia zamiast kopiowania
     * co zwiększa wydajność
     * Dodatkowo kompilator może zastosować optymalizacje
     * */
    A(A&& other) noexcept : s(std::move(other.s)){
        std::cout << "Przenoszenie wersja 2\n";
    }

    /** Operator kopiujący - przenosi nazwę obiektu dla istniejącego obiektu
    * wyświetla informacje o jego wykorzystaniu
    * warunek if zapewnia, że nie będzie kopiowany ten sam obiekt
     * `noexcept` zapewnia, że kontenery STL użyją przenoszenia zamiast kopiowania
     * co zwiększa wydajność
     * Dodatkowo kompilator może zastosować optymalizacje
    * */
    A& operator=(A&& other) noexcept{
        std::cout << "Przenoszenie wersja 1\n";
        if(this != &other)
            s = std::move(other.s);
        return *this;
    }
};

A f(A a){ return a;}

int main(){
    A a("var_a"),b("var_b");

    std::cout<<"(1) ->"
             << "a.s ="<<a.s<<" b.s = "<<b.s<<std::endl;
    A c = a;
    std::cout<<"(2) ->"
             << "a.s ="<<a.s<<" b.s = "<<b.s<<std::endl;
    a = b;
    std::cout<<"(3) ->"
             << "a.s ="<<a.s<<" b.s = "<<b.s<<std::endl;
    a = f(A{"var_c"});

    std::cout<<"(4) ->"
             << "a.s ="<<a.s<<" b.s = "<<b.s<<std::endl;
    b = std::move(a);

    std::cout<<"(5) ->"
             << "a.s ="<<a.s<<" b.s = "<<b.s<<std::endl;
    /** Zakomentowane, ponieważ jest to błędnie napisana linijka */
    //    b - std::move(b);
}

/*output:
Tworzenie: var_a
Tworzenie: var_b
(1) -> a.s = var_a  b.s = var_b
Kopiowanie wersja 2
(2) -> a.s = var_a  b.s = var_b
Kopiowanie wersja 1
(3) -> a.s = var_b  b.s = var_b
Tworzenie: var_c
Przenoszenie wersja 2
Przenoszenie wersja 1
(4) -> a.s = var_c  b.s = var_b
Przenoszenie wersja 1
(5) -> a.s =   b.s = var_b
*/