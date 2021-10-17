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

// int Libary::getID(TypeID typeId){
//     if (typeId == M){
//         return this->member.size() + 1;
//     } else if (typeId == L){
//         return this->librarian.size() + 1;
//     }
//     return rand() 1;
// }

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
