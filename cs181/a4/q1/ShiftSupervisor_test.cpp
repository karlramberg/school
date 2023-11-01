#include"ShiftSupervisor.cpp"
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<ShiftSupervisor> supervisors;
   
    bool done = false; 
    while(!done)
    {
	string name;
	cout << "Enter the new supervisor's name: ";
	getline(cin, name);

	int number;
	cout << "Enter their number: ";
	cin >> number;

	string dummy;
	getline(cin, dummy); // consumes newline cin doesn't use

	long hireDate;
	cout << "Enter the date they were hired (YYYMMDD): ";
	cin >> hireDate;

	int salary;
	cout << "Enter their starting salary: ";
	cin >> salary;

	int bonus;
	cout << "Enter their yearly bonus: ";
	cin >> bonus;

	supervisors.emplace_back(name, number, hireDate, salary, bonus);	

	getline(cin, dummy); // consumes newline cin doesn't use

	string answer;
	cout << "Add another supervisor? (q to quit) ";
	getline(cin, answer);
	if(answer == "q")
	{
	    done = true;
	}
    }

    return 0;
}
