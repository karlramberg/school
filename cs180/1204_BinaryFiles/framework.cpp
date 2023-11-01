// Karl Ramberg
// a program for inventory managment and showcasing binary files

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const unsigned short IDSIZE = 5;

struct Part
{
  char code [IDSIZE];
  unsigned short quantity;
  unsigned short max_quantity;
};

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

// displays a part struct as a string
// parameter: part a part struct
// return a string respresenting the part
string to_string(Part &part);

// prompts for restocking a part
// returns bool for restocking or not
bool prompt_restock();

int main()
{
  const unsigned NUMBER_OF_PARTS = 14;
  fstream file;
  file.open("inventory.dat", ios::in | ios::out | ios::binary);

  bool done = false;
  while(!done)
  {
    size_t choice =
      get_numeric_value("Choose part number or q to quit", 0,
                        NUMBER_OF_PARTS - 1, true);

    if(choice == NUMBER_OF_PARTS)
    {
      done = true;
    }
    else
    {
      Part part;
      file.seekg(static_cast<long>(choice * sizeof part));
      file.read(reinterpret_cast<char *>(&part), sizeof part);
      cout << choice << ' ' << to_string(part) << endl;

      if(prompt_restock())
      {
        cout << "Restocking " << part.code << " adding "
          << part.max_quantity - part.quantity << endl;

        part.quantity = part.max_quantity;

        cout << to_string(part) << endl;

        file.seekp(static_cast<long>(choice * sizeof part));
        file.write(reinterpret_cast<char *>(&part), sizeof part);
      }
    }


  }

  file.close();
  return 0;
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

string to_string(Part &part)
{
  string result = part.code;
  result += " " + to_string(part.quantity);
  result += " " + to_string(part.max_quantity);
  return result;
}

bool prompt_restock()
{
  cout << "Restock? (Y/N) ";
  string choice;
  getline(cin, choice);
  if(choice.at(0) == 'y' || choice.at(0) == 'Y')
  {
    return true;
  }
  return false;
}
