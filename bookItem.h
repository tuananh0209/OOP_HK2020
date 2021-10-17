#ifndef BOOKITEM_H
#define BOOKITEM_H

#include "header.h"
#include "book.h"


class BookItem
{
public:
    int code;
    bool borrowed;
    Book *book;
    string loanPeriod;
    string dueDay;
    bool isOverdue;

    BookItem();
    BookItem(int code, Book *book);
};

#endif