#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>

class Employee
{
private:
	std::string name;
	std::string position;
	double salary;

public:
	Employee(std::string name, std::string position, double salary);

	std::string getPosition() const;
	std::string getName() const;
	double getSalary() const;

	virtual void display();
};

#endif
