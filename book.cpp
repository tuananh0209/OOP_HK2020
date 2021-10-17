#include "book.h"

Book::Book(){};

Book::Book(int id, string name, string subject, string author,
           string publisher, string publiccationDate)
{
    this->id = id;
    this->author = author;
    this->name = name;
    this->subject = subject;
    this->publisher = publisher;
    this->publiccationDate = publiccationDate;
    this->book_available = 0;
}

void Book::printBook()
{
    cout << "Name: " << this->name << " publisher: " << this->publisher << endl;
}

void Book::addBookItem(BookItem* item){
    this->bookItem.push_back(item);
    this->book_available += 1;
}