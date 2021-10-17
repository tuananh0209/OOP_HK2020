#include "libary.h"

Libary::Libary(){};

void Libary::addBookShelf(BookShelf * bookShelf){
    this->bookShelf.push_back(bookShelf);
}

void Libary::addLibrarian(Librarian *librarian){
    this->librarian.push_back(librarian);
}

void Libary::addMember(Member *member){
    this->member.push_back(member);
}