#include "BusinessCustomer.h"

using namespace std;

BusinessCustomer::BusinessCustomer(string databaseID, string name, string address, string businessSize, string uniqueIdentificationNumber) : Customer(databaseID, name, address)
{
	this->businessSize = businessSize;
	this->uniqueIdentificationNumber = uniqueIdentificationNumber;
}

string BusinessCustomer::getBusinessSize() const
{
	return businessSize;
}

string BusinessCustomer::getUniqueIdentificationNumber() const
{
	return uniqueIdentificationNumber;
}

void BusinessCustomer::display()
{
	cout << "Customer information: " << endl;

	cout << "Type: " << "Private Customer" << endl;
	cout << "Database ID: " << databaseID << endl;
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Business size: " << businessSize << endl;
	cout << "Unique identification number: " << uniqueIdentificationNumber << endl;
}