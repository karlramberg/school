#pragma once
class BasicShape
{
private:
    double area;

public:

    // accessor for area
    // return : the shapes area
    double getArea()
    {
	return this->area;
    }

    // mutator for area
    // parameter : the new value for area
    void setArea(double area)
    {
	this->area = area;
    }

    // children should define how to calculate their area    
    virtual void calcArea() = 0;
};
