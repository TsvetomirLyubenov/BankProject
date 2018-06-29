#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

class Customer
{
protected:
	std::string databaseID;
	std::string name;
	std::string address;

public:
	Customer(std::string databaseID, std::string name, std::string address);

	std::string getId() const;
	std::string getName() const;
	std::string getAddress() const;

	virtual void display() = 0;
};

#endif
