#ifndef LIBARY_H
#define LIBARY_H

#include "header.h"
#include "bookShelf.h"
#include "librarian.h"
#include "member.h"
#include "bookBorrow.h"

enum TypeID {
    M, B, L
};

class Libary {
    public:
    vector <BookShelf*> bookShelf;
    vector <Librarian*> librarian;
    vector <Member*> member;
    Member *memLogin;

    Libary();

    void addMember(Member *member);
    void addLibrarian(Librarian *librarian);
    void addBookShelf(BookShelf *bookShelf);
    int getID(TypeID typeId);
    bool login(string username);

    vector <Book*> findBook(string key);
    int borrowBook(Book *item);
    void addNotification(Book *item);
    void printBorrowingBook();
    void returnBook(int i);

};

#endif