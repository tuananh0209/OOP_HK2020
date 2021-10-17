#include "person.h"

Person::Person(){};
Person::Person(string name, string phone, string address, string birthday){
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->birthday = birthday;

}
