#include<string>

using namespace std;

class PersonData
{
private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    int zip;
    long phone;

public:
    // argument constructor for PersonData
    // parameter : the person's last name
    // parameter : the person's first name
    // parameter : the person's address
    // parameter : the city where the person lives
    // parameter : the state where the person lives
    // parameter : the zip where the person lives
    // parameter : the person's phone number
    PersonData(string lastName,
	       string firstName,
	       string address,
	       string city,
	       string state,
	       int zip,
	       long phone)
    {
	this->lastName = lastName;
	this->firstName = firstName;
	this->address = address;
	this->city = city;
	this->state = state;
	this->zip = zip;
	this->phone = phone;
    }

    // accessor for lastName
    // return : the current last name
    string getLastName() const
    {
	return this->lastName;
    }

    // mutator for lastName
    // parameter : the new last name
    void setLastName(string lastName)
    {
	this->lastName = lastName;
    }

    // accessor for firstName
    // return : the current first name
    string getFirstName() const
    {
	return this->firstName;
    }

    // mutator for firstName
    // parameter : the new first name
    void setFirstName(string firstName)
    {
	this->firstName = firstName;
    }

    // accessor for address
    // return : the person's current address
    string getAddress() const
    {
	return this->address;
    }

    // mutator for address
    // parameter : the person's new address
    void setAddress(string address)
    {
	this->address = address;
    }

    // accessor for city
    // return : the current city where the person lives
    string getCity() const
    {
	return this->city;
    }

    // mutator for city
    // parameter : the new city where the person lives
    void setCity(string city)
    {
	this->city = city;
    }

    // accessor for state
    // return : the current state where the person lives
    string getState() const
    {
	return this->state;
    }

    // mutator for state
    // parameter : the new state where the person lives
    void setState(string state)
    {
	this->state = state;
    }

    // accessor for zip
    // return : the person's current zip code
    int getZip() const
    {
	return this->zip;
    }

    // mutator for zip
    // parameter : the person's new zip
    void setZip(int zip)
    {
	this->zip = zip;
    }

    // accessor for phone
    // return : the person's current phone number
    long getPhone() const
    {
	return this->phone;
    }

    // mutator for phone
    // parameter : the person's new phone number
    void setPhone(int phone)
    {
	this->phone = phone;
    }
};
