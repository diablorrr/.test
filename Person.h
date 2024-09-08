#ifndef PERSON_H
#define PERSON_H
#include <string>

using std::istream;
using std::ostream;
using std::string;

struct Person {

friend istream &read(istream &, Person &);
friend ostream &print(ostream &, const Person &);

public:

    Person() = default;
    Person(const string &s, const string &a) : name(s), address(a) { };
    explicit Person(istream &);

    auto get_name() const -> const std::string& {return name;}
    auto get_address() const -> const std::string& {return address;}

private:

    string name;
    string address;
};

istream &read(istream &, Person &);
ostream &print(ostream &, const Person &);


#endif
