// Karl Ramberg
// Computes multiple invoices for phone plans, given the correct data
#include <iostream>
using namespace std;
int main()
{

  bool running = true;
  do
  {
    cout << "Choose a plan (A, B, or C) or Q to quit: ";
    char plan;
    cin >> plan;

    while (plan != 'A' && plan != 'B' && plan != 'C' && plan != 'Q')
    {
      cout << "Invalid choice. Please re-enter: ";
      cin >> plan;
    }

    double base_cost = 0.00;
    double total = 0.00;

    if (plan == 'A' || plan == 'B')
    {
      cout << "How many gigs data? ";
      double gigabytes_used;
      cin >> gigabytes_used;

      while (gigabytes_used < 0.0)
      {
        cout << "Data usage cannot be negative. Please re-enter: ";
        cin >> gigabytes_used;
      }

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
        total += (gigabytes_used - gigabyte_limit) * overage_charge;
      }
    }
    else if (plan == 'C')
    {
      base_cost = 69.99;
    }
    else // must be 'Q'
    {
      running = false;
    }

    if (running)
    {
      total += base_cost;
      cout << "Invoice total: " << total << endl << endl;
    }
  } while (running);
  return 0;
}
