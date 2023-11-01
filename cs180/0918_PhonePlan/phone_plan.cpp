// Karl Ramberg
// Computes an invoice from a plan and user

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  cout << "Choose the plan (A, B, or C): ";
  char plan;
  cin >> plan;

  double base_cost;

  double total_price = 0.00;

  if (plan == 'C')
  {
    base_cost = 69.99;
  }
  else
  {
    cout << "How many gigs data? ";
    unsigned int gigabytes_used;
    cin >> gigabytes_used;

    double overage_charge;
    unsigned int gigabyte_limit;

    if (plan == 'A')
    {
      base_cost = 39.99;
      overage_charge = 9.99;
      gigabyte_limit = 4;
    }
    else
    {
      base_cost = 59.99;
      overage_charge = 4.99;
      gigabyte_limit = 8;
    }

    if (gigabytes_used > gigabyte_limit)
    {
      total_price += (gigabytes_used - gigabyte_limit) * overage_charge;
    }
  }

  total_price += base_cost;

  cout << "Invoice total: " << fixed << setprecision(2) << total_price;

  return 0;
}
