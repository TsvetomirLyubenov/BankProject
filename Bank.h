#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include<vector>

#include "Customer.h"
#include "Account.h"
#include "Manager.h"

class Bank
{
private:
	std::string name;
	std::string address;
	std::vector<Customer*> customers;
	std::vector<Account*> accounts;
	Manager* manager;

public:
	Bank(std::string name, std::string address, std::vector<Customer*> customers, std::vector<Account*> accounts, Manager* manager);

	~Bank();

	std::string getName() const;
	std::string getAddress() const;
	std::string getManagerName() const;
	
	void addPrivateCustomer(std::string customerDatabaseID, std::string name, std::string address, std::string status, std::string uniqueCitizenshipNumber);
	void addBusinessCustomer(std::string customerDatabaseID, std::string name, std::string address, std::string businessSize, std::string uniqueIdentificationNumber);
	void listCustomers();
	void deleteCustomer(std::string customerDatabaseID);
	void addAccount(std::string accountType, std::string iban, std::string ownerId, double amount);
	void deleteAccount(std::string iban);
	void listAccounts();
	void listCustomerAccount(std::string customerDatabaseID);
	void listEmployees() const;
	void transfer(std::string fromIBAN, std::string toIBAN, double amount);
	void display();

	void deposit(std::string customerDatabaseID, double deposit);
	void withdraw(std::string customerDatabaseID, double withdraw);
};

#endif