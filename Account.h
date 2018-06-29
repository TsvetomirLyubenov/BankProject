#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

class Account
{
protected:
	std::string iban;
	std::string ownerDatabaseID;
	double amount;

public:
	Account(std::string iban, std::string ownerDatabaseID, int amount);

	std::string getIban() const;
	std::string getOwnerDatabaseID() const;
	double getAmount() const;

	virtual void deposit(double deposit) = 0;
	virtual bool withdraw(double withdraw) = 0;
	virtual void display() = 0;

	void getBalance();
};

#endif
