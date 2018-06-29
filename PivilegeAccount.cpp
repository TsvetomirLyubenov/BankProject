#include "PrivilegeAccount.h"

using namespace std;

PrivilegeAccount::PrivilegeAccount(string iban, string ownerDatabaseID, int amount, double overdraft) : Account(iban, ownerDatabaseID, amount)
{
	this->overdraft = overdraft;
}

double PrivilegeAccount::getOverdraft() const
{
	return overdraft;
}

void PrivilegeAccount::deposit(double deposit)
{
	this->amount += deposit;
}

bool PrivilegeAccount::withdraw(double withdraw)
{
	if (this->amount + overdraft >= withdraw)
	{
		this->amount -= withdraw;
		return true;
	}

	return false;
}

void PrivilegeAccount::display()
{
	
	cout << "Account type: Savings Account" << endl;
	cout << "Savings Account information: " << endl;

	cout << "IBAN: " << getIban() << endl;
	cout << "Owner ID: " << getOwnerDatabaseID() << endl;
	cout << "Overdraft: " << getOverdraft() << endl;

	getBalance();
}
