#ifndef LIBARY_H
#define LIBARY_H

#include "header.h"
#include "bookShelf.h"
#include "librarian.h"
#include "member.h"


class Libary {
    public:
    vector <BookShelf*> bookShelf;
    vector <Librarian*> librarian;
    vector <Member*> member;
    Libary();

    void addMember(Member *member);
    void addLibrarian(Librarian *librarian);
    void addBookShelf(BookShelf *bookShelf);    
};

#endif