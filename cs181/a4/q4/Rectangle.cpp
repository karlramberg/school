#include"BasicShape.cpp"

class Rectangle : public BasicShape
{
private:
    long width;
    long length;

public:
    // argument constructor for Rectangle
    // parameter : the width of the rectangle
    // parameter : the length of the rectangle
    Rectangle(long width, long length)
    {
	this->width = width;
	this->length = length;
	calcArea();
    }

    // calculates the rectangle's area
    void calcArea()
    {
	this->setArea(length * width);
    }

    // acccessor for width
    // return : the rectangle's width
    long getWidth() const
    {
	return this->width;
    }

    // accessor for height
    // return : the rectangle's length 
    long getLength() const
    {
	return this->length;
    }
};
