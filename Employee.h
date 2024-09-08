#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>

class Employee {
public:
        Employee();
        Employee(const std::string &);
        Employee(const Employee &) = delete;
        Employee& operator=(const Employee &) = delete;

        const int id() const {return id_;}
private:
        std::string name_;
        int id_;
        static int s_increment;
};

int Employee::s_increment = 0;

Employee::Employee() {
        id_ = s_increment++;
}

Employee::Employee(const std::string & name) {
        id_ = s_increment++;
        name_ = name;
}



#endif
