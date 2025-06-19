#include <iostream>

// w całym kodzie można bezpośrednio wywoływać tylko dwie funkcje: printOn i operator <<
// wypisywanie może się odbywać tylko z wykorzystaniem __PRETTY_FUNCTION__ i "\n"
//  __PRETTY_FUNCTION__ zawiera pełną nazwę funkcji w danym miejscu

struct B{
    virtual ~B() = default;
    virtual std::ostream& printOn(std::ostream& os) const{
        return os << __PRETTY_FUNCTION__ << "\n";
    };
};

struct D1 : B{
    std::ostream& printOn(std::ostream& os) const override{
        return os << __PRETTY_FUNCTION__ << "\n";
    }
};

struct D2 : D1{};

struct D3 : D1{
    std::ostream& printOn(std::ostream& os) const override{
        return os << __PRETTY_FUNCTION__ << "\n";
    }
};

struct D4 : D3{
    std::ostream& printOn(std::ostream& os) const override{
        B::printOn(os);
        D1::printOn(os);
        D3::printOn(os);
        os << __PRETTY_FUNCTION__ << "\n";
        return os;
    }
};

std::ostream& operator<<(std::ostream& os, const B& b){
    b.printOn(os);
    return os;
}

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