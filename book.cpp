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

BookItem * Book::findAvailable(){
    int len = this->bookItem.size();
    for (int i = 0; i < len; i++)
    {
        if (bookItem[i]->borrowed == false){
            bookItem[i]->borrowed = true;
            return bookItem[i];
        }
    }
    return nullptr;
}
