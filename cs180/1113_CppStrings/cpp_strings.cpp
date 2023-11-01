// Karl Ramberg and Isiah Slater
// generates a username file from full names and ids

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// break a string into tokens on a character delimiter
// parameter: line the string containing tokens and delimiters together
// parameter: delimiter the character on which to split the line
// parameter: tokens a vector to contain the tokens after they have been
// found
void split(const string& line, char delimiter, vector<string>& tokens);

int main(int argc, char* argv[])
{
  const unsigned NAME_WIDTH = 24;
  const unsigned USERNAME_WIDTH = 6;

  if (argc != 2)
  {
    cout << "usage: " << argv[0] << " filename" << endl;
    return 1;
  }

  ifstream data_file(argv[1]);
  if(data_file.fail())
  {
    cout << "could not open data file " << argv[1] << endl;
    return 2;
  }

  ofstream username_file("usernames.txt");

  string id_name;
  while(getline(data_file, id_name))
  {
    vector<string> fields;
    split(id_name, ',', fields);

    string fullname = fields.at(2) + ", " + fields.at(1);

    string username;
    username += tolower(fields.at(1).at(0));
    username += tolower(fields.at(2).at(0));
    username += fields.at(0).substr(4, 4);

    username_file << left << setw(NAME_WIDTH) << fullname;
    username_file << setw(USERNAME_WIDTH) << username << endl;
  }

  data_file.close();
  username_file.close();
  return 0;
}

void split(const string& line, char delimiter, vector<string>& tokens)
{
  size_t token_start = 0;

  size_t delim_position = line.find(delimiter);

  while(delim_position != string::npos)
  {
    string token = line.substr(token_start, delim_position - token_start);

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
