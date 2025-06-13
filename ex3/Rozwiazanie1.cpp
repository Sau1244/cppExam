#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> c = {1,2,3,4,5,6,7};                                // WERSJA 1

    std::cout << "c: ";
    /** Funkcja lambda, która przyjmuje parametr val i wyświetla go po kolei */
    std::for_each(std::begin(c), std::end(c),
                  [](int val){std::cout << " " << val;});

    std::cout << "\nc wieksze od 3.5: ";
    /** Funkcja lambda, która przyjmuje parametr val
     * zawiera warunek, który sprawia, iż wyświetlą się
     * tylko te wartości, które są większe od 3.5
     */
    std::for_each(std::begin(c), std::end(c),
                  [](int val){
        if(val > 3.5) std::cout << " " << val;});

    std::cout << "\nc posortowane: ";
    /** Funkcja lambda, która przyjmuje dwa argumenty: a, b
     * która zwraca wartość logiczną, true gdy poprzednia jest większa od kolejnej
     * czyli tzw. komparator dla funkcji sortującej
     */
    std::sort(std::begin(c), std::end(c), [](int a, int b){ return a > b; });
    /** Funkcja lambda, która klasycznie wyświetla elementy
     * tym razem w kwadratowych ramkach
     */
    std::for_each(std::begin(c), std::end(c),
                  [](int val){std::cout << " [" << val << "]";});

    std::cout << "\nc dodane 'x': ";
    decltype(*std::begin(c)) x = *std::begin(c);

    /** Funkcja zmieniająca wartość funkcji o wartość funkcji x */
    std::for_each(std::begin(c), std::end(c), [x](int& val){ val += x; });
    /** Funkcja wyświetlająca wartości funkcji kolejno i przywracająca je do poprzedniej wartości */
    std::for_each(std::begin(c), std::end(c), [x](int& val){std::cout << " " << val; val -= x/2;});

    /** Funkcja korzystająca z parametru x, której wartość ma się zmieniać -
     * zmienia się i zwraca wartość nowej wartości */
    auto f = [&x](int val){x += val; return x;};
    std::cout << "\nx: " << x << " ";
    std::cout << "f: " << f(6) << " ";
    std::cout << "x: " << x << std::endl;
}
/*    WERSJA 1
c: 1 2 3 4 5 6 7 
c wieksze od 3.5: 4 5 6 7
c posortowane: [7] [6] [5] [4] [3] [2] [1] 
c dodane 'x': 14, 13, 12, 11, 10, 9, 8, 
x: 5 f: 13 x: 13
*/