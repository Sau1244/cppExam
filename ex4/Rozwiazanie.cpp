#include <iostream>

// w całym kodzie można bezpośrednio wywoływać tylko dwie funkcje: printOn i operator <<
// wypisywanie może się odbywać tylko z wykorzystaniem __PRETTY_FUNCTION__ i "\n"
//  __PRETTY_FUNCTION__ zawiera pełną nazwę funkcji w danym miejscu


/** Klasa bazowa B - klasa z wirtualną metodą printOn oraz operatorem <<
 * `friend` sugeruje o ogólnodostępnej funkcji
 */
class B{
public:
    virtual ~B() = default;
    virtual std::ostream& printOn(std::ostream&) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const B& b){
        return b.printOn(os);
    }
};

/** Metoda printOn wzięta z klasy B, korzysta z ostream oraz __PRETTY_FUNCTION__ */
std::ostream& B::printOn(std::ostream &os) const {
    return os << __PRETTY_FUNCTION__ << "\n";
}

/** Klasa D1 dziedziczona po klasie B, z metodą nadpisującą metodę wirtualną */
class D1 : public B{
public:
    std::ostream& printOn(std::ostream& os) const override{
        os << __PRETTY_FUNCTION__ << "\n";
        return os;
    }
};

/** Klasa D2 dziedziczona po klasie D1 - pusta, ponieważ output wyświetla
 * iż brana jest funkcja z klasy D1
 */
class D2 : public D1{};

/** Klasa D3 dziedziczona po D1 - to samo co w D1, potrzebne dla klasy D1*/
class D3 : public D1{
public:
    std::ostream& printOn(std::ostream& os) const override{
        os << __PRETTY_FUNCTION__ << "\n";
        return os;
    }
};

/** Klasa D4 dziedziczona po D3, mająca dostęp do D3, D1 oraz B
 * korzystając z odpowiednich metod z klasy
 */
class D4 : public D3{
public:
    std::ostream& printOn(std::ostream& os) const override{
        B::printOn(os);
        D1::printOn(os);
        D3::printOn(os);
        os << __PRETTY_FUNCTION__ << "\n";
        return os;
    }
};
int main(int argc, char *argv[]) {
    // B b; odkomentowanie powoduje błąd kompilacji
    D1 d1; D2 d2; D3 d3; const D4 d4;
    std::cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4;
}

/* Output:
d1: virtual std::ostream& D1::printOn(std::ostream&) const
d2: virtual std::ostream& D1::printOn(std::ostream&) const
d3: virtual std::ostream& D3::printOn(std::ostream&) const
d4: virtual std::ostream& B::printOn(std::ostream&) const
virtual std::ostream& D1::printOn(std::ostream&) const
virtual std::ostream& D3::printOn(std::ostream&) const
virtual std::ostream& D4::printOn(std::ostream&) const
*/