#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H
#include <iostream>
#include <string>
#include "Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount(std::string iban, std::string ownerDatabaseID, int amount);
	virtual void deposit(double deposit);
	virtual bool withdraw(double withdraw);
	virtual void display();
};

#endif
