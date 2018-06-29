#include "Manager.h"

using namespace std;

Manager::Manager(string name, vector<Employee*> employees, double salary)
{
	this->name = name;
	this->employees = employees;
	this->salary = salary;
}

Manager::~Manager()
{
	for (int i = 0; i < employees.size(); i++)
	{
		delete employees[i];
	}
}

void Manager::addEmployee(string name, string position, double salary)
{
	employees.push_back(new Employee(name, position, salary));
}

void Manager::removeEmployee(string name, string position, double salary)
{
	for (int i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getName() == name && employees[i]->getPosition() == position && employees[i]->getSalary() == salary)
		{
			employees.erase(employees.begin() + i);
			break;
		}
	}
}

const std::vector<Employee*> Manager::getEmployees() const
{
	return employees;
}

int Manager::getNumberOfEmployees() const
{
	return employees.size();
}

string Manager::getName() const
{
	return name;
}

double Manager::getSalary() const
{
	return salary;
}

void Manager::display()
{
	cout << "Manager information: " << endl;

	cout << "Name: " << name << endl;
	cout << "Salary: " << salary << endl << endl;
	cout << "Employees: "<< endl << endl;

	for (int i = 0; i < employees.size(); i++)
	{
		employees[i]->display();
		cout << endl;
	}
	
}

