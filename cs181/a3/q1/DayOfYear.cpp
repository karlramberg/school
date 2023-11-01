#include<iostream>
#include<string>

using namespace std;

class DayOfYear
{
private:
    int day;
    const inline static string months[] = {"January", "February", "March",
		    "April", "May", "June",
		    "July", "August", "September",
		    "October", "November", "December"};

    const static inline int monthLengths[] = {31, 28, 31, 30, 31, 30,
			      31, 31, 30, 31, 30, 31};

public:
    // argument constructor for DayOfYear
    // parameter: int, the value for day
    DayOfYear(int day)
    {
	this->day = day;
    }

    // prints the day in date format (eg 30 June)
    void print()
    {
	int daysPassed = 0;
	bool dayFound = false;
	for(int index = 0; index < 12; index++)
	{
	    if(!dayFound && this->day > 0 && this->day < daysPassed + monthLengths[index])
	    {
		cout << to_string(day - daysPassed) << " " << months[index];
		dayFound = true;
	    }
	    else
	    {
		daysPassed += monthLengths[index];
	    }
	}
	if(!dayFound)
	{
	    cout << "not a valid date";
	}
    }
    
    // accessor for day
    // return: int, the current value of day
    int getDay() const
    {
	return this->day;
    }

    // mutator for day
    // parameter: int, the new value for day
    void setDay(int day)
    {
	this->day = day;
    }
};
