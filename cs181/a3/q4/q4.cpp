#include<iostream>
#include"FeetInches.cpp"

using namespace std;

int main()
{
    FeetInches feetInches1(9, 8);
    FeetInches feetInches2(9, 7);
    if(feetInches1 <= feetInches2)
    {
	cout << "feetInches1 is less than or equal to feetInches2" << endl;
    }

    FeetInches feetInches3(9, 10);
    FeetInches feetInches4(9, 9);
    if(feetInches3 >= feetInches4)
    {
	cout << "feetInches3 is greater than or equal to feetInches4" << endl;
    }

    FeetInches feetInches5(1, 1);
    FeetInches feetInches6(1, 2);
    if(feetInches5 != feetInches6)
    {
	cout << "feetInches5 is not equal to feetInches6" << endl;
    }

    FeetInches feetInches7(2, 7);
    FeetInches feetInches8(feetInches7);
    cout << "Original feet: " << feetInches7.getFeet() << endl;
    cout << "Original inches: " << feetInches7.getInches() << endl;
    cout << "Copy feet: " << feetInches8.getFeet() << endl;
    cout << "Copy inches: " << feetInches8.getInches() << endl;

    FeetInches feetInches9(2, 2);
    FeetInches feetInches10(4, 3);
    FeetInches feetInches11;
    feetInches11 = feetInches9.multiply(feetInches10);
    cout << "First original feet: " << feetInches9.getFeet() << endl;
    cout << "First original inches: " << feetInches9.getInches() << endl;
    cout << "Second original feet: " << feetInches10.getFeet() << endl;
    cout << "Second original inches: " << feetInches10.getInches() << endl;
    cout << "Multiplied feet: " << feetInches11.getFeet() << endl;
    cout << "Multiplied inches: " << feetInches11.getInches() << endl;

    return 0;
}
