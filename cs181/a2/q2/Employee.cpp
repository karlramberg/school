#include<string>

using namespace std;

class Employee {
private:
    string name;
    int idNumber;
    string department;
    string position;

public:
    // full-argument constructor
    // parameter: name - the employee's name
    // parameter: idNumber - the employee's id number
    // parameter: department - the department where the employee belongs
    // parameter: position - the employee's job position
    Employee(string name, int idNumber, string department, string position)
    {
	this->name = name;
	this->idNumber = idNumber;
	this->department = department;
	this->position = position;
    }
    
    // argument constructor with only name and id 
    // parameter: name - the employee's name
    // parameter: idNumber - the employee's id number
    Employee(string name, int idNumber)
    {
	this->name = name;
	this->idNumber = idNumber;
	this->department = "";
	this->position = "";
    }
    
    // default constructor
    Employee()
    {
	this->name = "";
	this->idNumber = 0;
	this->department = "";
	this->position = "";
    }
    
    // gets the name of the employee
    // return: the employee's name
    string getName() const
    {
	return this->name;
    }
    
    // sets the name of the employee 
    // parameter: name - the employee's new name
    void setName(string name)
    {
	this->name = name;
    }
    
    // gets the id of the employee
    // return: the current emplyee's id
    int getIdNumber() const
    {
	return this->idNumber;
    }
    
    // sets the id of the employee
    // parameter: the new employee's id
    void setIdNumber(int idNumber)
    {
	this->idNumber = idNumber;
    }
    
    // gets the department of the employee
    // return: the current department of the employee
    string getDepartment() const
    {
	return this->department;
    }
   
    // sets the department of the employee 
    // parameter: department - the new department for the employee
    void setDepartment(string department)
    {
	this->department = department;
    }
   
    // gets the position of the employee 
    // return: the current positon of the employee
    string getPosition() const
    {
	return this->position;
    }
    
    // set the position of the employee
    // parameter: position - the new position for the employee
    void setPosition(string position)
    {
	this->position = position;  
    }
};
