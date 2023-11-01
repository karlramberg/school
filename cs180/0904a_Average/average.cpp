// Jon Beck
// A program to read five integer data items and compute their average

#include <iostream>
using namespace std;

int main()
{
  const unsigned int NUMBER_OF_VALUES = 5;
  int running_sum = 0;

  int data_value;
  cout << "Please enter the first integer: ";
  cin >> data_value;
  running_sum += data_value;

  cout << "Please enter the second integer: ";
  cin >> data_value;
  running_sum += data_value;

  cout << "Please enter the third integer: ";
  cin >> data_value;
  running_sum += data_value;

  cout << "Please enter the fourth integer: ";
  cin >> data_value;
  running_sum += data_value;

  cout << "Please enter the fifth integer: ";
  cin >> data_value;
  running_sum += data_value;

  double average = static_cast<double>(running_sum) / NUMBER_OF_VALUES;
  cout << "The average of the five values is " << average << endl;
  return 0;
}
