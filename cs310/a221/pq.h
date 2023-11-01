#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <cassert>
#include <vector>

/**
 * Provide a priority queue implemented on a heap
 * This implementation also provides a field for counting basic operations.
 * Some code provided by Jon Beck
 * @author Karl Ramberg
 * @version 21 February 2020 
 */
class PQ
{
 public:
  /**
   * Construct an empty priority queue
   */
  PQ() : op_count {0} {}

  // disallow both copy constructors and both operator= methods
  PQ(const PQ& pq) = delete;
  PQ(const PQ&& pq) = delete;
  PQ& operator= (const PQ& pq) = delete;
  PQ& operator= (const PQ&& pq) = delete;

  /**
   * Insert a priority into the PQ and count operations
   * @param priority the priority of the inserted job
   */
  void push(unsigned priority)
  {
    array.push_back(priority);
    op_count++; // push_back
    bubble_up();
  }

  /**
   * Remove and return the maximum-priority job in the queue while counting
   * basic operations
   * @return the priority of the removed job
   */
  unsigned pop()
  {
    assert(array.size() != 0);
    op_count++; // assert
    unsigned popped_value = array.front();
    op_count++; // assignment
    array.front() = array.back();
    op_count++; // assignment
    array.pop_back();
    op_count++; // pop_back
    percolate_down();
    return popped_value; 
  }

  /**
   * Report if the queue is empty
   * @return true if empty, false otherwise
   */
  bool is_empty() const
  {
    return array.empty();
  }

  /**
   * Return the number of basic operations counted so far
   * @return the count of basic operations
   */
  size_t get_op_count() const
  {
    return op_count;
  }

  /**
   * Reset the basic operations counter
   */
  void reset_op_count()
  {
    op_count = 0;
  }
      
 private:
  std::vector<unsigned> array;
  size_t op_count;

  /**
   * Sort the newest node by swapping with any larger parents
   */
  void bubble_up()
  {
    size_t bubble_index = array.size() - 1;
    op_count += 2; // arithmatic and assignment
    size_t parent = (bubble_index - 1) / 2;
    op_count += 3; // 2 arthmatic and assignment
    while (bubble_index != 0 && array.at(bubble_index) > array.at(parent))
    {
      op_count += 3; // while loop
      std::swap(array.at(bubble_index), array.at(parent));
      op_count += 2; // swap
      bubble_index = parent;
      op_count++;
      parent = (bubble_index - 1) / 2;
      op_count += 3; // 2 arithmatic and assignment
    }
    op_count += 3; // end while
  }

  /**
   * Re-sort the root node
   */
  void percolate_down()
  {
    size_t percolate_index = 0;
    op_count++; // assignment
    bool in_place = false;
    op_count++; // assignment
    while (!in_place)
    {
      op_count++; // while loop
      size_t left_child = 2 * percolate_index + 1;
      op_count += 3; // 2 arthmatic and assignment
      size_t right_child = 2 * percolate_index + 2;
      op_count += 3; // 2 arthmatic and assignment
      if (right_child < array.size()) // has two children
      {
        op_count++; // if statement
        size_t larger_child = array.at(left_child) > array.at(right_child) ?
          left_child : right_child;
        op_count += 2; // comparison and assignment

        if (array.at(larger_child) > array.at(percolate_index))
        {
          std::swap(array.at(percolate_index), array.at(larger_child));
          op_count += 2; // swap
          percolate_index = larger_child;
          op_count++; // assignment
        }
        else
        {
          in_place = true;
          op_count++; // assignment
        }
        op_count++; // if statement
      }
      else if (left_child < array.size()) // has only one child
      {
        op_count += 2; // else if
        if (array.at(left_child) > array.at(percolate_index))
        {
          std::swap(array.at(percolate_index), array.at(left_child));
          percolate_index = left_child;
          op_count++; // assignment
        }
        else
        {
          in_place = true;
        }
        op_count++; // if statement
      }
      else // has no children
      {
        op_count += 3; // else
        in_place = true;
        op_count++; // assignment
      }
    }
    op_count++; // end while
  }
};
#endif
