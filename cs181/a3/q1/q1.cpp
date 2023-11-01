#include"DayOfYear.cpp"
#include<iostream>

using namespace std;

int main()
{
    DayOfYear day(0);
    cout << "Day " << day.getDay() << " is ";
    day.print();
    cout << endl;
   
    day.setDay(1);
    cout << "Day " << day.getDay() << " is ";
    day.print();
    cout << endl;

    day.setDay(45);
    cout << "Day " << day.getDay() << " is ";
    day.print();
    cout << endl;

    day.setDay(135);
    cout << "Day " << day.getDay() << " is ";
    day.print();
    cout << endl;

    day.setDay(366);
    cout << "Day " << day.getDay() << " is ";
    day.print();
    cout << endl;

    return 0;
}
