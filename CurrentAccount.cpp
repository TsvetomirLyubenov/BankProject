#include "CurrentAccount.h"

using namespace std;

CurrentAccount::CurrentAccount(string iban, string ownerDatabaseID, int amount):Account(iban, ownerDatabaseID, amount){}

void CurrentAccount::deposit(double deposit)
{
	this->amount += deposit;
}

bool CurrentAccount::withdraw(double withdraw)
{
	if (this->amount >= withdraw)
	{
		this->amount -= withdraw;
		return true;
	}

	return false;
}

void CurrentAccount::display()
{	
	cout << "Account type: Current Account" << endl;
	cout << "CurrentAccount information: " << endl;

	cout << "IBAN: " << getIban() << endl;
	cout << "Owner ID: " << getOwnerDatabaseID() << endl;

	getBalance();
}
