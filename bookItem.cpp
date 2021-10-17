#include "bookItem.h"

BookItem::BookItem(){};

BookItem::BookItem(int code, Book *book)
{
    this->code = code;
    this->book = book;
}
