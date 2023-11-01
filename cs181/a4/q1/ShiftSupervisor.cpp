#include"Employee.cpp"

using namespace std;

class ShiftSupervisor : public Employee
{
private:
    int salary;
    int bonus; 

public:
    // argument constructor for ShiftSupervisor
    // parameter : the new supervisor's name
    // parameter : the new supervisor's number
    // parameter : the date the new supervisor was hired
    // parameter : the new supervisor's starting salary
    // parameter : the new supervisor's starting bonus
    ShiftSupervisor(string name,
		    int number,
		    long hireDate,
		    int salary,
		    int bonus) : Employee(name, number, hireDate)
    {
	this->salary = salary;
	this->bonus = bonus;
    }

    // accessor for salary
    // return : the supervisor's current salary
    int getSalary() const
    {
	return this->salary;
    }

    // mutator for salary
    // paramter : the supervisor's new salary
    void setSalary(int salary)
    {
	this->salary = salary;
    }

    // accessor for bonus
    // return : the supervisor's current bonus
    int getBonus() const
    {
	return this->bonus;
    }

    // mutator for bonus
    // paramter : the supervisor's new bonus
    void setBonus(int bonus)
    {
	this->bonus = bonus;
    }
};


