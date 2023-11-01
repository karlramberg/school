// Karl Ramberg
// a program for inventory management (and a demonstration of structs)
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Part
{
  string description;
  unsigned current_quantity;
  unsigned min_quantity;
  unsigned max_quantity;
};

// read the database from disk and populate the inventory
// parameter: inventory the inventory of parts
void setup(vector<Part> &inventory);

// run the main menu, repeatedly prompting for input until the user
// chooses to shut down the system
// parameter: inventory the inventory of parts
void main_menu(vector<Part> &inventory);

// you document this function
void shutdown(const vector<Part> &inventory);

// if this part's quantity on hand has fallen below the minimum, re-stock
// the part up to the part's maximum
// parameter: part the part
void restock_if_necessary(Part &part);

// prompt for a numeric value in a range, and accept only values within
// that range (with one exception: if the user enters a string beginning
// with 'q' or 'Q', then return the value one larger than the maximum)
// parameter: prompt the prompt to show to the user
// parameter: min_value the minimum value to accept
// parameter: max_value the maximum value to accept
// parameter: accept_quit whether or not to accept q
// return: a numeric value between min_value and max_value inclusive
// (except max_value + 1 if the user enters q and q is acceptable)
size_t get_numeric_value(const string &prompt,
                         size_t min_value,
                         size_t max_value,
                         bool accept_quit);

// break a string into tokens on a character delimiter
// parameter: line the string containing tokens and delimiters together
// parameter: delimiter the character on which to split the line
// parameter: tokens a vector to contain the tokens after they have been
// found
void split(const string& line, char delimiter, vector<string>& tokens);

int main()
{
  vector<Part> inventory;
  setup(inventory);
  main_menu(inventory);
  shutdown(inventory);
  return 0;
}

void setup(vector<Part> &inventory)
{
  ifstream csv_inventory;
  csv_inventory.open("inventory.txt");

  string part;
  size_t index = 0;
  while(getline(csv_inventory, part))
  {
    vector<string> tokens;
    split(part, ',', tokens);

    inventory.push_back({tokens.at(0),
                         static_cast<unsigned>(stoi(tokens.at(1))),
                         static_cast<unsigned>(stoi(tokens.at(2))),
                         static_cast<unsigned>(stoi(tokens.at(3)))});

    restock_if_necessary(inventory.at(index));

    index++;
  }
  cout << endl;
}

void main_menu(vector<Part> &inventory)
{
  const unsigned ITEM_WIDTH = 4;
  const unsigned DESCRIPTION_WIDTH = 23;
  const unsigned QTY_WIDTH = 7;
  const unsigned PAD_WIDTH = 2;
  bool done = false;
  while(!done)
  {
    cout << left << setw(ITEM_WIDTH) << "Item" <<
      left << setw(PAD_WIDTH) << " " <<
      left << setw(DESCRIPTION_WIDTH) << "Description" <<
      right << setw(QTY_WIDTH) << "Current" <<
      right << setw(QTY_WIDTH) << "Min" <<
      right << setw(QTY_WIDTH) << "Max" << endl;
    cout <<  setfill('-') <<
      setw(ITEM_WIDTH + PAD_WIDTH + DESCRIPTION_WIDTH + 3 * QTY_WIDTH) <<
      "-" << setfill(' ') << endl;

    unsigned count = 0;
    for(auto item : inventory)
    {
      cout << right << setw(ITEM_WIDTH) << count <<
        left << setw(PAD_WIDTH) << " " <<
        left << setw(DESCRIPTION_WIDTH) << item.description <<
        right << setw(QTY_WIDTH) << item.current_quantity <<
        right << setw(QTY_WIDTH) << item.min_quantity <<
        right << setw(QTY_WIDTH) << item.max_quantity << endl;
      count++;
    }
    cout << endl;
    size_t choice =
      get_numeric_value("Choose item from inventory, q to quit", 0,
                        inventory.size() - 1, true);

    if(choice == inventory.size())
    {
      done = true;
    }
    else
    {
      unsigned amount =
        static_cast<unsigned>
        (get_numeric_value("How many " + inventory.at(choice).description +
                           "s are you using?",
                           1,
                           inventory.at(choice).current_quantity, false));
      inventory.at(choice).current_quantity -= amount;
      restock_if_necessary(inventory.at(choice));
      cout << endl;
    }
  }
}

void shutdown(const vector<Part> &inventory)
{
  ofstream data_file("inventory.txt");
  for(auto item : inventory)
  {
    data_file << item.description << ',' <<
      item.current_quantity << ',' <<
      item.min_quantity << ',' <<
      item.max_quantity << endl;
  }
  data_file.close();
}

void restock_if_necessary(Part &part)
{
  if(part.current_quantity < part.min_quantity)
  {
    cout << "Restocking " << part.description << " adding "
      << part.max_quantity - part.current_quantity << endl;
    part.current_quantity = part.max_quantity;
  }
}

void split(const string& line, char delimiter, vector<string>& tokens)
{
  size_t token_start = 0;
  size_t delim_position = line.find(delimiter);

  while(delim_position != string::npos)
  {
    string token =
      line.substr(token_start, delim_position - token_start);
    tokens.push_back(token);
    delim_position++;
    token_start = delim_position;
    delim_position = line.find(delimiter, delim_position);

    if(delim_position == string::npos)
    {
      token = line.substr(token_start);
      tokens.push_back(token);
    }
  }
}

size_t get_numeric_value(const string &prompt,
                         size_t min_value,
                         size_t max_value,
                         bool accept_quit)
{
  bool done = false;
  size_t value = 0;

  do
  {
    cout << prompt << " (" <<
      min_value << " to " << max_value << "): ";
    string value_string;
    getline(cin, value_string);

    if(isdigit(value_string.at(0)))
    {
      value = static_cast<size_t>(stoul(value_string));
      if(value >= min_value && value <= max_value)
      {
        done = true;
      }
    }
    else if(accept_quit && tolower(value_string.at(0)) == 'q')
    {
      done = true;
      value = max_value + 1;
    }
    if(!done)
    {
      cout << "invalid value; please re-enter" << endl;
    }
  }
  while(!done);
  return value;
}
