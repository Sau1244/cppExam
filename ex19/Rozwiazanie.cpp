#include <iostream>

struct Obj{
    virtual ~Obj() = default;
    virtual void Draw() const = 0;
};

template<typename T>
struct Box : Obj{
    T val;

    Box() = default;
    explicit Box(T _val) : val(_val){}

    void Draw() const override{
        std::cout << __PRETTY_FUNCTION__ << " [with T = " << (std::is_same_v<T, int> ? "int" : "double") << "] --> " << val << std::endl;
    }

    operator T() const{ return val; }
};

template<typename T>
struct Box<Box<T>> : Obj{
    Box<T> val;

    explicit Box(T _val) : val(_val){}

    void Draw() const override{
        std::cout << __PRETTY_FUNCTION__ << " [with T = " << (std::is_same_v<T, int> ? "int" : "double") << "] --> " << val << std::endl;
    }

    operator Box<T>() const{ return val; }
};

int main()
{
    Box<int> b_i {3};
    Obj& r_1 = b_i;
    r_1.Draw();
    int i = b_i;
    Box<double> b_d {3.4} ;
    Obj& r_2 = b_d;
    r_2.Draw();
    double d = b_d;
    Box<Box<int>> bb_i {3} ;
    const Obj& r_3 = bb_i;
    r_3.Draw();
    Box<int> br_i = bb_i;
    Box<Box<double>> bb_d {3.4} ;
    const Obj& r_4 = bb_d;
    r_4.Draw();
    Box<double> b_a = bb_d;

// Box<int> _ = 3; Odkomentowanie powoduje b��d kompilacji

}
/*
void Box<T>::Draw() const [with T = int] --> 3
void Box<T>::Draw() const [with T = double] --> 3.4
void Box<Box<K> >::Draw() const [with T = int] --> 3
void Box<Box<K> >::Draw() const [with T = double] --> 3.4
*/