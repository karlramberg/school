//  A program to allocate and intialize memory as specified by Jon Beck
//  Written by Karl Ramberg on January 23rd, 2020

#include <iostream>
using namespace std;

/**
 * Produces memory as specified by Jon Beck
 * @param x storage for a passed value
 * @param y reference to a calling-scope variable
 * @return the modified value of y
 */
int foo(int x, int& y);

int main()
{
  int i = 5;
  int j = 10;
  int* k = new int {20};
  int& m = *k;
  int n;

  n = foo(5, j);
  *k *= 2;
  m *= 3;

  cout << "i: " << i << endl;
  cout << "j: " << j << endl;
  cout << "k: " << *k << endl;
  cout << "m: " << m << endl;
  cout << "n: " << n << endl;

  delete k;
  return 0;
}

int foo(int x, int& y)
{
  int* z = new int {15};

  x = -x;
  y--;
  *z *= 2;

  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "z: " << *z << endl;

  delete z;
  return y;
}
