#include "librarian.h"

Librarian::Librarian(){};
Librarian::Librarian(int id, string name, string phone, string address, string birthday)
:Person(name, phone, address, birthday)
{
    this->id = id;
}
