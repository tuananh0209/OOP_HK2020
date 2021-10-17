#include "member.h"

Member::Member(){};
Member::Member(int id, string name, string phone, string address, string birthday):Person(name, phone, address, birthday){
    this->id = id;
}