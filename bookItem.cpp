#include "bookItem.h"

BookItem::BookItem(){};

BookItem::BookItem(int code)
{
    this->code = code;
    this->borrowed = false;
}

void BookItem::printBookItem(){
    string available = this->borrowed ? "False" : "True";
    cout <<"=======================\n";
    cout << "Code: " << this->code << endl;
    cout << "Is avalable: "<< available << endl;
}
