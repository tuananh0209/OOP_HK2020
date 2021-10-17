#ifndef BOOK_H
#define BOOK_H

#include "header.h"
#include "bookItem.h"

class Book
{
public:
    int id;
    string name;
    string subject;
    string publisher;
    string publiccationDate;
    vector <BookItem *> bookItem;
    int book_available;

    Book();
    Book(int id, string name, string subject, string publisher, string publiccationDate);

    void printBook();
    void addBookItem(BookItem * item);
};

#endif