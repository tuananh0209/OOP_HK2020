#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "header.h"
#include "bookItem.h"

class BookShelf {
    public:
    int id;
    string title;
    vector <BookItem*> bookItem;
    
    BookShelf();
    BookShelf(int id, string title);

    void addBook(BookItem *item);
};

#endif