#ifndef PRIVATECUSTOMER_H
#define PRIVATECUSTOMER_H
#include <iostream>
#include <string>
#include "Customer.h"

class PrivateCustomer: public Customer
{
private:
	std::string status;
	std::string uniqueCitizenshipNumber;

public:
	PrivateCustomer(std::string databaseID, std::string name, std::string address, std::string status, std::string uniqueCitizenshipNumber);

	std::string getStatus() const;
	std::string getUniqueCitizenshipNumber() const;

	void display();
};

#endif
