#ifndef SALES_DATA_H
#define SALES_DATA_H
#include "Person.h"
#include <complex>
#include <ostream>
#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;
using std::cout;
using std::endl;

struct Sales_data {

friend istream &read(istream &, Sales_data &);
friend ostream &print(ostream &, Sales_data &);
friend Sales_data add(const Sales_data &, const Sales_data &);
friend bool operator==(const Sales_data &, const Sales_data &);
friend ostream& operator<<(ostream&, const Sales_data&);
friend istream& operator>>(istream&, Sales_data &);
friend Sales_data operator+(const Sales_data &, const Sales_data&);

public:

    Sales_data(string s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n*p) { cout << "snp" << endl;};
    Sales_data() : Sales_data("", 0, 0.0) { cout << "()" << endl;};
    Sales_data(string s) : Sales_data(s, 0, 0.0) { cout << "s" << endl;};
    Sales_data(istream &is) : Sales_data(){
        cout << "is" << endl;
        read(is, *this);
    };

    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);

    Sales_data& operator+=(const Sales_data &);
    Sales_data& operator=(const Sales_data &);

    explicit operator string() const {
        return bookNo;
    }
    explicit operator double() const {
        return avg_price();
    }

private:

    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream &read(istream &, Sales_data &);
ostream &print(ostream &, Sales_data &);
Sales_data add(const Sales_data &, const Sales_data &);

inline bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();  // 假设 isbn 是唯一标识
}

ostream& operator<<(ostream&, const Sales_data&);
istream& operator>>(istream&, Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data&);

#endif
