#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

/** Funkcja zwracająca funkcje z parametrem domyślnym funkcji zmniejszającej element o 2*/
std::function<std::vector<int>(std::vector<int>)> liftToVector(std::function<int(int)> f = [](int val){return val - 2;}){
    /** Funkcja lambda, zwracająca wektor elementów ze wziętego wektora, która używa funkcji f parametru */
    return [&](std::vector<int> v){
        std::vector<int> v2;
        for(int& el : v){
            v2.push_back(f(el));
        }
        return v2;
    };
}


int main() {

    auto vadd2 = liftToVector();
    std::vector<int> x = {0, 9, 4};
    auto v = vadd2(x);

    std::for_each(v.begin(), v.end(), [](const int n) { std::cout << n << ' '; });

    return 0;
}

/*
 -2 7 2
*/