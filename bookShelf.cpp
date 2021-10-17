#include "bookShelf.h"

BookShelf::BookShelf(){};
BookShelf::BookShelf(int id, string title){
    this->id = id;
    this->title = title;
}

void BookShelf::addBook(BookItem * item){
    this->bookItem.push_back(item);
}