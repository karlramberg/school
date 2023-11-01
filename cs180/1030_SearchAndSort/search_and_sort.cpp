// Karl Ramberg
// a program to demonstrate searching and sorting

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// opens a file given a name
// parameter: filename a name of a file on disk
// parameter: a file object to read from
void get_input_file(string &filename, ifstream &file);

// searchs an array linearly
// parameter: array the array to search
// parameter: array_size the size of the array to search
// parameter: value the value to search the array for
// return: the index of where the value was found or a not found sentinal
size_t linear_search_array(int array[], size_t array_size, int value);

// searchs a vector with binary search
// parameter: array the array structure to search
// parameter: value the value to search for
// return: the index of where the value was found or a not found sentinal
size_t binary_search_vector(const vector <int> &array, int value);

// sorts an array in ascending order using bubble sort
// parameter: array the array to sort
// parameter: array_size the size of the array to sort
void bubble_sort_array(int array[], size_t array_size);

// sorts a vector in ascending order using selection sort
// parameter: array the array structure to sort
void selection_sort_vector(vector <int> &array);

int main()
{
  const size_t ARRAY_SIZE = 100;
  ifstream data_file;
  string file_name;
  get_input_file(file_name, data_file);

  vector<int> values_v; // a vector of values
  int values_a[ARRAY_SIZE]; // an array of values

  int value;
  size_t value_count = 0;
  while(data_file >> value)
  {
    values_v.push_back(value);
    values_a[value_count] = value;
    value_count++;
  }
  data_file.close();

  bubble_sort_array(values_a, value_count);
  selection_sort_vector(values_v);

  do
  {
    cout << "Enter a value to search for: ";
    cin >> value;
    if (value != 0)
    {
      size_t position = linear_search_array(values_a, value_count, value);
      if (position == value_count)
      {
        cout << "Value was not found in the array" << endl;
      }
      else
      {
        cout << "Value is in the array at position " << position << endl;
      }

      position = binary_search_vector(values_v, value);
      if (position == values_v.size())
      {
        cout << "Value was not found in the vector" << endl;
      }
      else
      {
        cout << "Value is in the vector at position " << position << endl;
      }
    }
  }
  while(value != 0);

  return 0;
}

void get_input_file(string &file_name, ifstream &file)
{
  cout << "Enter a data filename: ";
  cin >> file_name;

  file.open(file_name);

  while(file.fail())
  {
    cout << "Cannot read that file" << endl;
    cout << "Enter a data filename: ";
    cin >> file_name;
    file.open(file_name);
  }
}

size_t linear_search_array(int array[], size_t array_size, int value)
{
  size_t position = array_size;
  bool found = false;

  size_t index = 0;
  while(!found && index < array_size  && array[index] <= value)
  {
    if(array[index] == value)
    {
      found = true;
      position = index;
    }
    index++;
  }
  return position;
}

size_t binary_search_vector(const vector <int> &array, int value)
{
  size_t position = array.size();
  size_t first = 0;
  size_t last = array.size() - 1;

  bool found = false;
  while(!found && first <= last && last << array.size())
  {
    size_t middle = (first + last) / 2;
    if(array.at(middle) == value)
    {
      found = true;
      position = middle;
    }
    else if (array.at(middle) > value)
    {
      last = middle - 1;
    }
    else
    {
      first = middle + 1;
    }
  }
  return position;
}

void bubble_sort_array(int array[], size_t array_size)
{
  for(size_t bubble_index = array_size - 1; bubble_index > 0; bubble_index--)
  {
    for(size_t compare_index = 0;
        compare_index < bubble_index;
        compare_index++)
    {
      if(array[compare_index] > array[compare_index + 1])
      {
        swap(array[compare_index], array[compare_index + 1]);
      }
    }
  }
}

void selection_sort_vector(vector <int> &array)
{
  size_t size = array.size();
  for(size_t select_index = 0; select_index < size - 1; select_index++)
  {
    int smallest_value = array.at(select_index);
    size_t smallest_index = select_index;
    for(size_t compare_index = select_index + 1;
        compare_index < size;
        compare_index ++)
    {
      if(array.at(compare_index) < smallest_value)
      {
        smallest_value = array.at(compare_index);
        smallest_index = compare_index;
      }
    }
    swap(array.at(smallest_index), array.at(select_index));
  }
}
