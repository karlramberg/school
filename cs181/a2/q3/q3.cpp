#include"Temperature.cpp"
#include<iostream>

using namespace std;

int main()
{
    Temperature temperature;
    
    int inputTemperature;
    cout << "Enter a temperature: ";
    cin >> inputTemperature; 
    temperature.setTemperature(inputTemperature);

    if(temperature.isEthylFreezing())
    {
	cout << "Ethyl will freeze." << endl;
    }

    if(temperature.isOxygenFreezing())
    {
	cout << "Oxygen will freeze." << endl;
    }
    
    if(temperature.isWaterFreezing())
    {
	cout << "Water will freeze." << endl;
    }

    if(temperature.isEthylBoiling())
    {
	cout << "Ethyl will boil." << endl;
    }

    if(temperature.isOxygenBoiling())
    {
	cout << "Oxygen will boil." << endl;
    }
    
    if(temperature.isWaterBoiling())
    {
	cout << "Water will boil" << endl;
    }
}
