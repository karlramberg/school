/**
 * sudoku solved by backtracking
 * assumes more than 1 and fewer than 81 lines of input in the form of:
 * row col value
 * where row and col are in the range 0 .. 8 inclusive and value
 * is in the range 1 .. 9 inclusive
 * any row, col combination not initialized by the input is
 * considered blank, and must be solved during the game
 * @author Karl Ramberg
 * @version 04/22/20
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include "matrix.h"
using namespace std;

const unsigned SIZE = 9;
const unsigned SUBSIZE = 3;

/**
 * Output an ASCII art horizontal line with plus signs where columns
 * will intersect
 */
void hr();

/**
 * Output an ASCII art double horizontal line with plus signs where
 * columns will intersect
 */
void hrr();

/**
 * Prints a sudoku sheet to std output
 * @param sheet the sheet whose arrangement to dump
 */
void print_sheet(const Matrix<unsigned>& sheet);

/** Perform recursive backtracking. Cells from 0 through cell - 1 have
 * already been successfully placed.  We are trying to place an item
 * in the next cell.
 * @param cell a cell number between 0 and 80 inclusive
 * @param sheet the sudoku game board
 */
void fill_cell(unsigned cell, Matrix<unsigned>& sheet, unsigned elaborated,
  unsigned dead_ends, unsigned input_size);

/**
 * Checks to see if the value in the indicated cell is ok.  It is ok
 * if the row, column, or 3x3 square the cell is in does not contain
 * more than one copy of the value of the indicated cell.  A return of
 * true means no conflict.  A return of false means at least one
 * conflict.
 * @param cell the cell that just got a value. 0 <= cell < 81
 * @param sheet the current sudoku sheet
 */
bool test(unsigned cell, const Matrix<unsigned>& sheet);

int main()
{
  Matrix<unsigned> sheet(SIZE, SIZE);
  for (unsigned row = 0; row < SIZE; row++)
  {
    for (unsigned col = 0; col < SIZE; col++)
    {
      sheet.at(row, col) = 0;
    }
  }

  // read in a starting arrangement
  unsigned row;
  unsigned col;
  unsigned value;
  unsigned num_seeds = 0;
  while (!cin.eof())
  {
    cin >> row >> col >> value;
    if (!cin.eof())
    {
      sheet.at(row, col) = value;
      num_seeds++;
    }
  }

  // dump the sheet to confirm the starting arrangement
  print_sheet(sheet);

  // start with cell 0
  fill_cell(0, sheet, 0, 0, (SIZE * SIZE) - num_seeds);
  cout << "No solution" << endl;
  exit(1);
}

void hr()
{
  cout << "    ++---+---+---++---+---+---++---+---+---++" << endl;
}

void hrr()
{
  cout << "    ++===+===+===++===+===+===++===+===+===++" << endl;
}

void print_sheet(const Matrix<unsigned>& sheet)
{
  cout << "     ";
  for (unsigned col = 0; col < SIZE; col++)
  {
    if (col % SUBSIZE == 2)
    {
      cout << setw(3) << col << "  ";
    }
    else
    {
      cout << setw(3) << col << " ";
    }
  }
  cout << endl;

  hrr();
  for (unsigned row = 0; row < SIZE; row++)
  {
    cout << ' ' << setw(2) << row << " ||";
    for (unsigned col = 0; col < SIZE; col++)
    {
      if (sheet.at(row, col) != 0)
      {
        cout << setw(2) << sheet.at(row, col);
      }
      else
      {
        cout << "  ";
      }

      if (col % SUBSIZE == 2)
      {
        cout << " ||";
      }
      else
      {
        cout << " |";
      }
    }
    cout << endl;
    if (row % SUBSIZE == 2)
    {
      hrr();
    }
    else
    {
      hr();
    }
  }
  cout << endl;
}

void fill_cell(unsigned cell, Matrix<unsigned>& sheet, unsigned elaborated,
  unsigned dead_ends, unsigned input_size)
{
  // Check if we've reached the end
  if (cell == SIZE * SIZE)
  {
    print_sheet(sheet);
    cout << "Input size: " << input_size << endl;
    cout << "Elaborated: " << elaborated << endl;
    cout << "Dead ends: " << dead_ends << endl;
    exit(0);
  }

  size_t row = cell / SIZE;
  size_t col = cell % SIZE;
  // Check if unsolved
  if (sheet.at(row, col) == 0)
  {
    // Check all 9 possible values (branches)
    for (unsigned value = 1; value <= SIZE; value++)
    {
      sheet.at(row, col) = value;
      elaborated++;
      // Check if sheet is still valid, move on to next cell if so
      if (test(cell, sheet))
      {
        fill_cell(cell + 1, sheet, elaborated, dead_ends, input_size);
      }
      else
      {
        dead_ends++;
      }
    }
    // Reset cell because all 9 branches failed
    sheet.at(row, col) = 0;
  }
  else
  {
    fill_cell(cell + 1, sheet, elaborated, dead_ends, input_size);
  }
}

bool test(unsigned cell, const Matrix<unsigned>& sheet)
{
  size_t row = cell / SIZE;
  size_t col = cell % SIZE;
  unsigned value = sheet.at(row, col);

  // Check if there are duplicates in the row or column
  for (size_t num = 0; num < SIZE; num++)
  {
    if (value == sheet.at(row, num) && num != col)
    {
      return false;
    }
    if (value == sheet.at(num, col) && num != row)
    {
      return false;
    }
  }

  // Check the 4 cells in the same subgrid not checked with row and column
  // Find these by finding the cell's position within the subgrid
  size_t test_row1 = 0;
  size_t test_row2 = 0;
  switch (row % SUBSIZE) {
    case 0:
      test_row1 = row + 1;
      test_row2 = row + 2;
      break;
    case 1:
      test_row1 = row - 1;
      test_row2 = row + 1;
      break;
    case 2:
      test_row1 = row - 2;
      test_row2 = row - 1;
      break;
  }

  size_t test_col1 = 0;
  size_t test_col2 = 0;
  switch (col % SUBSIZE) {
    case 0:
      test_col1 = col + 1;
      test_col2 = col + 2;
      break;
    case 1:
      test_col1 = col - 1;
      test_col2 = col + 1;
      break;
    case 2:
      test_col1 = col - 2;
      test_col2 = col - 1;
      break;
  }

  if (sheet.at(test_row1, test_col1) == value ||
    sheet.at(test_row1, test_col2) == value ||
    sheet.at(test_row2, test_col1) == value ||
    sheet.at(test_row2, test_col2) == value)
  {
    return false;
  }
  
  return true;
}
