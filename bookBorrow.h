#ifndef BOOKBORROW_H
#define BOOKBORROW_H

#include "header.h"
#include "book.h"

class BookBorrow
{
    public:
        Book * book;
        BookItem* bookItem;
        bool is_return;
        time_t dateBorrow;
        time_t dateReturn;
        bool isReturnLate;
        int dateLate;

        BookBorrow();
        BookBorrow(Book *book, BookItem * bookItem);
};

#endif