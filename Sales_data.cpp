#include "Sales_data.h"
#include <iostream>


using std::endl;

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << endl;
    return os;
}

Sales_data add(Sales_data &lhs, Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}



inline double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

Sales_data& Sales_data::operator+=(const Sales_data &sd1) {
    units_sold += sd1.units_sold;
    revenue += sd1.revenue;
    return *this;
}

ostream& operator<<(ostream &os, const Sales_data& sd) {
    os << sd.bookNo << " " << sd.units_sold << " " << sd.revenue << endl;
    return os;
}

istream& operator>>(istream &is, Sales_data &sd) {
    double price;
    is >> sd.bookNo >> sd.units_sold >> sd.revenue;
    if (is)
        sd.revenue = sd.units_sold * price;
    else
        sd = Sales_data();
    return is;
}

Sales_data operator+(const Sales_data &sd1, const Sales_data&sd2) {
    Sales_data sum = sd1;
    sum += sd2;
    return sum;
}

Sales_data& Sales_data::operator=(const std::string &isbn) {
    *this = Sales_data(isbn);
    return *this;
}
