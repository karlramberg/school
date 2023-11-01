#include"PreferredCustomer.cpp"
#include<string> 
#include<iostream>

using namespace std;

int main()
{
    string lastName;
    cout << "What is the customer's last name? ";
    getline(cin, lastName);

    string firstName;
    cout << "What is the customer's first name? ";
    getline(cin, firstName);

    string address;
    cout << "What is the customer's address? ";
    getline(cin, address);

    string city;
    cout << "What city does the customer live in? ";
    getline(cin, city);

    string state;
    cout << "What state does the customer live in? ";
    getline(cin, state);

    int zip;
    cout << "What is the customer's zip code? ";
    cin >> zip;

    long phone;
    cout << "What is the customer's phone number? (no formatting) ";
    cin >> phone;

    int customerNumber;
    cout << "What is the customer's unique id number? ";
    cin >> customerNumber;

    string dummy;
    getline(cin,dummy); // eats the newline cin doesn't

    string answer;
    cout << "Would they like to be on the mailing list? (y for yes): ";
    getline(cin, answer);
    bool mailingList = answer == "y" ? true : false;

    double purchaseAmount;
    cout << "What's the total dollar amount they've spent? ";
    cin >> purchaseAmount;
    bool negative = purchaseAmount < 0.0 ? true : false;
    while(negative)
    {
	cout << "The customer cannot have a negative purchase total." << endl;
	cout << "What's the total dollar amount they've spent? ";
	cin >> purchaseAmount;
	negative = purchaseAmount < 0.0 ? true : false;
    }

    PreferredCustomer customer(lastName,
			       firstName,
			       address,
			       city,
			       state,
			       zip,
			       phone,
			       customerNumber,
			       mailingList,
			       purchaseAmount);

    cout << customer.getFirstName() << " " << customer.getLastName()
	 << " has spent " << customer.getPurchaseAmount()
	 << " and has earned a " << (static_cast<int>(customer.getDiscountLevel() * 100))
	 << "\% discount" << endl;

    return 0;
}
