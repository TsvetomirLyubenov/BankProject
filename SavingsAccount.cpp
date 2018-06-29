#include "SavingsAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(string iban, string ownerDatabaseID, int amount, double interestRate) : Account(iban, ownerDatabaseID, amount)
{
	this->interestRate = interestRate;
}

double SavingsAccount::getInterestRate() const
{
	return interestRate;
}

void SavingsAccount::deposit(double deposit)
{
	this->amount += deposit;
}

bool SavingsAccount::withdraw(double withdraw)
{
	if (this->amount >= withdraw)
	{
		this->amount -= withdraw;
		return true;
	}

	return false;
}

void SavingsAccount::display()
{
	cout << "Account type: Savings Account" << endl;
	cout << "Savings Account information: " << endl;

	cout << "IBAN: " << getIban() << endl;
	cout << "Owner ID: " << getOwnerDatabaseID() << endl;
	cout << "Interest rate: " << getInterestRate() << endl;
	
	getBalance();
}
