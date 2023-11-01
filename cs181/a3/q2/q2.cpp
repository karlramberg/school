#include"DayOfYear.cpp"
#include<iostream>

using namespace std;

int main()
{
    DayOfYear day("January", 1);
    day = DayOfYear("June", 30);
    day = DayOfYear("October", 31);
    day = DayOfYear("February", 30);
}
