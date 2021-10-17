#include "librarian.h"

Librarian::Librarian(){};
Librarian::Librarian(int id,string username, string name, string phone, string address, string birthday)
:Person(username, name, phone, address, birthday)
{
    this->id = id;
}
