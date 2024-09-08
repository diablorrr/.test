#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <iostream>

class HasPtr {

public:
    friend void swap(HasPtr &, HasPtr &);
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)){ }
    HasPtr(const HasPtr &hp) :ps(hp.ps), i(hp.i), use(hp.use) {
        ++*use;
    }
    HasPtr& operator=(const HasPtr &hp) {
        return *this;
    }
    std::string operator*() {
        return *ps;
    }
    bool operator<(const HasPtr &hp) const{
        return *ps < *hp.ps;
    }

    ~HasPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }
private:
    std::string *ps;
    int i;
    std::size_t *use;
};


inline void swap(HasPtr &hp1, HasPtr &hp2) {
    std::cout << "call swap" << std::endl;
    using std::swap;
    swap(hp1.ps, hp2.ps);
    swap(hp1.i, hp2.i);
    swap(hp1.use, hp2.use);
}
#endif
