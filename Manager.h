#ifndef	MANAGER_H
#define MANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"

class Manager
{
private:
	std::string name;
	std::vector<Employee*> employees;
	double salary;

public:
	Manager(std::string name, std::vector<Employee*> employees, double salary);
	~Manager();

	void addEmployee(std::string name, std::string position, double salary);
	void removeEmployee(std::string name, std::string position, double salary);
	
	const std::vector<Employee*> getEmployees() const;

	int getNumberOfEmployees() const;
	std::string getName() const;
	double getSalary() const;

	virtual void display();
};

#endif
