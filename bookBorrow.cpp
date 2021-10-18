#include "bookBorrow.h"

BookBorrow::BookBorrow(){};
BookBorrow::BookBorrow(Book *book, BookItem *bookItem){
    this->book = book;
    this->bookItem = bookItem;
    this->isReturnLate = false;
    this->is_return = false;
    time(&dateBorrow);
    this->penalty= 0;
}

void BookBorrow::printBookBorrow(){
    tm *ltm = localtime(&this->dateBorrow);
    cout <<"sss" << this->isReturnLate;
    string late = this->isReturnLate ? "true" : "false";
    cout << "Name: "<< this->book->name << endl;
    cout << "Date borrow: " << ltm->tm_mday <<"-"<< 1 + ltm->tm_mon << "-" << 1900 + ltm->tm_year << endl;
    cout << "Is return late: " << late << endl;
    cout << "Penalty: " << this->penalty <<" vnd" << endl;
}