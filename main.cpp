#include <iostream>
#include <vector>
#include <string>

#include "Bank.h"
#include "Manager.h"
#include "Employee.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include "Customer.h"
#include "BusinessCustomer.h"
#include "PrivateCustomer.h"

using namespace std;

int main()
{
	vector<Customer*> customers;
	customers.push_back(new PrivateCustomer("47842", "Ivan Stoyanov", "Sofia, Studentski grad, Block 37", "Employed", "9603027825"));
	customers.push_back(new BusinessCustomer("66666", "PrintExpress", "Sofia, Bul. Tsarigradsko Shose 12", "Small", "74525988"));
	customers.push_back(new BusinessCustomer("66634", "Telenor", "Sofia, Mladost 4, Business Park Sofia", "Large", "27845839"));
	customers.push_back(new PrivateCustomer("66644", "Petar Kolev", "Sofia, Studentski grad, Block 33", "Unemployed", "9204123595"));
	customers.push_back(new PrivateCustomer("83334", "Klimentina Mladenova", "Sofia, Mladost 1, Block 65", "Retired", "4507097523"));

	vector<Account*> accounts;
	accounts.push_back(new CurrentAccount("1234567890", "47842", 1000));
	accounts.push_back(new CurrentAccount("12345678900", "66666", 1002));

	accounts.push_back(new SavingsAccount("12321432453432", "66634", 555, 10));
	accounts.push_back(new SavingsAccount("1232453432", "66644", 55, 18));

	accounts.push_back(new PrivilegeAccount("1232453432", "83334", 65, 48));
	accounts.push_back(new PrivilegeAccount("1232453432", "47842", 56, 38));

	vector<Employee*> employees;
	employees.push_back(new Employee("Maria Blagoeva", "Accountant", 800));
	employees.push_back(new Employee("Anton Nikolov", "Main Consultant", 1200));
	employees.push_back(new Employee("Stoyka Dimitrova", "Cashier", 750));

	Manager manager("Ivan Ivanov", employees, 5000);

	Bank bank("DSK", "Studentski grad, 8 Dekemvri 10", customers, accounts, &manager);

	int choice;

	do
	{
		cout << "BANK MENU" << endl;
		cout << "....................................................." << endl;

		cout << "Please enter one of the option buttons that you want:" << endl;

		cout << "1 - List customers" << endl;
		cout << "2 - Add new customer" << endl;
		cout << "3 - Delete customer" << endl;
		cout << "4 - List all accounts" << endl;
		cout << "5 - List customer accounts" << endl;
		cout << "6 - Add new account" << endl;
		cout << "7 - Delete account" << endl;
		cout << "8 - Withdraw from account" << endl;
		cout << "9 - Deposit to account" << endl;
		cout << "10 - Transfer" << endl;
		cout << "11 - Display info for the bank" << endl;
		cout << "12 - List Employees" << endl;
		cout << "13 - Quit" << endl;

		cout << "....................................................." << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		cout << "....................................................." << endl;

		if (choice == 1)
		{
			bank.listCustomers();
		}

		else if (choice == 2)
		{
			cout << "Private or business customer?" << endl;
			string type;
			cin >> type;

			cout << "Please enter database ID: " << endl;
			string databaseID;
			cin >> databaseID;
			cout << "Please enter name: " << endl;
			string name;
			cin >> name;
			cout << "Please enter adress: " << endl;
			string address;
			cin >> address;

			if (type == "Private")
			{
				cout << "Please enter status: " << endl;
				string status;
				cin >> status;

				cout << "Please enter Unique Citizenship Number: " << endl;
				string uniqueCitizenshipNumber;
				cin >> uniqueCitizenshipNumber;

				bank.addPrivateCustomer(databaseID, name, address, status, uniqueCitizenshipNumber);
			}

			else if (type == "Business")
			{
				cout << "Please enter business size: " << endl;
				string businessSize;
				cin >> businessSize;

				cout << "Please enter Unique Identification Number: " << endl;
				string uniqueIdentificationNumber;
				cin >> uniqueIdentificationNumber;

				bank.addBusinessCustomer(databaseID, name, address, businessSize, uniqueIdentificationNumber);
			}
	
		}

		else if (choice == 3)
		{
			string customerDatabaseID;
			cout << "Please enter the customer databese ID, which you want to delete: " << endl;
			cin >> customerDatabaseID;
			bank.deleteCustomer(customerDatabaseID);
		}

		else if (choice == 4)
		{
			bank.listAccounts();
		}

		else if (choice == 5)
		{
			string customerDatabaseID;
			cout << "Please enter the customer database ID for information: " << endl;
			cin >> customerDatabaseID;
			bank.listCustomerAccount(customerDatabaseID);
		}

		else if (choice == 6)
		{
			string typeOfAccount;

			cout << "Please enter the account you want to use" << endl;
			cout << "Your can choose between: " << endl;
			cout << "Current" << endl;
			cout << "Savings" << endl;
			cout << "Privilege" << endl;

			cin >> typeOfAccount;

			string iban;
			string ownerDatabaseID;
			double amount;

			if (typeOfAccount == "Current" || typeOfAccount == "Savings" || typeOfAccount == "Privilege")
			{
				cout << "Please enter an iban: " << endl;
				cin >> iban;
				cout << "Please enter an owner database ID: " << endl;
				cin >> ownerDatabaseID;
				cout << "Please enter an amount: " << endl;
				cin >> amount;

				if (typeOfAccount == "Current")
				{
					bank.addAccount("Current", iban, ownerDatabaseID, amount);
				}

				if (typeOfAccount == "Savings")
				{
					bank.addAccount("Savings", iban, ownerDatabaseID, amount);
				}

				if (typeOfAccount == "Privilege")
				{
					bank.addAccount("Privilege", iban, ownerDatabaseID, amount);
				}
			}
			else
			{
				cout << "There is no such account type." << endl;
			}
		}

		else if (choice == 7)
		{
			string iban;
			cout << "Please enter the IBAN of the customer, whose account you want to delete: " << endl;
			cin >> iban;
			bank.deleteAccount(iban);
		}

		else if (choice == 8)
		{
			string databaseID;
			cout << "Please enter the database ID of the customer, from whose account you want to withdraw an amount: " << endl;
			cin >> databaseID;

			double withdraw;
			cout << "Please enter the amount to withdraw: " << endl;
			cin >> withdraw;

			bank.withdraw(databaseID, withdraw);
		}

		else if (choice == 9)
		{
			string databaseID;
			cout << "Please enter the ID of the customer, to whose account you want to deposit an amount: " << endl;
			cin >> databaseID;

			double deposit;
			cout << "Please enter the amount to deposit: " << endl;
			cin >> deposit;

			bank.deposit(databaseID, deposit);
		}

		else if (choice == 10)
		{
			string fromIBAN;
			string toIBAN;
			double amount;

			cout << "Please enter the IBAN of the sender, the IBAN of the receiver and the amount that you want to transfer: ";

			cin >> fromIBAN;
			cin >> toIBAN;
			cin >> amount;

			bank.transfer(fromIBAN, toIBAN, amount);
		}

		else if (choice == 11)
		{
			bank.display();
		}

		else if (choice == 12)
		{
			bank.listEmployees();
		}

		if (choice != 13)
		{
			system("pause");
			system("cls");
		}

	} while (choice != 13);

	return 0;
}
