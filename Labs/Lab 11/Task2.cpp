#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(string accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}

    virtual void deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void calculateInterest() = 0;

    string getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }
};

class SavingsAccount : public Account {
protected:
    double interestRate;

public:
    SavingsAccount(double interestRate, string accountNumber, double balance) : interestRate(interestRate), Account(accountNumber, balance) {}

    virtual void deposit(double amount) override {
        balance += amount;
    }

    virtual bool withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient balance\nCurrent Balance= " << balance << endl;
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    virtual void calculateInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
    }
};

class CurrentAccount : public Account {
protected:
    double overDraftLimit;

public:
    CurrentAccount(double overDraftLimit, string accountNumber, double balance) : overDraftLimit(overDraftLimit), Account(accountNumber, balance) {}

    virtual void deposit(double amount) override {
        balance += amount;
    }

    virtual bool withdraw(double amount) override {
        if (amount > balance && (amount - balance) > overDraftLimit) {
            cout << "OverDraftLimit Exceeded\nOverDraftLimit: " << overDraftLimit << endl << "Current Balance= " << balance << endl;
            return false;
        } else if (amount > balance && (amount - balance) < overDraftLimit) {
         
		    overDraftLimit -= (amount-balance);
		    balance=0;
            cout << "OverDraftLimit used\nOverDraftLimit: " << overDraftLimit << endl << "Current Balance= " << balance << endl;
       return true;
	    } else {
            balance -= amount;
            return true;
        }
    }

    virtual void calculateInterest() override {
        cout << "No interest\n";
    }
};

