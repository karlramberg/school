// Karl Ramberg
// Computes a circle's diameter, circumference, and area with a given radius
#include <iostream>
using namespace std;

int main()
{
  const double PI = 3.1415;

  // Get a radius from the user
  double radius;
  cout << "Please enter the radius of a circle: ";
  cin >> radius;

  cout << "For a circle with radius " << radius << endl;

  // Calculate and display the diameter
  double diameter = radius * 2.0;
  cout << "The diameter is " << diameter << endl;

  // Calculate and display the circumference
  double circumference = PI * diameter;
  cout << "The circumference is " << circumference << endl;

  // Calculate and display the area
  double area = PI * radius * radius;
  cout << "The area is " << area << endl;

  return 0;
}
