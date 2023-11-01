#include"Rectangle.cpp"
#include"Circle.cpp"
#include<iostream>

using namespace std;

int main()
{
    cout << "Enter some information about a circle." << endl;

    long centerX;
    cout << "x-coordinate: ";
    cin >> centerX;

    long centerY;
    cout << "y-coordinate: ";
    cin >> centerY;

    double radius;
    cout << "radius: ";
    cin >> radius;
    
    Circle circle(centerX, centerY, radius);
    cout << "That circle has an area of " << circle.getArea() << endl << endl;

    cout << "Enter some information about a rectangle." << endl;
    
    long width;
    cout << "width: ";
    cin >> width;

    long length;
    cout << "length: ";
    cin >> length;

    Rectangle rectangle(width, length);
    cout << "That rectangle has an area of " << rectangle.getArea() << endl;

    return 0;
}
