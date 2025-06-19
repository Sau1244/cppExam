#include<iostream>
#include<vector>

/**
 * Struktura wirtualna pełniąca rolę bazy
 */
struct Base{
    virtual ~Base() = default; // Destruktor wirtualny potrzebny aby metody działały poprawnie
    virtual std::ostream& print(std::ostream&) const = 0; // Metoda wirtualna zwracająca ostream - tworzy abstrakcyjną siatkę
};

/**
 * Struktura Derived dziedzicząca po Base - aby mieć dostęp do metody print
 */
struct Derived1 : Base{
    std::ostream& print(std::ostream& os) const override{
        return os << __PRETTY_FUNCTION__ << "\n";
    }
};

/**
 * struktura Derived2 dziedzicząca po Base aby miec dostep do metody print
 */
struct Derived2 : public Base{
    std::ostream& print(std::ostream& os) const override{
        return os << __PRETTY_FUNCTION__ << "\n";
    }
};

/**
 * Struktura Derived3 dziedzicząca po Derived2 aby móc ją bez problemu przypisać tak jak w main i miec dostep do print
 */
struct Derived3 : public Derived2{
    std::ostream& print(std::ostream& os) const override{
        return os << __PRETTY_FUNCTION__ << "\n";
    }
};

// Przeciążenie operatora << i przyjmująca parametr wektora Base*
std::ostream& operator<<(std::ostream& os, std::vector<Base*>& b){
    os << "[\n";
    for(Base* el : b){ // Wewnątrz są elementy Base*
        el->print(os); //-> ponieważ element jest wskaźnikiem - nie musi czemuś to przypisywać
    }
    os <<"]";
    return os;
}
// Przeciążenie funkcji i operatora << przyjmuje referencje to elementów z bazy
std::ostream& operator<<(std::ostream& os, const Base& b){
    return b.print(os);
}

int main(){
    Derived1 d1;
    Derived3 d3;
    Derived2 d2 = d3;
    // Derived1 d1_make_err = d2;

    // std::vector<Base> v_make_err = {d1, d2, d3};
    std::vector<Base*> v = {&d1, &d2, &d3};

    std::cout << *v.front()<<std::endl;
    std::cout << v;
}

/*Wynik:
virtual std::ostream& Derived1::print(std::ostream&) const
[
virtual std::ostream& Derived1::print(std::ostream&) const,
virtual std::ostream& Derived2::print(std::ostream&) const,
virtual std::ostream& Derived3::print(std::ostream&) const
]
*/