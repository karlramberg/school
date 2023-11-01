// Proper header documentation here

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// finds index of a given value
// parameter: ids[] the set of identifications to search
// parameter: space_used the number of elements in use
// parameter: query the value to find in ids[]
// return: the index in ids[] of the query
unsigned find_position (const string ids[],
                        unsigned space_used, string query);

// adds a transaction to an existing total for a customer
// parameter: customer_ids[] the set of customer identification numbers
// parameter: customer_purchases[] a total for each existing customer
// parameter: space_used the number of elements the parallel arrays use
// parameter: customer_id the customer that needs updating
// parameter: purchase_amount the transaction to be added to a total
void update_purchase_info (const string customer_ids[],
                           double customer_purchases[],
                           unsigned space_used,
                           string customer_id,
                           double purchase_amount);

// prints a receipt for each customers total sales
// parameter: customer_purchases[] a total sales for each existing customer
// parameter: customer_names[] the set of each customer's name
// parameter: customer_ids[] the set of customer identification numbers
// parameter: space_used the number of elements the parallel arrays use
void report_sales (const double customer_purchases[],
                   const string customer_names[],
                   const string customer_ids[],
                   unsigned space_used);

// finds id of the highest-totaled customer
// parameter: customer_purchases{} a total sales for each existing customer
// parameter: customer_ids[] the set of customer identification numbers
// parameter: space_used the number of elements the parllel arrays use
// return: the id of the highest-totaled customer
string get_top_customer_id (const double customer_purchases[],
                            const string customer_ids[],
                            unsigned space_used);

int main()
{
  const unsigned MAX_CUSTOMERS = 100;

  string customer_names [MAX_CUSTOMERS];
  string customer_ids [MAX_CUSTOMERS];
  double customer_purchases [MAX_CUSTOMERS];

  ifstream customer_info;
  customer_info.open("customer_info.txt");
  string customer_id;
  unsigned customer_count = 0;

  while (customer_info >> customer_id)
  {
    customer_info.ignore(1); // the space between the id and the name

    string customer_name;
    getline(customer_info, customer_name);

    customer_ids[customer_count] = customer_id;
    customer_names[customer_count] = customer_name;
    customer_purchases[customer_count] = 0.0;
    customer_count++;
  }
  customer_info.close();

  ifstream transaction_info;
  transaction_info.open("september_transactions.txt");

  while (transaction_info >> customer_id)
  {
    double transaction_amount;
    transaction_info >> transaction_amount;

    update_purchase_info(customer_ids, customer_purchases, customer_count,
                         customer_id, transaction_amount);
  }

  report_sales(customer_purchases, customer_names,
               customer_ids, customer_count);

  string top_customer_id =
    get_top_customer_id (customer_purchases, customer_ids, customer_count);

  unsigned top_customer_index =
    find_position(customer_ids, customer_count, top_customer_id);

  cout << "The top seller was " << customer_names[top_customer_index] <<
    " with purchases of " << customer_purchases[top_customer_index] << endl;

  return 0;
}

unsigned find_position (const string customer_ids[],
                        unsigned space_used,
                        string query)
{
  unsigned position = space_used + 1;
  bool found = false;

  unsigned index = 0;
  while(index < space_used && !found)
  {
    if(customer_ids[index] == query)
    {
      found = true;
      position = index;
    }
    index++;
  }
  return position;
}

void update_purchase_info (const string customer_ids[],
                           double customer_purchases[],
                           unsigned space_used,
                           string customer_id,
                           double purchase_amount)
{
  unsigned index = find_position(customer_ids, space_used, customer_id);
  customer_purchases[index] += purchase_amount;
}

void report_sales (const double customer_purchases[],
                   const string customer_names[],
                   const string customer_ids[],
                   unsigned space_used)
{
  const unsigned ID_WIDTH = 6;
  const unsigned NAME_WIDTH = 26;
  const unsigned TOTAL_WIDTH = 7;

  const unsigned CENTS_PLACE = 2;
  cout << fixed << setprecision(CENTS_PLACE);

  cout << left << setw(ID_WIDTH) << " ID"
    << setw(NAME_WIDTH) << "Customer Name"
    << right << setw(TOTAL_WIDTH) << "Total" << endl;

  cout << left << setw(ID_WIDTH) << "----"
    << setw(NAME_WIDTH) << "----------------------"
    << right << setw(TOTAL_WIDTH) << "-------" << endl;

  for(unsigned index = 0; index < space_used; index++)
  {
    cout << left << setw(ID_WIDTH) << customer_ids[index]
      << setw(NAME_WIDTH) << setfill('.') << customer_names[index]
      << right << setw(TOTAL_WIDTH) << setfill(' ')
      << customer_purchases[index] << endl;
  }
}

string get_top_customer_id (const double customer_purchases[],
                            const string customer_ids[],
                            unsigned space_used)
{
  string top_customer;
  double highest_sales = 0.00;

  for(unsigned index = 0; index < space_used; index++)
  {
    if(customer_purchases[index] > highest_sales)
    {
      top_customer = customer_ids[index];
      highest_sales = customer_purchases[index];
    }
  }

  return top_customer;
}
