#include "Library.h"

void Library::addBook(const Book &b) { books.push_back(b); }

void Library::addMember(const Member &m) { members.push_back(m); }

Book* Library::findBook(int id) {
    for(auto& book : books){
        if(book.getId() == id)
            return &book;
    }
    return nullptr;
}

void Library::borrowBook(int idBook, int idMember) {
    Book* b = findBook(idBook);
    if(b) {
        b->changeStatus();
        std::cout << "Ksiazka " << b->getTitle() << " wypozyczona przez uzytkownika o ID " << idMember << std::endl;
    }else
        std::cout << "Brak ksiazki w systemie o numerze id " << idBook << std::endl;
}

void Library::returnBook(int idBook, int idMember) {
    Book* b = findBook(idBook);
    if(b) {
        b->changeStatus();
        std::cout << "Ksiazka " << b->getTitle() << " zwrocona przez uzytkownika o ID " << idMember << std::endl;
    }else
        std::cout << "Brak ksiazki w systemie o numerze id " << idBook << std::endl;
}

void Library::displayBooks() {
    std::cout << "Ksiazki w bibliotece:\n";
    for(auto& book : books)
        std::cout << book << std::endl;
}

void Library::displayMembers() {
    std::cout << "Czlonkowie biblioteki:\n";
    for(auto& member : members)
        std::cout << member << std::endl;
}

