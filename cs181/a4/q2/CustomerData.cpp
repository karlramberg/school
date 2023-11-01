#include"PersonData.cpp"

using namespace std;

class CustomerData : public PersonData
{
private:
    int customerNumber;
    bool mailingList;

public:
    // argument constructor for CustomerData
    // parameter : the customer's last name
    // parameter : the customer's first name
    // parameter : the customer's address
    // parameter : the city where the customer lives
    // parameter : the state where the customer lives
    // parameter : the zip code of where the customer lives
    // parameter : the customer's phone number
    // parameter : the customer's unique id number
    // parameter : whether the customer is on the mailing list
    CustomerData(string lastName,
		 string firstName,
		 string address,
		 string city,
		 string state,
		 int zip,
		 int phone,
		 int customerNumber,
		 bool mailingList)
    : PersonData(lastName, firstName, address, city, state, zip, phone)
    {
	this->customerNumber = customerNumber;
	this->mailingList = mailingList;
    }

    // accessor for customerNumber
    // return : the customer's unique id number
    int getCustomerNumber() const
    {
	return this->customerNumber;
    }

    // mutator for customerNumber
    // parameter : the customer's new unique id number
    void setCustomerNumber(int customerNumber)
    {
	this->customerNumber = customerNumber;
    }

    // accessor for mailingList
    // return : whether or not the customer is on the mailing list
    bool getMailingList() const
    {
	return this->mailingList;
    }

    // mutator for mailingList
    // parameter : opt-in or opt-out to the mailing list
    void setMailingList(bool mailingList)
    {
	this->mailingList = mailingList;
    }
};
