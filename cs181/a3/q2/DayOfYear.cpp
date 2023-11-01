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
    
    // argument constructor for DayOfYear
    // parameter: string, month in word form
    // parameter: int, the day of the month (eg. 1-31 for January)
    DayOfYear(string month, int dayOfMonth)
    {
	this->day = 0;
	bool monthFound = false;
	for(int index = 0; index < 12; index++)
	{
	    if(month == months[index])
	    {
		monthFound = true;

		if(dayOfMonth <= monthLengths[index] && dayOfMonth > 0)
		{
		    this->day += dayOfMonth;
		}
		else
		{
		    cout << dayOfMonth << " " << month << " is not a valid date" << endl;
		    exit(0);
		}
	    }
	    else if(!monthFound)
	    {
		this->day += monthLengths[index];
	    }
	}
	cout << dayOfMonth << " " << month << " is Day " << this->day << endl;
    }
    
    // prefix increment operator overloading
    // return: DayOfYear&, reference to the modifyied current object 
    DayOfYear& operator++()
    {
	if(this->day == 365)
	{
	    this->day = 0;
	}
	else
	{
	    this->day++;
	}	    
	return *this;
    }

    // postfix increment operator overloading
    // return: DayOfYear, copy of the previous state of the current object
    DayOfYear operator++(int)
    {
	DayOfYear temp = *this;
	++*this;		    
	return temp;
    }

    // prefix increment operator overloading
    // return: DayOfYear&, reference to the modifieyed current object
    DayOfYear& operator--()
    {
	if(this->day == 1)
	{
	    this->day = 365;
	}
	else
	{
	    this->day--;
	}
	return *this;
    }

    // postfix decrement operator overloaiding
    // return: DayOfYear, copy of the previous state of the current object
    DayOfYear operator--(int)
    {
	DayOfYear temp = *this;
	--*this;
	return temp;
    }

    // print the day in date format - eg '30 June'
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
    // return: day
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
