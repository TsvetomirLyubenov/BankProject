#include "Employee.h"

using namespace std;

Employee::Employee(string name, string position, double salary)
{
	this->name = name;
	this->position = position;
	this->salary = salary;
}

string Employee::getPosition() const
{
	return position;
}

string Employee::getName() const
{
	return name;
}

double Employee::getSalary() const
{
	return salary;
}

void Employee::display()
{
	cout << "Employee information: " << endl;

	cout << "Name: " << name << endl;
	cout << "Position: " << position << endl;
	cout << "Salary: " << salary << endl;
}

