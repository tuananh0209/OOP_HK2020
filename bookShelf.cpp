#include "bookShelf.h"

BookShelf::BookShelf(){};
BookShelf::BookShelf(int id, string title){
    this->id = id;
    this->title = title;
}

void BookShelf::addBook(Book * item){
    this->book.push_back(item);
}