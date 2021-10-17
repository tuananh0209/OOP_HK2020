#ifndef MEMBER_H
#define MEMBER_H

#include "header.h"
#include "person.h"

class Member: public Person {
    public:
    int id;
    vector <BookItem*> history;
    vector <BookItem*> borrowing;

    Member();
    Member(int id,string username, string name, string phone, string address, string birthday);

};

#endif