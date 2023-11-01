/**
 * Counts the number of collisions when the provided hash function is used
 * @author Karl Ramberg 
 * @version 1 April 2020 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * simple hash function using words
 * @param key the word to hash
 * @param table_size the size of the hash table
 * @return the index in the hash table
 */
size_t hashx(const string& key, size_t table_size);

int main()
{
  const size_t TABLE_SIZE = 2000000;
  vector<bool> used(TABLE_SIZE, false);
  unsigned collisions = 0;
  string word;
  while (getline(cin, word))
  {
    size_t index = hashx(word, TABLE_SIZE);
    !used.at(index) ? used.at(index) = true : collisions++;
    cout << word << endl;
  }
  cout << "Collisions: " << collisions << endl;
  return 0;
}

size_t hashx(const string& key, size_t table_size)
{
  size_t hash_value = 0;
  for (auto character : key)
  {
    hash_value = 37 * hash_value + static_cast<unsigned char>(character);
  }
  return hash_value % table_size;
}
