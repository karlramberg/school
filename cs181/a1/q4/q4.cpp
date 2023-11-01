// Karl Ramberg
// 2-17-19
// CS181 - Assignment 1 - Q4
// A structure manager, allows reading, writing, and modifying
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
 
struct Division 
{
    string name;
    int id;
    double sales;
    int year;
};
 
void readFile(vector<Division> &divs);

void writeDiv(vector<Division> &divs, size_t numOfDivs);

void modifyDiv(vector<Division> &divs);

void getInfo(Division &div);

int main()
{
    fstream file;
    file.open("divisions.dat", ios::in | ios::out | ios::binary);
 
    size_t numOfDivs;
    file.read(reinterpret_cast<char *>(&numOfDivs), sizeof numOfDivs);

    vector<Division> divs;
    for (size_t index = 0; index < numOfDivs; index++)
    {
        Division div;
        file.read(reinterpret_cast<char *>(&div), sizeof div);
        divs.push_back(div);
    }
 
    bool done = false;
    do
    {
	int choice;
	cout << "(1) Read, (2) Write, (3) Modify, or (4) Quit? ";
        cin >> choice;
        if (choice == 1)
        {
            readFile(divs);
        }
        else if (choice == 2)
        {
            writeDiv(divs, numOfDivs);
        }
        else if (choice == 3)
        {
	    modifyDiv(divs);
        }
        else
        {
            done = true;
        }
    } while (!done);
   
    file.seekp(0);
    file.write(reinterpret_cast<char *>(&numOfDivs), sizeof numOfDivs);
 
    for (auto div : divs)
    {
        file.write(reinterpret_cast<char *>(&div), sizeof div);
    }
    
    file.close();
    return 0;
}
 
void readFile(vector<Division> &divs)
{
    cout << "Reading..." << endl;
    cout << endl;
    for (auto div: divs)
    {
	cout << "Name:   " << div.name << endl;
	cout << "ID:     " << div.id << endl;
	cout << "Sales:  $" << div.sales << endl;
	cout << "Year:   " << div.year << endl;
	cout << endl;
    }
}
 
void writeDiv(vector<Division> &divs, size_t numOfDivs)
{
    cout << "Writing..." << endl;
    cout << endl;
    
    Division div;
    getInfo(div);
    
    divs.push_back(div);
    numOfDivs++;
}
 
void modifyDiv(vector<Division> &divs)
{
    int index;
    cout << "Which would you like to modify? ";
    cin >> index; 
    
    cout << endl;

    Division div;
    getInfo(div); 
    
    divs.at(index) = div;
}

void getInfo(Division &div)
{
    cout << "Enter a name: ";
    cin >> div.name;
    while(div.name == "")
    {
	cout << "Cannot have empty name" << endl;
	cout << "Enter a name: ";
	cin >> div.name;
    }

    cout << "Enter an ID: ";
    cin >> div.id;
    while(div.id < 0)
    {
	cout << "ID cannot be negative" << endl;
	cout << "Enter an ID: ";
	cin >> div.id;
    }

    cout << "Enter total sales: ";
    cin >> div.sales;
    while(div.sales < 0.0)
    {
	cout << "Sales cannot be negative" << endl;
	cout << "Enter total sales: ";
	cin >> div.sales;
    }

    cout << "Enter a year: ";
    cin >> div.year;
    while(div.year < 0 || div.year > 2019)
    {
	cout << "Not a valid year" << endl;
	cout << "Enter a year: ";
	cin >> div.year;
    }

    cout << endl;
}
