#include <iostream>

struct Obj; template<typename T> struct Box;

struct Obj{
    virtual ~Obj() = default;
    virtual void Draw() const = 0;
};

template<typename T = int>
struct Box : Obj{
    T val;

    void Draw() const override {
        std::cout << "Box<" << typeid(T).name() << ">::Draw() --> " << val << std::endl;
    }
    Box(){}
    explicit Box(T val) : val(val){}
    operator T() const { return val; }
};

template<typename T>
struct Box<Box<T>> : Obj{
    Box<T> val;

    void Draw() const override {
        std::cout << "Box<" << typeid(Box<T>).name() << ">::Draw() --> " << val << std::endl;
    }
    explicit Box(T val) : val(val){}
    operator Box<T>() const { return val; }
};

int main() {

    Box<> b_i {13}; Obj& r_1 = b_i; r_1.Draw(); int i = b_i;

    Box b_d {14.15}; Obj& r_2 = b_d; r_2.Draw(); double d = b_d;

    Box<Box<int>> bb_i {b_i}; const Obj& r_3 = bb_i; r_3.Draw(); Box<int> br_i = bb_i;

    Box<Box<double>>bb_d {b_d}; const Obj& r_4 = bb_d; r_4.Draw(); Box<double> b_a = bb_d;

    //Box<int> _ = 1;     // BŁĄD KOMPILACJI

    return 0;
}

/*
Box<i>::Draw() --> 13
Box<d>::Draw() --> 14.15
Box<3BoxIiE>::Draw() --> 13
Box<3BoxIdE>::Draw() --> 14.15
*/