#include "Account.h"

using namespace std;

Account::Account(string iban, string ownerDatabaseID, int amount)
{
	this->iban=iban;

	this->ownerDatabaseID = ownerDatabaseID;
	this->amount = amount;
}

string Account::getIban() const
{
	return iban;
}

string Account::getOwnerDatabaseID() const
{
	return ownerDatabaseID;
}

double Account::getAmount() const
{
	return amount;
}

void Account::getBalance()
{
	cout << "Balance information: " << endl;
	cout << "Balance: " << this->amount << endl;
}
