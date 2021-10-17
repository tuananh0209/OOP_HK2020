#include "member.h"

Member::Member(){};
Member::Member(int id,string username, string name, string phone, string address, string birthday)
:Person(username, name, phone, address, birthday){
    this->id = id;
    this->numBookBorrow = 0;
}

Member::~Member(){
    int len = this->borrowing.size();
    for (int i = 0; i < len; i++)
    {
        cout << i << ". ";
        delete borrowing[i];
    }
}

void Member::printBookBorrowing(){
    int len = this->borrowing.size();
    for (int i = 0; i < len; i++)
    {
        cout << i <<". ";
        borrowing[i]->book->printBook();
    }
}

void Member::returnBook(int i){
    BookBorrow *item = this->borrowing[i];
    time_t cur;
    struct tm *tmp;
    time(&cur);
    int difTime = int(difftime(cur, item->dateBorrow));
    int day = difTime/(60*60*24);
    item ->dateReturn = cur;
    if (day > 10){
        
    }
}
