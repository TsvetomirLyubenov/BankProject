#ifndef PRIVILEGEACCOUNT_H
#define PRIVILEGECCOUNT_H
#include <iostream>
#include <string>
#include "Account.h"

class PrivilegeAccount : public Account
{
private:
	double overdraft;

public:
	PrivilegeAccount(std::string iban, std::string ownerDatabaseID, int amount, double overdraft);

	double getOverdraft() const;

	virtual void deposit(double deposit);
	virtual bool withdraw(double withdraw);
	virtual void display();
};

#endif

