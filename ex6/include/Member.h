#pragma once

#include <iostream>

/**
 * @brief Klasa reprezentująca użytkowników w bibliotece
 */
class Member{
private:
    std::string name; /** Imię użytkownika */
    int id; /** Identyfikator użytkownika */
public:
    /**
     * @brief Konstruktor klasy inicjuje użytkownika
     * @param name Imię użytkownika
     * @param id Identyfikator użytkownika
     */
    Member(const std::string& name, int id) : name(name), id(id){}

    /**
     * @brief Getter imienia użytkownika
     * @return Imię użytkownika jako string
     */
    std::string getName() const{ return name; }

    /**
     * @brief Przeciążenie operatora << do wypisywania informacji o użytkowniku
     * @param os Strumień wyjściowy
     * @param m Użytkownik
     * @return Referencja do strumienia wyjściowego
     */
    friend std::ostream& operator<<(std::ostream& os, const Member& m){
        os << "ID: " << m.id << ", Imie: " << m.name;
        return os;
    }
};