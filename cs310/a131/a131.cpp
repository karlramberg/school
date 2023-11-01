// Program to analyze the complexity of unoptimized bubble sort 
// Some code provided by John Beck
// Written by Karl Ramberg on 03 February 2020

#include<iostream>
#include<chrono>
#include<random>
#include<vector>
using namespace std;

/**
 * bubble_sort bubble sorts an array and counts it's operations for analysis
 * @param array the array to be worked on
 */
void bubble_sort(vector<unsigned>& array);

int main(int argc, char* argv[])
{ 
  // check if the user added an argument
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0]
      << " n where n is the size of the vector to generate" << endl;
    return 1;
  }

  // set up a random number generator
  const unsigned MAX_RANDOM_VALUE = 1000000;
  default_random_engine get_next_value(static_cast<unsigned>(
    chrono::system_clock::now().time_since_epoch().count()));
  uniform_int_distribution<unsigned> uniform(0, MAX_RANDOM_VALUE);

  // fill the vector with random numbers
  size_t array_size = static_cast<size_t>(stoul(argv[1]));
  vector<unsigned> array {}; 
  for (size_t count = 0; count < array_size; count++)
  {
    unsigned random_value = uniform(get_next_value);
    array.push_back(random_value);
    cout << random_value << " ";
  }
  cout << endl;

  // bubble sort the array
  bubble_sort(array);
}

void bubble_sort(vector<unsigned>& array)
{
  unsigned operations = 0;
  for (size_t pass_indx = array.size() - 1; pass_indx > 0; pass_indx--)
  {
    operations += 2;
    for (size_t compare_indx = 0; compare_indx < pass_indx; compare_indx++)
    {
      operations += 2;
      if (array.at(compare_indx) > array.at(compare_indx + 1))
      {
        swap(array.at(compare_indx), array.at(compare_indx + 1));
        operations += 2;
      }
      operations++;
    }
    operations += 2;
  }
  operations +=2;
  cerr << array.size() << " " << operations << endl;
}
