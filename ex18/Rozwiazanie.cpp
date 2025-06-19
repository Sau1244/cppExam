#include <iostream>

struct A{
    int i = 1;
};

template<typename T>
class ptr{
private:
    T* data;
public:
    ptr(){}
    explicit ptr(T* newData) : data(newData){};
//    explicit ptr(const ptr<T>& a) = default;

    T operator*() const { return *data; }
    T* operator->() const{ return data; }

    bool operator==(const ptr<T> & a) const{
        return false;
    }

    bool operator!=(const ptr<T> & a) const{
        return true;
    }

};

int main() {
    const ptr<A>  a(new A);
    const ptr<A> b;
    ptr<A> c(new A);

    //ptr<A>  _b_error = new A;      // Odkomentowanie powoduje błąd kompilacji 
    //a = a;               // Odkomentowanie powoduje błąd kompilacji 
//    const ptr<A> _c_error = a;     // Odkomentowanie powoduje błąd kompilacji

    std::cout << (((*a).i, a->i))        << " " << ++c->i << " ";
    std::cout << (a == ptr<A>() ) << " " << (a != b) << "\n";
}

//1 2 0 1