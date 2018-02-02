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
void updateCust(Customer [], int, int, int);
void displayCust(Customer [], int);
int findCust(Customer [], int , int );
void sortCust(Customer [], int);

/*~~~~~~~ CONSTANTS ~~~~~~~*/
const int MAXCUST = 30;


/*~~~~~~~ MAIN ~~~~~~~~*/
int main()
{
	//declarations
	Customer cust[MAXCUST];
	int count = 0;
	int cust_id = 0;
	int cust_index = 0;
	int cust_edit = 0;
	string choice = "";

	do
	{
		sortCust(cust, count);
		menu(choice);
		if (choice == "1")
		{
			addCust(cust, count);
			count++;
		}
		else if (choice == "2")
		{
			cout << "Enter an id to edit : ";
			updateCust(cust, count, cust_edit, findCust(cust, count, cust_id));
		}
		else if (choice == "3")
		{
			displayCust(cust, count);
		}
		else if (choice == "4")
		{
			cout << "Enter an id : ";
			cin >> cust_id;
			cust_index = findCust(cust, count, cust_id);

			if (cust_index != -1)
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << setw(5) << left << "ID" << setw(20) << left << "Name" << setw(8) << left << "Zip"
					<< setw(10) << left << "Balance" << setw(10) << "Payment Date" << endl;

				cout << setw(5) << left << cust[cust_index].id << setw(20) << left << cust[cust_index].name
					<< setw(8) << left << cust[cust_index].zip << setw(10) << left << cust[cust_index].balance
					<< setw(10) << cust[cust_index].pmtDate << endl;
			}
			else
			{
				cout << "No customer found\n";
			}
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
		cout << "Enter a choice : ";
		getline(cin, choice);
		if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5")
		{
			isValid = true;
		}
		else
		{
			cout << "Enter a valid choice (1-5)\n";
			
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
	
	int i = count;
	//add id, name, zip, balance, pmtDate

	cout << "Add an ID for the new customer : ";
	cin >> cust[i].id;
	//validate

	cout << "Add a name for the new customer : ";
	cin.ignore();
	getline(cin, cust[i].name);

	cout << "Add a zip for the new customer : ";
	cin >> cust[i].zip;

	cout << "Add a balance for the new customer : ";
	cin >> cust[i].balance;
	//validate

	cout << "Add a payment date for the new customer : ";
	cin >> cust[i].pmtDate;

	cin.ignore();
}

// Function: updateCust
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 
void updateCust(Customer cust[], int count, int cust_edit, int findcust)
{
	if (findcust != -1)
	{
		int i = count;
		//add id, name, zip, balance, pmtDate

		cout << "Add an ID for the new customer : ";
		cin >> cust[i].id;
		//validate

		cout << "Add a name for the new customer : ";
		cin.ignore();
		getline(cin, cust[i].name);

		cout << "Add a zip for the new customer : ";
		cin >> cust[i].zip;

		cout << "Add a balance for the new customer : ";
		cin >> cust[i].balance;
		//validate

		cout << "Add a payment date for the new customer : ";
		cin >> cust[i].pmtDate;

		cin.ignore();
	}
}


// Function: displayCust
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 
void displayCust(Customer cust[], int count)
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << setw(5) << left << "ID" << setw(20) << left << "Name" << setw(8) << left << "Zip" 
		<< setw(10) << left << "Balance" << setw(10) << "Payment Date" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << setw(5) << left << cust[i].id << setw(20) << left << cust[i].name << setw(8) << left << cust[i].zip 
			<< setw(10) << left << cust[i].balance << setw(10) << cust[i].pmtDate << endl;
	}
}


// Function: findCust
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: int
int findCust(Customer cust[], int count, int cust_id)
{
	int low_index = 0;
	int high_index = count;
	int mid_index = 0;
	int position = -1;

	bool isFound = false;

	while (!isFound && low_index <= high_index)
	{
		mid_index = (low_index + high_index) / 2;

		if (cust[mid_index].id == cust_id)
		{
			isFound = true;
			position = mid_index;
		}
		else if (cust[mid_index].id > cust_id)
		{
			high_index = mid_index - 1;
		}
		else
		{
			low_index = mid_index + 1;
		}
	}

	cin.ignore();
	return position;
}


// Function: sortCust
// Description: bubble sort
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 
void sortCust(Customer cust[], int count)
{
	//Variables
	bool isSorted;
	Customer temp;

	do
	{
		isSorted = true;
		//Bubble sorter

		for (int i = 0; i < count -1; i++)
		{
			if (cust[i].id > cust[i + 1].id)
			{
				temp = cust[i];
				cust[i] = cust[i + 1];
				cust[i + 1] = temp;

				isSorted = false;
			}
		}
	} while (!isSorted);
}
