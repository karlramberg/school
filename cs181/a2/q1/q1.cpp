#include<iostream>

using namespace std;

class Circle {
private:
    double radius;
    constexpr static double PI = 3.141592654;

public:
    
    // default constructor
    Circle()
    {
	this->radius = 0;
    }
    
    // argument constructor
    // parameter: radius - the radius of the circle to initialize
    Circle(double radius)
    {
	this->radius = radius;
    }
    
    // calculates and returns the area of the circle
    // return: the current area of the circle
    double getArea() const
    {
	return PI * this->radius * this->radius;
    }	
    
    // gets the radius of the circle
    // return: the current radius of the circle
    double getRadius() const
    {
	return this->radius;
    }

    // sets the radius of the circle
    // parameter: radius - the new radius of the circle
    void setRadius(double radius)
    {
	this->radius = radius;
    }
};

int main() {
    const int NUM_OF_CIRCLES = 5;
    
    Circle c1;
    cout << "Circle1 Area: " << c1.getArea() << endl;
        
    Circle c2 = Circle(3.2);
    cout << "Circle2 Area: " << c2.getArea() << endl; 

    Circle circles[NUM_OF_CIRCLES];

    Circle more_circles[NUM_OF_CIRCLES] = {Circle(12.0), 
					   Circle(7.0), 
					   Circle(9.0), 
					   Circle(14.0), 
					   Circle(18.0)};

    for(int index = 0; index < NUM_OF_CIRCLES; index++)
    {
	cout << "Circles[" << index << "] Area: ";
	cout << more_circles[index].getArea() << endl;      
    } 
}

