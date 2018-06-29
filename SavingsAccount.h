#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include <string>
#include "Account.h"

class SavingsAccount : public Account
{
private:
	double interestRate;
public:
	SavingsAccount(std::string iban, std::string ownerDatabaseID, int amount, double interestRate);

	double getInterestRate() const;

	virtual void deposit(double deposit);
	virtual bool withdraw(double withdraw);
	virtual void display();
};

#endif

