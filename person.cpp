#include "person.h"

Person::Person(){};
Person::Person(string username, string name, string phone, string address, string birthday){
    this->name = name;
    this->username = username;
    this->address = address;
    this->phone = phone;
    this->birthday = birthday;

}
