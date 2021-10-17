#ifndef MEMBER_H
#define MEMBER_H

#include "header.h"
#include "person.h"
#include "bookBorrow.h"

class Member: public Person {
    public:
    int id;
    vector <BookBorrow*> history;
    vector <BookBorrow*> borrowing;
    vector <Book *> waitNotification;

    int numBookBorrow;
    Member();
    ~Member();
    Member(int id,string username, string name, string phone, string address, string birthday);
    void printBookBorrowing();
    void returnBook(int i);
    void viewHistory();
};

#endif