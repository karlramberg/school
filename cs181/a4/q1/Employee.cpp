#include<string>

using namespace std;

class Employee
{
private:
	string name;
	int number;
	long hireDate; //YYYYMMDD
	
public:
	// argument constructor for Employee
	// parameter : name : the new name for the employee
	// parameter : number : the new employee's number
	// parameter : hireDate : the date the new employee was hired, YYYYMMDD
	Employee(string name, int number, long hireDate)
	{
		this->name = name;
		this->number = number;
		this->hireDate = hireDate;
	}

	// accessor for employee's name
   	// return : the current value of name 
	string getName() const
	{
		return this->name;
	}

	// mutator for employee's name
	// parameter : the new value of name 
	void setName(string name)
	{
		this->name = name;
	}

	// accessor for employee's number 
	// return : the current value of number 
	int getNumber() const
	{
		return this->number;
	}
   
	// mutator for employee's number 
	// parameter : the new value of number
	void setNumber(int number)
	{
		this->number = number;
	}

	// accessor for employee's hire date 
	// return : the current value of hire date 
	long getHireDate() const
	{
		return this->hireDate;
	}

	// mutator for employee's hire date 
	// parameter : hireDate : the date the employee was hired, YYYYMMDD
	void setHireDate(long hireDate)
	{
		this->hireDate = hireDate;
	}
};
