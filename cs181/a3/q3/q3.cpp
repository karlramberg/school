#include<iostream>

using namespace std;

class ParkingMeter
{
private:
    int purchasedMinutes;

public:
    // argument constructor for ParkingMeter
    // parameter: int, the time in minutes of parking purchased
    ParkingMeter(int purchasedMinutes)
    {
	this->purchasedMinutes = purchasedMinutes;
    }

    // accessor for purchasedMinutes
    // return: int, the current value of purchasedMinutes
    int getPurchasedMinutes() const
    {
	return this->purchasedMinutes;
    }

    // mutator for purchasedMinutes
    // parameter: int, the new value for purchasedMinutes
    void setPurchasedMinutes(int purchasedMinutes)
    {
	this->purchasedMinutes = purchasedMinutes;
    }
};

class ParkedCar
{
private:
    string make;
    string model;
    string color;
    string licenseNumber;
    int minutesParked;

public:
    // the argument constructor for ParkedCar
    // parameter: string, the make of the car
    // parameter: string, the model of the car
    // parameter: string, the color of the car
    // parameter: string, the car's license number
    // parameter: int, the time the car has been parked in minutes
    ParkedCar(string make, string model, string color, string licenseNumber, int minutesParked)
    {
	this->make = make;
	this->model = model;
	this->color = color;
	this->licenseNumber = licenseNumber;
	this->minutesParked = minutesParked;
    }

    // accessor for make
    // return: string, the current value of make
    string getMake() const
    {
	return this->make;
    }

    // mutator for make
    // paramter: string, the new value for make
    void setMake(string make)
    {
	this->make = make;
    }

    // accessor for model
    // return: string, the current value of model
    string getModel() const
    {
	return this->model;
    }

    // mutator for model
    // parameter: string, the new value for model
    void setModel(string model)
    {
	this->model = model;
    }

    // accessor for color
    // return: string, the current value of color
    string getColor() const
    {
	return this->color;
    }

    // mutator for color
    // parameter: string, the new value for color
    void setColor(string color)
    {
	this->color = color;
    }

    // accessor for licenseNumber
    // return: string, the current value of licenseNumber
    string getLiscenceNumber() const
    {
	return this->licenseNumber;
    }

    // mutator for licenseNumber
    // parameter: string, the new value for licenseNumber
    void setLiscenceNumber(string licenseNumber)
    {
	this->licenseNumber = licenseNumber;
    }

    // accessor for minutedParked
    // return: int, the current value of minutesParked
    int getMinutesParked() const
    {
	return this->minutesParked;
    }

    // mutator for minutesParked
    // parameter: int, the new value for minutesParked
    void setMinutedParked(int minutesParked)
    {
	this->minutesParked = minutesParked;
    }
};

class PoliceOfficer
{
private:
    string name;
    int badgeNumber;

public:
    // argument constructor for PoliceOfficer
    // parameter: string, the name of the officer
    // parameter: int, the badge number of the officer
    PoliceOfficer(string name, int badgeNumber)
    {
	this->name = name;
	this->badgeNumber = badgeNumber;
    }
   
    // checks a car for a parking violation
    // parameter: ParkedCar, the car being checked
    // parameter: ParkingMeter, the meter it is parked by
    // return: bool, whether the car is in violation or not 
    bool checkCar(ParkedCar car, ParkingMeter meter)
    {
	if(car.getMinutesParked() > meter.getPurchasedMinutes())
	{
	    return true;
	}
	return false;
    }

    // accessor for name
    // return: string, the current name of the officer
    string getName() const
    {
	return this->name;
    }

    // mutator for name
    // parameter: string, the new name of the officer
    void setName(string name)
    {
	this->name = name;
    }

    // accessor for badgeNumber
    // return: int, the current badge number of the officer
    int getBadgeNumber() const
    {
	return this->badgeNumber;
    }
    
    // mutator for badgeNumber
    // paramter: int, the new badge number for the officer
    void setBadgeNumber(int badgeNumber)
    {
	this->badgeNumber = badgeNumber;
    }
};
class ParkingTicket
{
private:
    ParkedCar* car;
    PoliceOfficer* officer;
    ParkingMeter* meter;

public:
    // argument constructor for ParkingTicket
    // parameter: ParkedCar, the car the ticket is for
    // parameter: PoliceOfficer, the officer who wrote the ticker
    ParkingTicket(PoliceOfficer* officer, ParkedCar* car, ParkingMeter* meter)
    {
	this->car = car;
	this->officer = officer;
	this->meter = meter;
    }
    
    // gets the total fine for the parking violation
    // return: int, the total fine
    int getFineAmount()
    {
	int overtime = this->car->getMinutesParked() - this->meter->getPurchasedMinutes();
	return 25 + 10 * (this->car->getMinutesParked() / 60);
    }

    // accesssor for car
    // return: ParkedCar*, the current car in violation
    ParkedCar* getCar() const
    {
	return this->car;
    }

    // mutator for car
    // parameter: ParkedCar, the new car in violation
    void setCar(ParkedCar car)
    {
	this->car = &car;
    }

    // accessor for officer
    // return: PoliceOfficer*, the current officer who wrote the ticket
    PoliceOfficer* getOfficer() const
    {
	return this->officer;
    }

    // mutator for officer
    // parameter: PoliceOfficer, the new officer who wrote the ticket
    void setOfficer(PoliceOfficer officer)
    {
	this->officer = &officer;
    }

    // accessor for meter
    // parameter: ParkingMeter*, the current pointer to a meter
    ParkingMeter* getMeter() const
    {
	return this->meter;
    }
    
    // mutator for meter
    // parameter: ParkingMeter, the new meter to point to 
    void setMeter(ParkingMeter meter)
    {
	this->meter = &meter;
    }
};

int main()
{
    PoliceOfficer officer("Timmy Tuttle", 270321);
    
    cout << "Enter car's make: ";
    string make;
    getline(cin, make);
 
    cout << "Enter car's model: ";
    string model;
    getline(cin, model);
 
    cout << "Enter car's color: ";
    string color;
    getline(cin, color);
 
    cout << "Enter car's license number: ";
    string licenseNumber;
    getline(cin, licenseNumber);
 
    cout << "Enter car's minutes parked: ";
    int minutesParked;
    cin >> minutesParked;

    ParkedCar car(make, model, color, licenseNumber, minutesParked);

    cout << "Enter the purchased parking time: ";
    int minutesPurchased;
    cin >> minutesPurchased;

    ParkingMeter meter(minutesPurchased);

    if(officer.checkCar(car, meter))
    {
	cout << endl;
	cout << "Car1 is in violation." << endl;
	ParkingTicket ticket =	ParkingTicket(&officer, &car, &meter);
	cout << "Officer: " << officer.getName() << endl;
	cout << "Officer Badge: " << officer.getBadgeNumber() << endl;
	cout << "Car Make: " << car.getMake() << endl;
	cout << "Car Model: " << car.getModel() << endl;
	cout << "Car Color: " << car.getColor() << endl;
	cout << "Car Liscence: " << car.getLiscenceNumber() << endl;
	cout << "Fine Amount: " << ticket.getFineAmount() << endl;
    }
    else
    {
	cout << "Car1 is not in violation." << endl;
    }
}
