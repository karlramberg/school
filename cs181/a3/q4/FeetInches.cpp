#include<cstdlib>
#include<iostream>

using namespace std;

class FeetInches
{
private:
	int feet;
	int inches;
	
	// checks for values in the inches member greater than
	// twelve or less than zero. If such a value is found,
	// the numbers in feet and inches are adjusted to conform
	// to a standard feet & inches expression. For example,
	// 3 feet 14 inches would be adjusted to 4 feet 2 inches and
	// 5 feet -2 inches would be adjusted to 4 feet 10 inches.
	void simplify()
	{
		if (this->inches >= 12)
		{
			this->feet += (this->inches / 12);
			this->inches = this->inches % 12;
		}
		else if (this->inches < 0)
		{
			this->feet -= ((abs(this->inches) / 12) + 1);
			this->inches = 12 - (abs(this->inches) % 12);
		}
	}

public:
	
	// argument constructor
	FeetInches(int feet = 0, int inches = 0)
	{ 
		this->feet = feet;
		this->inches = inches;
		simplify();
	}
	
	// copy constructor
	FeetInches(FeetInches& other)
	{
		this->feet = other.feet;
		this->inches = other.inches;
	}

	FeetInches multiply(FeetInches& other)
	{
		FeetInches multiplied(this->feet * other.feet, this->inches * other.inches);
		return multiplied;
	}
		
	// overloaded binary + operator
	FeetInches operator+(const FeetInches &right)
	{
		FeetInches temp;

		temp.inches = inches + right.inches;
		temp.feet = feet + right.feet;
		temp.simplify();
		return temp;
	}


	// overloaded binary - operator
	FeetInches operator-(const FeetInches &right)
	{
		FeetInches temp;

		temp.inches = inches - right.inches;
		temp.feet = feet - right.feet;
		temp.simplify();	
		return temp;
	}

	// overloaded prefix ++ operator, increments inches
	FeetInches operator++()
	{
		++inches;
		simplify();
		return *this;
	}

	// overloaded postfix ++ operator, increaments inches 
	FeetInches operator++(int)
	{
		FeetInches temp(feet, inches);

		inches++;
		simplify();
		return temp;
	}

	// overloaded > operator. returns true if the current object
	// is set to a value greater than that of right
	bool operator>(const FeetInches& right)
	{
		bool status;

		if (this->feet > right.feet)
		{
			status = true;
		}
		else if (this->feet == right.feet && inches > right.inches)
		{
			status = true;
		}
		else
		{
			status = false;
		}

		return status;
	}

	// overloaded >= operator, returns true if the cuurent object
	// is set to a value greater of equal to that of the right
	bool operator>=(const FeetInches& right)
	{
		bool status;

		if(this->feet >= right.feet)
		{
			status = true;
		}
		else if(this->feet == right.feet && inches >= right.inches)
		{
			status = true;
		}
		else
		{
			status = false;
		}

		return status;
	}

	// overloaded < operator. Returns true if the current object
	// is set to a value less than that of right
	bool operator<(const FeetInches& right)
	{
		bool status;

		if(this->feet < right.feet)
		{
			status = true;
		}
		else if(this->feet == right.feet && this->inches < right.inches)
		{
			status = true;
		}
		else
		{
			status = false;
		}

		return status;
	}

	// overloaded ,+ operator. returns true if the current object
	// is set to a value less than or equal to the of right
	bool operator<=(const FeetInches& right)
	{
		bool status;

		if(this->feet <= right.feet)
		{
			status = true;
		}
		else if(this->feet == right.feet && this->inches <= right.inches)
		{
			status = true;
		}
		else
		{
			status = false;
		}

		return status;
	}

	// overloaded == operator. Returns true if the current object
	// is set to a value equal to that of right
	bool operator==(const FeetInches& right)
	{
		bool status;

		if(this->feet == right.feet && this->inches == right.inches)
		{
			status = true;
		}
		else
		{
			status = false;
		}

		return status;
	}

	// overloaded != operator. returns true if the current object
	// is set to a value not equal to that of right
	bool operator!=(const FeetInches& right)
	{
		bool status;

		if(this->feet != right.feet && inches != right.inches)
		{
			status = true;
		}
		else
		{
			status = false;
		}

		return status;
	}

	// converts a FeetInches object to an double
	operator double()
	{
		double temp = this->feet;

		temp += (this->inches / 12.0);
		return temp;
	}

	// converts a FeetInches object to an int
	operator int()
	{ 
		return this->feet; 
	}

	// accessor for feet
	int getFeet() const
	{
		return this->feet;
	}

	// mutator for feet
	void setFeet(int feet)
	{
		this->feet = feet;
	}

	// accessor for inches
	int getInches() const
	{ 
		return this->inches;
	}

	// mutator for inches
	void setInches(int inches)
	{
		this->inches = inches;
		this->simplify();
	}

	// Overloaded << operator. Gives cout the ability to
	// directly display FeetInches objects
	friend ostream& operator<<(ostream& strm, FeetInches& obj)
	{
		// Prompt the user for the feet.
		cout << "Feet: ";
		strm << obj.feet;

		// Prompt the user for the inches.
		cout << "Inches: ";
		strm << obj.inches;

		// Normalize the values.
		obj.simplify();

		return strm;
	}

	// Overloaded >> operator. Gives cin the ability to
	// store user input directly into FeetInches objects
	friend istream& operator>>(istream& strm, FeetInches& obj)
	{
		// Prompt the user for the feet.
		cout << "Feet: ";
		strm >> obj.feet;

		// Prompt the user for the inches.
		cout << "Inches: ";
		strm >> obj.inches;

		// Normalize the values.
		obj.simplify();

		return strm;
	}

};

