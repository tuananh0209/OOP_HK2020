#ifndef BOOK_H
#define BOOK_H

#include "header.h"


class Book
{
public:
    int id;
    string name;
    string subject;
    string publisher;
    string publiccationDate;

    Book();
    Book(int id, string name, string subject, string publisher, string publiccationDate);

    void printBook();
};

#endif