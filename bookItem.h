#ifndef BOOKITEM_H
#define BOOKITEM_H

#include "header.h"
#include "book.h"


class BookItem
{
public:
    int code;
    bool borrowed;

    BookItem();
    BookItem(int code);
    
    void printBookItem();
};

#endif