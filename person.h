#ifndef PERSON_H
#define PERSON_H

#include "header.h"

class Person
{
public:
    string name;
    string phone;
    string address;
    string birthday;
    string username;
    Person();
    Person(string username, string name, string phone, string address, string birthday);
};

#endif