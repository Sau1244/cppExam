#pragma once

#include <iostream>

/**
 * @brief Klasa reprezentująca książkę w bibliotece
 */
class Book{
private:
    std::string title; /** Tytuł książki */
    std::string author; /** Autor książki */
    int idBook; /** Identyfikator książki */
    bool status; /** Status książki: true = available, false = borrowed */
public:
    /**
     * @brief Konstruktor klasy inicjuje książkę
     * @param title Tytuł książki
     * @param author Autor książki
     * @param idBook Identyfikator książki
     */
    Book(const std::string& title, const std::string& author, int idBook);


    /**
     * @brief Zmienia status książki Available <-> Borrowed
     */
    void changeStatus();

    /**
     * @brief Getter tytułu książki
     * @return Tytuł książki jako string
     */
    std::string getTitle() const;
    /**
     * @brief Getter identyfikatora książki
     * @return Identyfikator jako int
     */
    int getId() const;

    /**
     * @brief Przeciążenie operatora << do wypisywania informacji o książce
     * @param os Strumień wyjściowy
     * @param b Książka
     * @return Referencja do strumienia wyjściowego
     */
    friend std::ostream& operator<<(std::ostream& os, const Book& b);
};