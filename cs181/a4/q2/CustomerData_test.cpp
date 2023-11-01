#include"CustomerData.cpp"
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<CustomerData> customers;
   
    bool done = false; 
    while(!done)
    {
	string lastName;
	cout << "Enter the new customer's last name: ";
	getline(cin, lastName);

	string firstName;
	cout << "Enter their first name: ";
	getline(cin, firstName);

	string address;
	cout << "Enter their address: ";
	getline(cin, address);

	string city;
	cout << "Enter the city where they live: ";
	getline(cin, city);

	string state;
	cout << "Enter the state where they live: ";
	getline(cin, state);

	int zip;
	cout << "Enter their zip code: ";
	cin >> zip;

	long phone;
	cout << "Enter their phone number (no formatting): ";
	cin >> phone;

	int number;
	cout << "Enter their unique ID number: ";
	cin >> number;

	string dummy;	
	getline(cin, dummy); // consumes newline cin doesn't use

	string answer;
	cout << "Would they like to be on the mailing list? (y for yes): ";
	getline(cin, answer);
	bool mailingList = answer == "y" ? true : false;

	customers.emplace_back(lastName,
			       firstName,
			       address,
			       city,
			       state,
			       zip,
			       phone,
			       number,
			       mailingList);	

	getline(cin, dummy); // consumes newline cin doesn't use

	cout << "Add another worker? (q to quit) ";
	getline(cin, answer);
	if(answer == "q")
	{
	    done = true;
	}
    }

    return 0;
}
