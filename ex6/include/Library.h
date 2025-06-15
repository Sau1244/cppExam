#pragma once

#include "Book.h"
#include "EBook.h"
#include "Member.h"
#include <vector>

/**
 * @brief Klasa reprezentująca bibliotekę przechowującą książki i użytkowników
 */
class Library{
private:
    std::vector<Book> books; /** Lista książek dostępnych w bibliotece */
    std::vector<Member> members; /** Lista zarejestrowanych użytkowników */
public:
    /**
     * @brief Konstruktor domyślny
     */
    Library() = default;

    /**
     * @brief Dodaje książkę do biblioteki
     * @param b Nowa książka
     */
    void addBook(const Book& b);

    /**
     * @brief Dodaje użytkownika do biblioteki
     * @param m Nowy użytkownik
     */
    void addMember(const Member& m);

    /**
     * @brief Zwraca wskaźnik do książki na podstawie jej ID
     * @param id Identyfikator szukanej książki
     * @return Jeśli książka została znaleziona zwraca wskaźnik do niej, jeśli nie - null
     */
    Book* findBook(int id);

    /**
     * @brief Pożycza książkę danemu użytkownikowi
     * @param idBook Identyfikator książki
     * @param idMember Identyfikator użytkownika
     */
    void borrowBook(int idBook, int idMember);

    /**
     * @brief Zwraca książkę do biblioteki
     * @param idBook Identyfikator książki
     * @param idMember Identyfikator użytkownika
     */
    void returnBook(int idBook, int idMember);

    /**
     * @brief Wyświetla wszystkie książki w bibliotece oraz ich status
     */
    void displayBooks();

    /**
     * @brief Wyświetla wszystkich użytkowników
     */
    void displayMembers();

    /**
     * @brief Wyszukuje książki na podstawie podanego predykatu
     * @tparam T Typ predykatu (np. lambda)
     * @param f Predykat logiczny przyjmujący obiekt Book, zwracający bool
     * @return Wektor książek spełniający warunek
     */
    template<typename T>
    std::vector<Book> findBooksByPredicate(T f){
        std::vector<Book> predicate;
        for(const auto& book : books){
            if(f(book)) predicate.push_back(book);
        }
        return predicate;
    }
};