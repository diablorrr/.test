#include <iostream>
#include "Person.h"

using std::endl;

istream &read(istream &is, Person &person) {
    return is >> person.name >> person.address;
}


ostream &print(ostream &os, const Person &person) {
    return os << person.get_name() << " " << person.get_address() << endl;
}

Person::Person(istream &is) {
    read(is, *this);
}
