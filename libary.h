#ifndef LIBARY_H
#define LIBARY_H

#include "header.h"
#include "bookShelf.h"
#include "librarian.h"
#include "member.h"
#include "bookBorrow.h"


class Libary {
    public:
    vector <BookShelf*> bookShelf;
    vector <Librarian*> librarian;
    vector <Member*> member;
    Member *memLogin;
    Librarian *libraLogin;
    Libary();

    void addMember(Member *member);
    void addLibrarian(Librarian *librarian);
    void addBookShelf(BookShelf *bookShelf);
    bool login(string username);

    vector <Book*> findBook(string key);
    int borrowBook(Book *item);
    void addNotification(Book *item);
    void printBorrowingBook();
    void returnBook(int i);
    void history();
    void logout();

    bool librarianLogin(string username);
    vector<Book *> listBook();
    void bookDetail(Book * item);
    string getMemberNameBorrowing(int code, int id);
    void checkNotification();
};

#endif