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