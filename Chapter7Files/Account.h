#ifndef ACCOUNT
#define ACCOUNT


class Account{
public:
    void update() { amount += amount*interestRate; }
    static double returnRate() { return interestRate; }
    static void changeRate(double newRate) { interestRate = newRate; }
    void addamount(double toAdd) { amount += toAdd; }
private:
    std::string owner;
    static double interestRate;
    double amount = 0;
};

double Account::interestRate = 0.125;

#endif // ACCOUNT
