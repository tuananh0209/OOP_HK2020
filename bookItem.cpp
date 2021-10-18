#include "bookItem.h"

BookItem::BookItem(){};

BookItem::BookItem(int code)
{
    this->code = code;
}

void BookItem::printBookItem(){
    string available = this->borrowed ? "False" : "True";
    cout << "Code: " << this->code << endl;
    cout << "Is avalable: "<< available << endl;
}
