// A program to create a binary inventory data file
// Jon Beck
// 2 December 2018

#include <fstream>
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
  vector<Part> parts;

  parts.push_back({"VC2Q",688,710});
  parts.push_back({"NA2G",413,755});
  parts.push_back({"W8CW",132,225});
  parts.push_back({"4E47",212,640});
  parts.push_back({"F5MZ",730,905});
  parts.push_back({"YJTX",54,135 });
  parts.push_back({"A23Z",706,775});
  parts.push_back({"PSTI",390,685});
  parts.push_back({"VXP7",795,815});
  parts.push_back({"QPQR",458,875});
  parts.push_back({"BBKY",51,725 });
  parts.push_back({"HT3R",518,520});
  parts.push_back({"AKZ2",115,550});
  parts.push_back({"QT3E",155,940});

  fstream file;
  file.open("inventory.dat", ios::out | ios::binary);
  file.seekp(0);

  unsigned count = 0;
  for(auto part : parts)
  {
    file.write(reinterpret_cast<char *>(&part), sizeof part);
    count++;
  }

  file.close();
  cout << count << " records written" << endl;
  return 0;
}
