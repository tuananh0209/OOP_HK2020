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
    len = this->history.size();
    for (int i = 0; i < len; i++)
    {
        cout << i << ". ";
        delete history[i];
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
    if (i < 0 || i >= this->borrowing.size()) return;
    BookBorrow *item = this->borrowing[i];
    time_t cur;
    struct tm *tmp;
    time(&cur);
    int difTime = int(difftime(cur, item->dateBorrow));
    int day = difTime/(60*60*24);
    item ->dateReturn = cur;
    if (day > 10){
        item->penalty = int(day - 10)*10000;
        item ->isReturnLate = true;
    }
    item->isReturnLate = false;
    item->is_return = true;
    item->book->book_available +=1;
    item->bookItem->borrowed = false;
    this->numBookBorrow -= 1;
    item->printBookBorrow();
    this->history.push_back(item);
    vector<BookBorrow *>::iterator rm = borrowing.begin() + i - 1;
    borrowing.erase(rm);
}

void Member::viewHistory(){
    int len = this->history.size();
    for (int i = 0; i < len; i++){
        cout << "=================\n";
        this->history[i]->printBookBorrow();
    }
}
