#include <iostream>

/** Korzystanie z szablonu std */
using namespace std;

/** Klasa A wykorzystania w głównym pliku Main */
class A{
private:
    int _a, _b; /** Wykorzystywane parametry */
public:
    /** Konstruktor przyjmujący wartości a i b */
    A(int a, int b) : _a(a), _b(b){
        cout << __PRETTY_FUNCTION__ << ": _a = " << _a << ", _b = " << _b << endl;
    }

    /** Konstruktor domyślny korzystający z inicjalizującego */
    A() : A(0,0){
        cout << __PRETTY_FUNCTION__ << ": _a = " << _a << ", _b = " << _b << endl;
    }

    /** Konstruktor jawny korzystający z inicjalizującego */
    explicit A(int a) : A(a,0){
        cout << __PRETTY_FUNCTION__ << ": _a = " << _a << ", _b = " << _b << endl;
    }

    /** Rule Of Five **/
    ~A() = default; /** Destruktor */

    /** Konstruktor kopiujący i operatory kopiujące i przenoszące, nie pozwalające na wykonanie czynności */
    A(const A& other) = delete;
    A& operator=(const A& other) = delete;
    A& operator=(A&& other) = delete;

    /** Konstruktor przenoszący - umożliwiający przeniesienie danych */
    A(A&& other){
        _a = other._a;
        other._a = 0;

        _b = other._b;
        other._b = 0;

        cout << __PRETTY_FUNCTION__ << ": _a = " << _a << ", _b = " << _b << endl;
    }

};

int main()
{
    cout << "a->"; A a;
    cout << "b->"; A b(1);
    cout << "c->"; A c(1,2);

    cout << "d->"; A d = std::move(c);

    //A e = c;
    //A f = 1;
}
/*
a-> A::A(int,int): _a=0,_b=0
A::A(): _a=0,_b=0
b-> A::A(int,int): _a=1,_b=0
A::A(int): _a=1,_b=0
c-> A::A(int,int): _a=1,_b=2
d-> A::[...]: _a=1,_b=2
*/