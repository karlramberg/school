#include<iomanip>
#include<iostream>
#include"Employee.cpp"

using namespace std;

int main() {
    const unsigned NAME_WIDTH = 15;
    const unsigned ID_WIDTH = 8;
    const unsigned DEPT_WIDTH = 16;
    const unsigned POS_WIDTH = 17;

    Employee e1 = Employee("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee e2 = Employee("Mark Jones", 39119, "IT", "Programmer");
    Employee e3 = Employee("Joy Rogers", 81774, "Manufacturing", "Engineer");
    
    cout << left << setw(NAME_WIDTH) << "NAME"
         << setw(ID_WIDTH) << "ID"
	 << setw(DEPT_WIDTH) << "DEPARTMENT"
	 << setw(POS_WIDTH) << "POSITION" << endl;

     cout << left << setw(NAME_WIDTH) << "------------"
         << setw(ID_WIDTH) << "-----"
	 << setw(DEPT_WIDTH) << "-------------"
	 << setw(POS_WIDTH) << "--------------" << endl;

    cout << left << setw(NAME_WIDTH) << e1.getName()
	 << setw(ID_WIDTH) << e1.getIdNumber()
	 << setw(DEPT_WIDTH) << e1.getDepartment()
	 << setw(POS_WIDTH) << e1.getPosition() << endl;

    cout << left << setw(NAME_WIDTH) << e2.getName()
	 << setw(ID_WIDTH) << e2.getIdNumber()
	 << setw(DEPT_WIDTH) << e2.getDepartment()
	 << setw(POS_WIDTH) << e2.getPosition() << endl;

    cout << left << setw(NAME_WIDTH) << e3.getName()
	 << setw(ID_WIDTH) << e3.getIdNumber()
	 << setw(DEPT_WIDTH) << e3.getDepartment()
	 << setw(POS_WIDTH) << e3.getPosition() << endl;
} 
