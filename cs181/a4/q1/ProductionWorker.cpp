#include"Employee.cpp"

class ProductionWorker : public Employee
{
private:
    int shift;
    double hourlyPayRate;

public:
    // argument constructor for ProductionWorker
    // parameter : the new production worker's name
    // paramter : the new production worker's number
    // parameter : the date the new production worker was hired 
    // paramter : the shift the new production worker will start with
    // parameter : the new production worker's starting hourly pay rate
    ProductionWorker(string name,
		     int number,
		     long hireDate,
		     int shift,
		     double hourlyPayRate) : Employee(name, number, hireDate)
    {
	this->shift = shift;
	this->hourlyPayRate = hourlyPayRate;
    }
     
    // argument constructor for ProductionWorker
    // accessor for shift
    // return : the current value of shift (1 or 2, day or night)
    int getShift() const
    {
	return this->shift;
    }

    // mutator for shift
    // parameter : the new value for shift (1 or 2, day or night)
    void setShift(int shift)
    {
	this->shift = shift;
    }

    // accessor for hourlyPayRate
    // return : the current pay per hour of the production worker
    double getHourlyPayRate() const
    {
	return this->hourlyPayRate;
    }

    // mutator for hourlyPayRate
    // paramter : the new pay per hour of the production worker
    void setHourlyPayRate(double hourlyPayRate)
    {
	this->hourlyPayRate = hourlyPayRate;
    }
};
