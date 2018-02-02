// Program 2
// Description: structures
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

	//validation
	do
	{
		//sorts and shows menu
		sortCust(cust, count);
		menu(choice);
		//choice 1
		if (choice == "1")
		{
			addCust(cust, count);
			count++;
		}
		//choice 2
		else if (choice == "2")
		{
			cout << "Enter an id to edit : ";
			cin >> cust_edit;
			cout << cust_edit << endl;

			updateCust(cust, count, cust_edit, findCust(cust, count, cust_edit));
		}
		//choice 3
		else if (choice == "3")
		{
			displayCust(cust, count);
		}
		//choice 4
		else if (choice == "4")
		{
			//choice 4 validation
			cout << "Enter an id : ";
			cin >> cust_id;
			cout << cust_id << endl;
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
		//choice 5
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
// Description: display menu choice
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	choice - user input
// Returns: valid choice as string
string menu(string & choice)
{
	bool isValid = false;
	cout << endl;
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
		//cin.ignore();
		getline(cin, choice);
		cout << choice << endl;

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
// Description: adds a new customer to structure
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	cust[] array of structure Customer
//				count - int representation of the number of id's
// Returns: void
void addCust(Customer cust[], int count)
{
	
	int i = count;
	//add id, name, zip, balance, pmtDate
	//validation for id
	do
	{
		cout << "Add an ID for the new customer : ";
		cin >> cust[i].id;
		cout << cust[i].id << endl;

		if (cust[i].id < 0)
		{
			cout << "Enter an ID that is greater than -1\n";
		}
	} while (cust[i].id < 0);

	cout << "Add a name for the new customer : ";
	cin.ignore();
	getline(cin, cust[i].name);
	cout << cust[i].name << endl;

	cout << "Add a zip for the new customer : ";
	cin >> cust[i].zip;
	cout << cust[i].zip << endl;

	//validation for balance
	do
	{
		cout << "Add a balance for the new customer : ";
		cin >> cust[i].balance;
		cout << cust[i].balance << endl;

		if (cust[i].balance < 0)
		{
			cout << "Enter a balance that is greater than -1\n";
		}
	} while (cust[i].balance < 0);

	cout << "Add a payment date for the new customer : ";
	cin >> cust[i].pmtDate;
	cout << cust[i].pmtDate << endl;

	cin.ignore();
}

// Function: updateCust
// Description: changes an existing customer to users choice
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	cust[] array of structure Customer
//				count - int representation of the number of id's
//				cust_edit - the user input to edit
//				foundcust - the customers id number that needs to be edited
// Returns:		void
void updateCust(Customer cust[], int count, int cust_edit, int foundcust)
{
	if (foundcust != -1)
	{
		int i = count;
		//edit name, zip, balance, pmtDate

		cout << "Add a new name for customer " << cust[foundcust].id << " : ";
		//cin.ignore();
		getline(cin, cust[foundcust].name);
		cout << cust[foundcust].name << endl;

		cout << "Add a new zip for customer " << cust[foundcust].id << " : ";
		cin >> cust[foundcust].zip;
		cout << cust[foundcust].zip << endl;

		//validation for new balance
		do
		{
			cout << "Add a new balance for customer " << cust[foundcust].id << " : ";
			cin >> cust[foundcust].balance;
			cout << cust[foundcust].balance << endl;

			if (cust[foundcust].balance < 0)
			{
				cout << "Enter a balance that is greater than -1\n";
			}
		} while (cust[foundcust].balance < 0);

		cout << "Add a new payment date for customer " << cust[foundcust].id << " : ";
		cin >> cust[foundcust].pmtDate;
		cout << cust[foundcust].pmtDate << endl;

		cin.ignore();
	}
	else
	{
		cout << "id not found\n";
	}

	
}


// Function: displayCust
// Description: displays a tubular list of customers
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	cust[] array of structure Customer
//				count - int representation of the number of id's
// Returns: void
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
// Parameters:	cust[] array of structure Customer
//				count - int representation of the number of id's
//				cust_id - the id needed to be found
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
// Description: bubble sorts array of structure
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	cust[] array of structure Customer
//				count - int representation of the number of id's
// Returns: void
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
