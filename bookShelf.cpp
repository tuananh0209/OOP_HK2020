#include "bookShelf.h"

BookShelf::BookShelf(){};
BookShelf::BookShelf(int id, string title){
    this->id = id;
    this->title = title;
}

void BookShelf::addBook(Book * item){
    this->book.push_back(item);
}

vector<Book *> BookShelf::search(string key)
{
    int len = this->book.size();
    transform(key.begin(), key.end(), key.begin(), ::tolower);

    vector<Book *> result;
    for (int i = 0; i < len; i++)
    {
        string bookName = this->book[i]->name;
        transform(bookName.begin(), bookName.end(), bookName.begin(), ::tolower);
        
        string bookAuthor = this->book[i]->author;
        transform(bookAuthor.begin(), bookAuthor.end(), bookAuthor.begin(), ::tolower);
        
        string bookSubject = this->book[i]->subject;
        transform(bookSubject.begin(), bookSubject.end(), bookSubject.begin(), ::tolower);
        
        string bookPublicDate = this->book[i]->publiccationDate;
        transform(bookPublicDate.begin(), bookPublicDate.end(), bookPublicDate.begin(), ::tolower);

        if (bookName.find(key) != string::npos)
        {
            result.push_back(book[i]);

        }
        else if (bookSubject.find(key) != string::npos)
        {
            result.push_back(book[i]);
           
        }
        else if (bookAuthor.find(key) != string::npos)
        {
            result.push_back(book[i]);
            
        }
        else if (bookPublicDate.find(key) != string::npos)
        {
            result.push_back(book[i]);
           
        }
        
    }
    return result;
}

vector<Book *> BookShelf::getBook(){
    vector<Book *> result;
    int len = this->book.size();
    for (int i = 0; i < len; i++){
        result.push_back(this->book[i]);
    }
    return result;
}
