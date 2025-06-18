#include <iostream>
#include <list>

template<typename T, typename T1>
void print_to_if(std::ostream& os, T begin, T end, T1 f){
    os;
    for(T it = begin; it != end; it++){
        if(f(*it)) std::cout << *it << " ";
    }
    std::cout << "\n";
}

template<typename T, typename T1>
void change(T begin, T end, T1 f){
    for(T it = begin; it != end; it++){
        f(*it);
    }
}

bool f1(int a){
    return true;
}

bool f2(int a){
    return !(a%2);
}

struct f3{
    int val;
    f3(int val) : val(val){}
    void operator()(int& x){x += val;}
};

int main(){
    const auto cl = {1,2,3,4,5,6,7};

    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f1);
    print_to_if(std::cout<<"All: ", begin(cl), end(cl), f2);

    int add_value{-1};
    std::list<int> cl2 = {7,6,5,4,3,2,1};
    change(begin(cl2), end(cl2), f3{add_value});
    print_to_if(std::cout << "All  ", begin(cl2), end(cl2), f1);
}
/*
All: 1 2 3 4 5 6 7 
All: 2 4 6 
All  6 5 4 3 2 1 0 
*/