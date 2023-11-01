// Testing of two seperate partition algorithms for quicksort
// Most code provided by Jon Beck
// Modified by Karl Ramberg 28 February 2020

#include<iostream>
#include<vector>
#include<chrono>
#include<random>
using namespace std;

size_t partition_j(vector<unsigned>& a, size_t lo, size_t hi);
size_t partition_w(vector<unsigned>& a, size_t lo, size_t hi);
size_t partition_k(vector<unsigned>& a, size_t lo, size_t hi);

size_t partition_j(vector<unsigned>& a, size_t lo, size_t hi)
{
  unsigned operations = 0;
  if (lo < hi && hi < a.size())
  {
    unsigned pivot = a.at(lo);
    operations++; // assignment
    size_t position = lo;
    operations++; // assignment
    for (size_t index = lo + 1; index <= hi; index++)
    {
      operations += 2; // for-loop
      if (a.at(index) < pivot)
      {
        position++;
        operations++; // arithmatic
        swap(a.at(position), a.at(index));
        operations += 2; // swap
      }
      operations++; // if comparison
    }
    operations += 2; // for loop exit
    swap(a.at(lo), a.at(position));
    operations += 2; // swap
    cout << operations;
    return position;
  }
  operations += 3; // if comparisons
  cout << operations;
  return lo;
}

size_t partition_w(vector<unsigned>& a, size_t lo, size_t hi)
{
  unsigned operations = 0;
  operations += 4; // if-else comparisons
  if (hi >= a.size() || lo == hi) // out of bounds or singleton
  {
    cout << operations;
    return lo;
  }
  else if (lo + 1 == hi) // only two elements
  {
    if (a.at(lo) > a.at(hi))
    {
      swap(a.at(lo), a.at(hi));
      operations += 2;
    }
    operations++;
    cout << operations;
    return lo;
  }
  else // at least 3 elements
  {
    unsigned pivot = a.at(hi);
    operations++; // assignment
    size_t left = lo;
    operations++; // assignment
    size_t right = hi - 1;
    operations += 2; // arithamtic and assignment

    while (left < right && right < a.size())
    {
      operations += 3; // while-loop
      while (a.at(left) < pivot)
      {
        operations++; // while-loop
        left++;
        operations++; // arithmatic
      }
      operations++; // while-loop end
      while (pivot <= a.at(right) && right > 0)
      {
        operations += 3; // while-loop
        right--;
        operations++; // arithmatic
      }
      operations += 3; // while-loop end
      if (left < right)
      {
        swap(a.at(left), a.at(right));
        operations += 2; // swap
      }
      operations++; // if comparison
    }
    operations += 3; // while-loop end
    swap(a.at(left), a.at(hi));
    operations += 2; // swap
    cout << operations;
    return left;
  }
}

size_t partition_k(vector<unsigned>& a, size_t lo, size_t hi)
{
  unsigned operations = 0;
  if (lo < hi && hi < a.size())
  {
    operations += 3; // if comparisons
    unsigned pivot = a.at(lo);
    size_t position = lo;
    unsigned duplicate_count = 0;
    operations += 3;
    for (size_t index = lo + 1; index <= hi; index++)
    {
      operations += 2;
      if (a.at(index) < pivot)
      {
        position++;
        swap(a.at(position), a.at(index));
        operations += 3;
      }
      else if(a.at(index) == pivot)
      {
        duplicate_count++;
        position++;
        swap(a.at(position), a.at(index));
        swap(a.at(lo + duplicate_count), a.at(position));
        operations += 6;
      }
      operations += 2;
    }
    operations += 2;
    for (size_t count = 0; count <= duplicate_count; count++)
    {
      operations += 2;
      swap(a.at(lo + count), a.at(position - count));
      operations += 4;
    }
    operations += 2;
    cout << operations;
    return position;
  }
  return lo;
}

int main(int argc, char* argv[])
{
  // Check if an argument was passed
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] <<
      " n where n is the number of values" << endl;
    return 1;
  }
  
  // Create a random number generator
  size_t number_of_values {static_cast<size_t>(stoul(argv[1]))};
  const unsigned MAX_RANDOM_VALUE = 1000000;
  default_random_engine get_next_value
    (static_cast <unsigned>
     (chrono::system_clock::now().time_since_epoch().count()));
  uniform_int_distribution<unsigned> uniform(0, MAX_RANDOM_VALUE);

  // Create two indentical vectors of size n
  vector<unsigned> v1;
  vector<unsigned> v2;
  vector<unsigned> v3;
  for(size_t i = 0; i < number_of_values; i++)
  {
    unsigned random_value = uniform(get_next_value);
    v1.push_back(random_value);
    v2.push_back(random_value); 
    v3.push_back(random_value);
  }

  // Run all versions and print how many operations the did
  cout << number_of_values << " ";
  size_t dummy1 = partition_j(v1, 0, static_cast<size_t>(number_of_values - 1));
  cout << " ";
  size_t dummy2 = partition_w(v2, 0, static_cast<size_t>(number_of_values - 1));
  cout << " ";
  size_t dummy3 = partition_k(v3, 0, static_cast<size_t>(number_of_values - 1));
  cout << endl;
}
