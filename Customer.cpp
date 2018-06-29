#include "Customer.h"

using namespace std;

Customer::Customer(string databaseID, string name, string address)
{
	this->databaseID = databaseID;
	this->name = name;
	this->address = address;
}

string Customer::getId() const
{
	return databaseID;
}

string Customer::getName() const
{
	return name;
}

string Customer::getAddress() const
{
	return address;
}


