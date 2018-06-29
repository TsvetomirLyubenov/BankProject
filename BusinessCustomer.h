#ifndef BUSINESSCUSTOMER_H
#define BUSINESSCUSTOMER_H
#include <iostream>
#include <string>
#include "Customer.h"

class BusinessCustomer : public Customer
{
private:
	std::string businessSize;
	std::string uniqueIdentificationNumber;

public:
	BusinessCustomer(std::string customerDatabaseID, std::string name, std::string address, std::string businessSize, std::string uniqueIdentificationNumber);

	std::string getBusinessSize() const;
	std::string getUniqueIdentificationNumber() const;

	void display();
};

#endif
