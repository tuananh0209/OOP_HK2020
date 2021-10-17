#include "bookBorrow.h"

BookBorrow::BookBorrow(){};
BookBorrow::BookBorrow(Book *book, BookItem *bookItem){
    this->book = book;
    this->bookItem = bookItem;
    this->isReturnLate = false;
    this->is_return = false;
    time(&dateBorrow);
}