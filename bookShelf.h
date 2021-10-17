#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "header.h"
#include "book.h"

class BookShelf {
    public:
    int id;
    string title;
    vector <Book*> book;
    
    BookShelf();
    BookShelf(int id, string title);

    void addBook(Book *item);
};

#endif