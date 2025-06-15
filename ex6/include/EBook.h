#pragma once

#include "Book.h"

/**
 * @brief Klasa reprezentująca EBook dziedziczy po klasie Book
 */
class EBook : public Book{
public:
    /**
     * @brief Konstruktor klasy inicjuje Ebook
     * @param title Tytuł książki
     * @param author Autor książki
     * @param idBook Identyfikator książki
     * @param val Parametr wartości - nieużywany, dostosowany do pliku Main
     */
    EBook(const std::string& title, const std::string& author, int idBook, double val)
        : Book(title, author, idBook){}
};
