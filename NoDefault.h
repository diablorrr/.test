#ifndef NODEFAULT_H
#define NODEFAULT_H

class NoDefault {
    friend class C;
public:
    NoDefault(int i) : num(i) { };

private:
    int num;
};

class C {

public:
    C() : nd(0) { };

private:
  NoDefault nd;


};


#endif
