#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> c = {1,2,3,4,5,6,7};

    std::cout << "c: ";
    std::for_each(c.begin(), c.end(), [](const int& val){
        std::cout << val << " ";
    });

    std::cout << "\nc parzyste: ";
    std::for_each(c.begin(), c.end(), [](const int& val){
        if(!(val % 2))
            std::cout << val << " ";
    });

    std::cout << "\nc malejaco: ";
    std::sort(c.begin(), c.end(), [](int a, int b){
        return a > b;
    });
    std::for_each(c.begin(), c.end(), [](const int& val){
        std::cout << "[" << val << "] ";
    });

    std::cout << "\nc + x: ";
    int x=5;
    std::for_each(c.begin(), c.end(), [x](int& val){
        val += x;
    });
    std::for_each(c.begin(), c.end(), [x](int& val){
        std::cout << val << " ";
        val -= x;
    });

    auto f = [&x](int val){return x += val;};
    std::cout << "\nx: " << x << " ";
    std::cout << "f: " << f(6) << " ";
    std::cout << "x: " << x << std::endl;
}
/*
c: 1 2 3 4 5 6 7
c parzyste: 2 4 6
c malejaco: [7] [6] [5] [4] [3] [2] [1]
c + x: 12, 11, 10, 9, 8, 7, 6,
x: 5 f: 11 x: 11
*/