#include "PrivateCustomer.h"

using namespace std;

PrivateCustomer::PrivateCustomer(std::string databaseID, std::string name, std::string address, std::string status, std::string uniqueCitizenshipNumber) : Customer(databaseID, name, address)
{
	this->status = status;
	this->uniqueCitizenshipNumber = uniqueCitizenshipNumber;
}

string PrivateCustomer::getStatus() const
{
	return status;
}

string PrivateCustomer::getUniqueCitizenshipNumber() const
{
	return uniqueCitizenshipNumber;
}

void PrivateCustomer::display()
{
	cout << "Customer information: " << endl;

	cout << "Type: " << "Private Customer" << endl;
	cout << "Database ID: " << databaseID << endl;
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Status: " << status << endl;
	cout << "Unique citizenship number: " << uniqueCitizenshipNumber << endl;
}