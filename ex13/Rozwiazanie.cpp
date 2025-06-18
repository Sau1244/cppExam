#include<iostream>
#include<array>
#include<string>
#include <memory>

#include <algorithm>

void my_print_el(const std::string& line){
    std::cout << line;
}

void my_print(std::array<std::unique_ptr<int>,2>& a, const std::string& between, const std::string& next){
    std::cout << " [";
    for(std::unique_ptr<int>& el : a){
        std::cout << *el << between;
    }
    std::cout << "] " << next;
}

void my_print(std::array<std::unique_ptr<int>, 2>& a){
    std::cout << " [";
    for(std::unique_ptr<int>& el : a){
        std::cout << *el << ";";
    }
    std::cout << "]\n";
}

template<typename T>
void my_swap(T& a, T& b){
    std::swap(a,b);
}


int main()
{
    std::array<std::unique_ptr<int>,2> a = {
            std::unique_ptr<int>(new int {1}),
            std::unique_ptr<int>(new int {2})
    };

    my_print_el("----------------\n");
    my_print(a,";"," -> ");
    my_swap(a[0],a[1]);
    my_print(a,";"," -> ");
    my_swap(*a[0],*a[1]);
    my_print(a);
    my_print_el("----------------");
}
//[1;2;] -> [2;1;] -> [1;2;]