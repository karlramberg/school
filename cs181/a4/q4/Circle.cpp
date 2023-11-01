#include"BasicShape.cpp"

class Circle : public BasicShape
{
private:
    const double PI = 3.14159;

    long centerX;
    long centerY;
    double radius;

public:
    // argument cosntructor for Circle
    // parameter : the x-coordinate of the circle
    // parameter : the y-coordinate of the circle
    // parameter : the radius of the circle
    Circle(long centerX, long centerY, double radius)
    {
	this->centerX = centerX;
	this->centerY = centerY;
	this->radius = radius;
	calcArea();
    }
   
    // calculates the area of the circle
    void calcArea()
    {
	this->setArea(PI * this->radius * this->radius);
    }

    // accessor for centerX
    // return : the x-coordinate of the circle 
    long getCenterX() const
    {
	return this->centerX;
    }

    // accessor for centerY
    // return : the y-coordinate of the circle
    long getCenterY() const
    {
	return this->centerY;
    }
};


    
