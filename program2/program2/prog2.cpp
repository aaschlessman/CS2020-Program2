// Program 2
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020 - 9:30 AM, Spring 2018

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

/*~~~~~~~~ STRUCTURES ~~~~~~~~~*/
struct Customer
{
	int id;				// id
	string name;		// Name
	string zip;			// ZIP code
	double balance;		// Account balance
	string pmtDate;		// Date of last payment
};

/*~~~~~~~ PROTOTYPES ~~~~~~~~*/
string menu(string &);
void addCust(Customer[], int);
void updateCust();
void displayCust();
void findCust();
void sortCust();

/*~~~~~~~ CONSTANTS ~~~~~~~*/
const int MAXCUST = 30;


/*~~~~~~~ MAIN ~~~~~~~~*/
int main()
{
	//declarations
	Customer cust[MAXCUST];
	int count = 0;
	string choice = "";

	do
	{
		menu(choice);
		if (choice == "1")
		{
			addCust(cust, count);
			count++;
		}
		else if (choice == "2")
		{

		}
		else if (choice == "3")
		{

		}
		else if (choice == "4")
		{

		}
		else
		{
			cout << endl;
			cout << "Program end\n";
		}

	} while (choice != "5");





	system("Pause");
	return 0;
}

// Function: menu
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 
string menu(string & choice)
{
	bool isValid = false;

	cout << "           Menu of choices\n";
	cout << "+++++++++++++++++++++++++++++++++++++++\n";
	cout << "1. Enter new account information\n";
	cout << "2. Change account information\n";
	cout << "3. Display all account information\n";
	cout << "4. Find customer\n";
	cout << "5. Exit the program" << endl << endl;
	do
	{
		cout << "Enter a choice :";
		getline(cin, choice);
		if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5")
		{
			isValid = true;
			cin.ignore();
		}
		else
		{
			cout << "Enter a valid choice (1-5)\n";
			cin.ignore();
		}


	} while (isValid != true);

	return choice;
}



// Function: addCust
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 
void addCust(Customer cust[], int count)
{
	int i = 0;

	//add id, name, zip, balance, pmtDate

	cout << "Add an ID for the new customer : ";
	cin >> cust[i].id;
	//validate

	cout << "Add a name for the new customer : ";
	getline(cin, cust[i].name);

	cout << "Add a zip for the new customer : ";
	cin >> cust[i].zip;

	cout << "Add a balance for the new customer : ";
	cin >> cust[i].balance;
	//validate

	cout << "Add a payment date for the new customer : ";
	cin >> cust[i].pmtDate;


}

// Function: updateCust
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 
void updateCust()
{

}


// Function: displayCust
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 
void displayCust()
{

}


// Function: findCust
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: int
void findCust()
{

}


// Function: sortCust
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 
void sortCust()
{

}
