#ifndef BOOKITEM_H
#define BOOKITEM_H

#include "header.h"
#include "book.h"


class BookItem
{
public:
    int code;
    bool borrowed;
    string loanPeriod;
    string dueDay;
    bool isOverdue;

    BookItem();
    BookItem(int code);
};

#endif