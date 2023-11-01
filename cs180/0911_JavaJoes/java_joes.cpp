// Karl Ramberg
// Creates an invoice for Java Joe's online coffee shop

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
  const double COLOMBIAN_UNIT_PRICE = 0.35;
  const double DECAF_UNIT_PRICE = 0.85;
  const double CHAI_UNIT_PRICE = 1.1;

  const unsigned int MIN_BONUS_DISCOUNT = 1;
  const unsigned int MAX_BONUS_DISCOUNT = 5;

  cout << "Welcome to Java Joe's!" << endl;

  cout << "Enter your name: ";
  string name;
  getline(cin, name);

  cout << "How many ounces of Colombian, Decaf, and Chai? ";
  unsigned int colombian_ounces;
  unsigned int decaf_ounces;
  unsigned int chai_ounces;
  cin >> colombian_ounces >> decaf_ounces >> chai_ounces;

  cout << endl;

  cout << "Java Joe's Invoice for " << name << endl;

  cout << endl;

  cout << setw(16) << "";
  cout << setw(12) << "Colom Supr";
  cout << setw(12) << "Organ Gold";
  cout << setw(12) << "Heavn Chai" << endl;

  cout << setw(16) << "";
  cout << setw(12) << "----------";
  cout << setw(12) << "----------";
  cout << setw(12) << "----------" << endl;

  cout << setw(16) << left << "Quantity (oz)";
  cout << setw(12) << right << colombian_ounces;
  cout << setw(12) << decaf_ounces;
  cout << setw(12) << chai_ounces << endl;

  cout << setw(16) << left << "Unit Price";
  cout << setw(12) << right << fixed << setprecision(2) << COLOMBIAN_UNIT_PRICE;
  cout << setw(12) << fixed << setprecision(2) << DECAF_UNIT_PRICE;
  cout << setw(12) << fixed << setprecision(2) << CHAI_UNIT_PRICE << endl;

  double colombian_total = colombian_ounces * COLOMBIAN_UNIT_PRICE;
  double decaf_total = decaf_ounces * DECAF_UNIT_PRICE;
  double chai_total = chai_ounces * CHAI_UNIT_PRICE;

  cout << setw(16) << left << "Amount";
  cout << setw(12) << right << fixed << setprecision(2) << colombian_total;
  cout << setw(12) << fixed << setprecision(2) << decaf_total;
  cout << setw(12) << fixed << setprecision(2) << chai_total << endl;

  cout << endl;

  double total = colombian_total + decaf_total + chai_total;
  cout << setw(16) << left << "Total";
  cout << setw(12) << right << fixed << setprecision(2) << total << endl;

  unsigned int seed = static_cast<unsigned int>(time(nullptr));
  srand(seed);

  double bonus_discount = -static_cast<double>(rand() % (MAX_BONUS_DISCOUNT - MIN_BONUS_DISCOUNT + 1) + MIN_BONUS_DISCOUNT);
  cout << setw(16) << left << "Bonus Discount";
  cout << setw(12) << right << fixed << setprecision(2) << bonus_discount << endl;

  double grand_total = total + bonus_discount;
  cout << setw(16) << left << "Grand Total";
  cout << setw(12) << right << grand_total << endl;

  cout << endl;

  cout << "Thank you for ordering!";

  return 0;
}
