#include <iostream>
#include <string>

class is_printable{
public:
    virtual ~is_printable() = default;
    virtual void print(std::ostream& os) const = 0;
};

class A : public is_printable{
private:
    std::string tekst;
public:
    A() = default;
    explicit A(const std::string& tekst) : tekst(tekst){};

    void print(std::ostream& os) const override{
        os << tekst;
    }
};

class B : public is_printable{
private:
    int num;
public:
    B() = default;

    explicit B(int num) : num(num) {};

    void print(std::ostream& os) const override{
        os << num;
    }
};

std::ostream& operator<<(std::ostream& os, const is_printable& ip){
    ip.print(os);
    return os;
}



int main()
{
    A a ("Tekst"); B b {123};
    std::cout<< "a:\t"<<a<<"; b:\t"<<b<<"\n";
    const is_printable & a_r = a; const is_printable & b_r = b;
    std::cout<< "a_r:\t"<<a_r<<"; b_r:\t"<<b_r<<"\n";
}

/*
a:      Tekst; b:       123
a_r:    Tekst; b_r:     123
*/