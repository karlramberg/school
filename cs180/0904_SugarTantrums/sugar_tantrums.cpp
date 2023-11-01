// Karl Ramberg
// Given six set of data, computes average sugar intake, average amount of tantrums, and total amount of tantrums

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  const unsigned int NUMBER_OF_KIDS = 6;
  unsigned int running_tantrum_total = 0;
  double running_sugar_total = 0.0;

  // Changing variables to temporarily store input
  string name;
  double sugar;
  unsigned int tantrums;

  cout << "Enter the first subject's data (name sugar tantrums): ";
  cin >> name >> sugar >> tantrums;
  running_sugar_total += sugar;
  running_tantrum_total += tantrums;

  cout << "Enter the second subject's data: ";
  cin >> name >> sugar >> tantrums;
  running_sugar_total += sugar;
  running_tantrum_total += tantrums;

  cout << "Enter the third subject's data: ";
  cin >> name >> sugar >> tantrums;
  running_sugar_total += sugar;
  running_tantrum_total += tantrums;

  cout << "Enter the fourth subject's data: ";
  cin >> name >> sugar >> tantrums;
  running_sugar_total += sugar;
  running_tantrum_total += tantrums;

  cout << "Enter the fifth subject's data: ";
  cin >> name >> sugar >> tantrums;
  running_sugar_total += sugar;
  running_tantrum_total += tantrums;

  cout << "Enter the last subject's data: ";
  cin >> name >> sugar >> tantrums;
  running_sugar_total += sugar;
  running_tantrum_total += tantrums;

  double average_sugar_intake = running_sugar_total / NUMBER_OF_KIDS;
  cout << "Average sugar intake (to the nearest hundredth gram): " << fixed << setprecision(2) << average_sugar_intake << endl;

  double average_tantrum_amount = static_cast<double>(running_tantrum_total) / NUMBER_OF_KIDS;
  cout << "Average number of tantrums (to the nearest tenth): " << fixed << setprecision(1) << average_tantrum_amount <<  endl;

  cout << "Total number of tantrums: " << running_tantrum_total << endl;

  return 0;
}
