#pragma once

/**
 * @brief Serwis nazw zawierający funkcje pomocnicze
 */
namespace Util{
    /**
     * @brief Zwraca większą z dwóch wartości
     * @tparam T Typ porównywanych wartości
     * @param a Pierwsza wartość
     * @param b Druga wartość
     * @return Większa z dwóch wartości jako ich typ
     */
    template<typename T>
    T findMax(const T& a,const T& b) {
        return a >=b ? a : b;
    }

    /**
     * @brief Zwraca większą z dwóch wartości na podstawie predykatu
     * @tparam T Typ porównywanych wartości
     * @tparam T2 Typ predykatu
     * @param a Pierwsza wartość
     * @param b Druga wartość
     * @param f Funkcja porównująca zwraca bool
     * @return Większa z dwóch wartości według predykatu jako ich typ
     */
    template<typename T, typename T2>
    T findMax(const T& a, const T& b, T2 f){
        return f(a,b) ? b : a;
    }

}

/**
 * @brief Umożliwia korzystanie z funkcji `Util` bez podawania przestrzeni
 */
using namespace Util;