// A program to display the contently of a binary inventory data file
// Jon Beck
// 2 December 2018

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const unsigned short CODE_SIZE = 5;

struct Part
{
  char code [CODE_SIZE];
  unsigned short quantity;
  unsigned short max_quantity;
};

int main()
{
  const unsigned NUMBER_OF_RECORDS = 14;
  const unsigned DISPLAY_WIDTH = 5;
  fstream file;
  file.open("inventory.dat", ios::in | ios::binary);
  file.seekg(0);

  for(unsigned count = 0; count < NUMBER_OF_RECORDS; count++)
  {
    Part part;
    file.read(reinterpret_cast<char *>(&part), sizeof part);
    cout << right << setw(DISPLAY_WIDTH) << count <<
      setw(DISPLAY_WIDTH) << part.code <<
      setw(DISPLAY_WIDTH) << part.quantity <<
      setw(DISPLAY_WIDTH) << part.max_quantity << endl;
  }

  file.close();
  return 0;
}
