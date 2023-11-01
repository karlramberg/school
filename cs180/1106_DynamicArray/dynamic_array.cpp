// Karl Ramberg
// a program to demonstrate dynamic array allocation using the heap

#include <iostream>
#include <iomanip>

using namespace std;

// sorts an array using the selection sort algorithm
// parameter: array the array to be sorted
// parameter: size the size of the array
void selection_sort(double array[], size_t size);

// computes the average value in an array
// parameter: array the array of values
// parameter: size the size of the array
// return: the average value of the array elements
double get_array_average(const double array[], size_t size);

int main()
{
    const int MAX_VALUE = 1000000;
    const int MIN_VALUE = -1000000;
    const int DECIMAL_SHIFT = 1000;
    const unsigned COL_WIDTH = 12;
    const unsigned NUM_OF_COL = 5;
    const unsigned THOUSANDTHS = 3;

    cout << "Enter the number of values: ";
    size_t size;
    cin >> size;

    double *values = new double[size];

    srand(static_cast<unsigned>(time(nullptr)));

    // generation
    for (size_t index = 0; index < size; index++)
    {
      values[index] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
      values[index] /= DECIMAL_SHIFT;
    }

    // sorting
    selection_sort(values, size);

    // printing
    cout << right << setprecision(THOUSANDTHS) << fixed;
    unsigned column = 0;
    for (size_t index = 0; index < size; index++)
    {
      cout <<  setw(COL_WIDTH) << values[index];
      column++;

      if(column == NUM_OF_COL)
      {
        cout << endl;
        column = 0;
      }
    }

    cout << endl << "The average value is "
      << get_array_average(values, size) << endl;

    return 0;
}

void selection_sort(double array[], size_t size)
{
  for(size_t select_index = 0; select_index < size - 1; select_index++)
  {
    double smallest_value = array[select_index];
    size_t smallest_index = select_index;
    for(size_t compare_index = select_index + 1;
        compare_index < size;
        compare_index ++)
    {
      if(array[compare_index] < smallest_value)
      {
        smallest_value = array[compare_index];
        smallest_index = compare_index;
      }
    }
    swap(array[smallest_index], array[select_index]);
  }
}

double get_array_average(const double array[], size_t size)
{
  double sum = 0.0;
  for (size_t index = 0; index < size; index++)
  {
    sum += array[index];
  }
  return sum / size;
}
