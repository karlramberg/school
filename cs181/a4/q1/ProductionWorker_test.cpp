#include"ProductionWorker.cpp"
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<ProductionWorker> factory;
   
    bool done = false; 
    while(!done)
    {
	string name;
	cout << "Enter the new worker's name: ";
	getline(cin, name);

	int number;
	cout << "Enter their number: ";
	cin >> number;

	string dummy;
	getline(cin, dummy); // consumes newline cin doesn't use

	long hireDate;
	cout << "Enter the date they were hired (YYYYMMDD): ";
	cin >> hireDate;

	int shift;
	cout << "Enter the shift they will be working in: ";
	cin >> shift;

	double hourlyPayRate;
	cout << "Enter their starting hourly pay rate: ";
	cin >> hourlyPayRate;

	factory.emplace_back(name, number, hireDate, shift, hourlyPayRate);	

	getline(cin, dummy); // consumes newline cin doesn't use

	string answer;
	cout << "Add another worker? (q to quit) ";
	getline(cin, answer);
	if(answer == "q")
	{
	    done = true;
	}
    }

    return 0;
}
