#include "libary.h"

Libary::Libary(){};

void Libary::addBookShelf(BookShelf * bookShelf){
    this->bookShelf.push_back(bookShelf);
}

void Libary::addLibrarian(Librarian *librarian){
    this->librarian.push_back(librarian);
}

void Libary::addMember(Member *member){
    this->member.push_back(member);
}


bool Libary::login(string username){
    int len = this->member.size();
    for (int i = 0; i < len; i++){
        if (this->member[i]->username == username){
            this->memLogin = this->member[i];
            return true;
        }
    }
    return false;
}

vector<Book *> Libary::findBook(string key)
{
    int j = 1, len = this->bookShelf.size();
    transform(key.begin(), key.end(), key.begin(), ::tolower);

    vector<Book *> result;
    for (int i = 0; i < len; i++)
    {
        vector<Book *> t = bookShelf[i]->search(key);
        if (t.size() > 0){
            result.insert(result.end(), t.begin(), t.end());
        }
    }
    len = result.size();
    for (int i = 0; i < len; i++)
    {
        cout << i <<". ";
        result[i]->printBook();
    }
    return result;
}

int Libary::borrowBook(Book *item){
    if (item->book_available <= 0){
        cout <<"Book not available, do you want add receive notification when it available?[1/yes, 0/no].\n";
        return 1;
    }
    if (memLogin->numBookBorrow >= 4){
        cout << "You reach the maximum possible limit.\n";
        return 2;
    }
    BookItem* availableBookItem = item->findAvailable();
    BookBorrow *t = new BookBorrow(item, availableBookItem);
    memLogin->borrowing.push_back(t);
    memLogin->numBookBorrow += 1;
    item->book_available -= 1;
    cout << "Borrow "<< item->name<<" success\n";
    return 0;
}

void Libary::addNotification(Book *item){
    this->memLogin->waitNotification.push_back(item);
    cout << "Add "<< item->name <<" to notification success\n";
}

void Libary::printBorrowingBook(){
    this->memLogin->printBookBorrowing();
}

void Libary::returnBook(int i){
    this->memLogin->returnBook(i);
}

void Libary::history(){
    this->memLogin->viewHistory();
}

void Libary::logout(){
    this->memLogin = nullptr;
    this->libraLogin = nullptr;
}

bool Libary::librarianLogin(string username){
    int len = this->librarian.size();
    for (int i = 0; i < len; i++)
    {
        if (this->librarian[i]->username == username)
        {
            this->libraLogin = this->librarian[i];
            return true;
        }
    }
    return false;
}

vector<Book *> Libary::listBook()
{
    int len = this->bookShelf.size();
    vector<Book *> result;
    for (int i = 0; i < len; i++)
    {
        vector<Book *> t = this->bookShelf[i]->getBook();
        if (t.size() > 0)
        {
            result.insert(result.end(), t.begin(), t.end());
        }
    }
    len = result.size();
    for (int i = 0; i < len; i++)
    {
        cout << i << ". ";
        result[i]->printBook();
    }
    return result;
}

void Libary::bookDetail(Book *item){
    item -> printBook();
    int len = item->bookItem.size();
    for (int i= 0; i < len; i++){
        item->bookItem[i]->printBookItem();
        string memberName =  this->Libary::getMemberNameBorrowing(item->bookItem[i]->code, item->id);
        cout << "Member borrowing: " << memberName << endl;
    }
}

string Libary::getMemberNameBorrowing(int code, int id)
{ 
    string result = "";
    int len = this->member.size();
    bool found = false;
    for (int i = 0; i < len; i++){
        if (found == true) break;
        int len2 =  this->member[i]->borrowing.size();
        for (int j = 0; j < len2; j++){
            BookBorrow *t = this->member[i]->borrowing[j];
            if(t->book->id == id && t->bookItem->code == code){
                result += this->member[i]->name;
                found = true;
                break;
            }
        }
    }
    return result;
}

void Libary::checkNotification(){
    vector<Book *> waitNoti = this->memLogin->waitNotification;
    int len = waitNoti.size();
    for(int i = 0; i < len; i++){
        if (waitNoti[i]->book_available > 0)
        {
            cout <<"Book " << waitNoti[i]->name << " is available!\n";
            vector<Book *>::iterator rm = this->memLogin->waitNotification.begin() + i - 1;
            this->memLogin->waitNotification.erase(rm);
        } 
    }
}