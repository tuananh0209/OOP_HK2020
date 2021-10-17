#include "book.h"

Book::Book(){};

Book::Book(int id, string name, string subject,
           string publisher, string publiccationDate)
{
    this->id = id;
    this->name = name;
    this->subject = subject;
    this->publisher = publisher;
    this->publiccationDate = publiccationDate;
}

void Book::printBook()
{
    cout << "Name: " << this->name << " publisher: " << this->publisher << endl;
}