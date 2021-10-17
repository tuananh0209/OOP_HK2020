#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "header.h"
#include "person.h"


class Librarian: public Person{
    public:
    int id;

    Librarian();
    Librarian(int id, string name, string phone, string address, string birthday);
};

#endif