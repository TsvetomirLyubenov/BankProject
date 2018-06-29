#include "Bank.h"
#include "PrivateCustomer.h"
#include "BusinessCustomer.h"
#include "CurrentAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"

using namespace std;

Bank::Bank(string name, string address, vector<Customer*> customers, vector<Account*> accounts, Manager* manager)
{
	this->name = name;
	this->address = address;
	this->customers = customers;
	this->accounts = accounts;
	this->manager = manager;
}

Bank::~Bank()
{
	for (int i = 0; i < accounts.size(); i++)
	{
		delete accounts[i];
	}

	for (int i = 0; i < customers.size(); i++)
	{
		delete customers[i];
	}
}

string Bank::getName() const
{
	return name;
}

string Bank::getAddress() const
{
	return address;
}

std::string Bank::getManagerName() const
{
	return manager->getName();
}

void Bank::addPrivateCustomer(string customerDatabaseID, string name, string address, string status, string uniqueCitizenshipNumber)
{
	this->customers.push_back(new PrivateCustomer(customerDatabaseID, name, address, status, uniqueCitizenshipNumber));
}

void Bank::addBusinessCustomer(string customerDatabaseID, string name, string address, string businessSize, string uniqueIdentificationNumber)
{
	this->customers.push_back(new BusinessCustomer(customerDatabaseID, name, address, businessSize, uniqueIdentificationNumber));
}


void Bank::listCustomers()
{
	cout << "Bank Customers: " << endl;
	for (int i = 0; i < customers.size(); i++)
	{
		cout << customers[i]->getName() << endl;
	}
}

void Bank::deleteCustomer(std::string customerDatabaseID)
{
	if (customers.size() <= 0)
	{
		cout << "The bank has no customers!" << endl;
	}
	else
	{
		int index = 0;
		while (index < customers.size())
		{
			if (customers[index]->getId() == customerDatabaseID)
			{
				customers.erase(customers.begin() + index);
			}
		}
	}
}

void Bank::addAccount(string accountType, string iban, std::string ownerDatabaseID, double amount)
{
	if (accountType == "Current") 
	{
		this->accounts.push_back(new CurrentAccount(iban, ownerDatabaseID, amount));
	}

	else if (accountType == "Savings")
	{
		double interestRate;
		cout << "Please enter an interest rate: " << endl;
		cin >> interestRate;
		this->accounts.push_back(new SavingsAccount(iban, ownerDatabaseID, amount, interestRate));
	}

	else if(accountType == "Privilege")
	{
		double overdraft;
		cout << "Please enter an overdraft: " << endl;
		cin >> overdraft;
		this->accounts.push_back(new PrivilegeAccount(iban, ownerDatabaseID, amount, overdraft));
	}
}

void Bank::deleteAccount(string iban)
{
	if (accounts.size() <= 0)
	{
		cout << "The bank has no accounts!" << endl;
	}
	else
	{
		int index = 0;
		while (index < accounts.size())
		{
			if (accounts[index]->getIban() == iban)
			{
				accounts.erase(accounts.begin() + index);
			}
		}
	}
}

void Bank::listAccounts()
{
	cout << "Bank Accounts' information: " << endl;
	for (int i = 0; i < accounts.size(); i++)
	{
		accounts[i]->display();
	}
}

void Bank::listCustomerAccount(std::string customerDatabaseID)
{
	cout << "Bank Accounts' information of the customer: ";
	cout << customerDatabaseID << endl;
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getOwnerDatabaseID() == customerDatabaseID)
		{
			accounts[i]->display();
		}
	}
}

void Bank::listEmployees() const
{
	int numberOfEmployees = manager->getNumberOfEmployees();
	const vector<Employee*> employees = manager->getEmployees();

	for (int i = 0; i < numberOfEmployees; i++)
	{
		employees[i]->display();
		cout << endl;
	}
}

void Bank::transfer(string fromIBAN, string toIBAN, double amount)
{
	for  (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == fromIBAN)
		{
			for (int j = 0; j < accounts.size(); j++)
			{
				if (accounts[j]->getIban() == toIBAN && accounts[i]->withdraw(amount))
				{
						accounts[j]->deposit(amount);
				}
			}
		}
	}
}

void Bank::display()
{
	cout << "Bank information: " << endl;

	cout << "Name: " << getName() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "Manager: " << getManagerName() << endl;
	

	cout << "Bank Customers' information: " << endl;
	for (int i = 0; i < customers.size(); i++)
	{
		customers[i]->display();
	}

	cout << "Bank Accounts' information: " << endl;
	for (int i = 0; i < accounts.size(); i++)
	{
		accounts[i]->display();
	}
}

void Bank::deposit(string databaseID, double deposit)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getOwnerDatabaseID() == databaseID)
		{
			accounts[i]->deposit(deposit);
		}
	}
}

void Bank::withdraw(string databaseID, double withdraw)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getOwnerDatabaseID() == databaseID)
		{
			accounts[i]->withdraw(withdraw);
		}
	}
}





