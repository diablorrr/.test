#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

using std::string;

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }

private:
    string owner;
    double amount;
    static double interestRate;
    static constexpr int todayRate = 42.42;
    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();

#endif
