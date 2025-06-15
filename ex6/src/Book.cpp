#include "Book.h"

Book::Book(const std::string &title, const std::string &author, int idBook)
    : title(title), author(author), idBook(idBook), status(true){}

void Book::changeStatus() { status = !status; }

std::string Book::getTitle() const { return title; }

int Book::getId() const { return idBook; }

std::ostream& operator<<(std::ostream& os, const Book& b){
    os << "ID: " << b.idBook << ", Title: " << b.title << ", Author: " << b.author << ", Status: ";
    b.status ? os << "Available" : os << "Borrowed";
    return os;
}