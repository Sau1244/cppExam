#include <iostream>

struct Obj; template<typename T> struct Box;

/**
 * Struktura czysto abstrakcyjna Obj
 *
 * destruktor wirtualny potrzebny, aby poprawnie działały
 * funkcje wirtualne
 * = default oznacza, że kompilator sam go wygeneruje
 *
 * virtual void Draw() const = 0 przyrównane jest do zera
 * ponieważ w ten sposób tworzy się abstrakcyjna siatka metody
 * */
struct Obj{
    virtual ~Obj() = default;
    virtual void Draw() const = 0;
};

/**
 * Deklaracja szablonu daje domyślnie parametr typu `int`
 * dzięki temu Box<> działa jako Box<int>
 *
 * struktura dziedziczy po Obj
 * ponieważ musi zaimplementować wszystkie
 * metody wirtualne
 *
 * Pole value ma wartość dowolnego typu T
 *
 * konstruktor explicit, wymusza jawną konwersję z T na Box<T>
 * `: value(value)` inicjalizacja pola value
 * w liście inicjalizacyjnej konstruktora
 * jest bardziej efektywna, ponieważ
 * unika domyślnej inicjalizacji + przypisania
 * odpowiednik
 * this->value = value;
 *
 * Implementacja metody Draw()
 * override jawnie wskazuje nadpisanie metody wirtualnej z Obj
 * Jeśli sygnatury się nie zgadzają kompilator zgłosi błąd
 *
 * typeid(T).name()
 * Zwraca nazwę typu T w formie tekstowej
 *
 * operator konwersji na T
 * Pozwala zwrócić value tego typu
 * */
template<typename T = int>
struct Box : Obj{
    T value;

    explicit Box(const T& value) : value(value) {}

    void Draw() const override{
        std::cout << "Box<" << typeid(T).name() << ">::Draw() --> " << value << std::endl;
    }

    operator T() const { return value; }
};

/* UZUPEŁNIJ 1 */

int main() {

    Box<>             b_i {13};            Obj& r_1 = b_i;        r_1.Draw();        int i = b_i;

    Box             b_d {14.15} ;        Obj& r_2 = b_d;        r_2.Draw();        double d = b_d;

    Box<Box<int>>    bb_i {b_i} ;  const Obj& r_3 = bb_i;    r_3.Draw();        Box<int> br_i = bb_i;

    Box<Box<double>>bb_d {b_d} ;  const Obj& r_4 = bb_d;    r_4.Draw();        Box<double> b_a = bb_d;

//    Box<int> _ = 1;     // BŁĄD KOMPILACJI

    return 0;
}

/*
Box<i>::Draw() --> 13
Box<d>::Draw() --> 14.15
Box<3BoxIiE>::Draw() --> 13
Box<3BoxIdE>::Draw() --> 14.15
*/