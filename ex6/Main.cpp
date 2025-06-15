/*

Proszę dodać kod, dodać nowe pliki, aby program działał
i jego wynik był taki sam jak podany na końcu tego pliku.

Wymagania:
    - Zdefiniuj klasy `Book` i `EBook`. Klasa `EBook` powinna dziedziczyć po klasie `Book`.
    - Zaimplementuj przeciążenie operatora `<<`, aby wyświetlić szczegóły książki.
    - Zdefiniuj metodę `borrowBook()`, która pozwala członkom wypożyczać książkę.
    - Zdefiniuj metodę `returnBook()`, która pozwala członkom zwracać książkę.
    - Zaimplementuj wyrażenia lambda w pliku `Main.cpp` w celu:
        - Znalezienia książek z tytułami zaczynającymi się od określonej litery.
        - Sortowania książek według tytułu.
    - Użyj szablonów do zdefiniowania funkcji użytkowej `findMax`, która zwraca maksymalną z dwóch wartości, oraz innej funkcji szablonowej do porównywania atrybutów książek lub członków.
    - Zaimplementuj metodę `findBooksByPredicate`, aby wyszukiwać książki na podstawie przekazanego predykatu.
    - Zaimplementuj odpowiednie zarządzanie pamięcią.
    - Plik `Main.cpp` nie może być modyfikowany, chyba że jest to wyraźnie zaznaczone w treści zadania (oznaczenie).
    - Wynikowy program powinien składać się z czytelnego kodu. Powinna być spełniona zasada D.R.Y. (Don't Repeat Yourself).
*/

#include <iostream>
#include <vector>
#include "Book.h"
#include "EBook.h"
#include "Member.h"
#include "Library.h"
#include "Utils.h"

int main() {
    Library library;

    Book book1("1984", "George Orwell", 1);
    Book book2("To Kill a Mockingbird", "Harper Lee", 2);
    EBook ebook1("Digital Fortress", "Dan Brown", 3, 5.0);

    Member member1("Alice", 101);
    Member member2("Bob", 102);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(ebook1);

    library.addMember(member1);
    library.addMember(member2);

    library.borrowBook(1, 101);
    library.borrowBook(2, 102);
    library.borrowBook(3, 101);

    library.returnBook(1, 101);

    std::cout << "Wyświetlanie wszystkich książek:" << std::endl;
    library.displayBooks();

    std::cout << "Wyświetlanie wszystkich członków:" << std::endl;
    library.displayMembers();

    std::cout << "Znajdowanie książek z tytułami zaczynającymi się na 'D':" << std::endl;
    auto booksWithD = library.findBooksByPredicate([](const Book &book) {
        return book.getTitle().front() == 'D';
    });
    for (const auto &book : booksWithD) {
        std::cout << book << std::endl;
    }

    std::cout << "Demonstracja funkcji szablonowej:" << std::endl;
    std::cout << "Maksymalna wartość z 3 i 5: " << findMax(3, 5) << std::endl;
    std::cout << "Maksymalna wartość z 3.5 i 2.1: " << findMax(3.5, 2.1) << std::endl;

    std::cout << "Porównanie ID książek: " << std::endl;
    std::cout << findMax(book1, book2, [](const Book &a, const Book &b) { return a.getId() < b.getId(); }) << std::endl;

    std::cout << "Porównanie imion członków: " << std::endl;
    std::cout << findMax(member1, member2, [](const Member &a, const Member &b) { return a.getName() < b.getName(); }) << std::endl;


    return 0;
}

/*
Książka 1984 wypożyczona przez użytkownika o ID 101
Książka To Kill a Mockingbird wypożyczona przez użytkownika o ID 102
Książka Digital Fortress wypożyczona przez użytkownika o ID 101

Książka 1984 zwrocona przez użytkownika o ID 101

Wyświetlanie wszystkich książek:
Książki w bibliotece:
ID: 1, Title: 1984, Author: George Orwell, Status: Available
ID: 2, Title: To Kill a Mockingbird, Author: Harper Lee, Status: Borrowed
ID: 3, Title: Digital Fortress, Author: Dan Brown, Status: Borrowed

Wyświetlanie wszystkich członków:
Członkowie bibliopteki:
ID: 101, Imie: Alice
ID: 102, Imie: Bob

Znajdowanie książek z tytułami zaczynającymi się na 'D':
ID: 3, Title: Digital Fortress, Author: Dan Brown, Status: Borrowed

Demonstracja funkcji szablonowej:
Maksymalna wartość z 3 i 5: 5
Maksymalna wartość z 3.5 i 2.1: 3.5

Porównanie ID książek:
ID: 2, Title: To Kill a Mockingbird, Author: Harper Lee, Status: Available

Porównanie imion członków:
ID: 102, Imie: Bob
*/