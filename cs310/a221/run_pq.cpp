// Priority queue testing client 
// Most code provided by Jon Beck
// Written by Karl Ramberg 21 February 2020

#include <cstdlib>
#include <chrono>
#include <iostream>
#include <random>
#include "pq.h"
using namespace std;

int main(int argc, char * argv[])
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] <<
      " n where n is the number of values" << endl;
    return 1;
  }

  size_t number_of_values {static_cast<size_t>(stoul(argv[1]))};

  const unsigned MAX_RANDOM_VALUE = 1000000;
  default_random_engine get_next_value
    (static_cast <unsigned>
     (chrono::system_clock::now().time_since_epoch().count()));
  uniform_int_distribution<unsigned> uniform(0, MAX_RANDOM_VALUE);

  PQ priority_queue;

  for (size_t index = 0; index < number_of_values; index++)
  {
    priority_queue.push(uniform(get_next_value));
  }

  unsigned dummy;
  for (size_t index = 0; index < number_of_values; index++)
  {
    dummy = priority_queue.pop();
  }

  cout << number_of_values << ' ' << priority_queue.get_op_count() << endl;

  return 0;
} 
