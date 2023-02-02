//  Created by Hannah Jeffi Leo Paul -Student No:2279688 [11/22/2022]
// Puzzle implementation File
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include "Puzzle.h"

using namespace std;

/// @brief Default constructor of Square Class, it creates an instance of the class
/// by initializing the value of its private members.
///@return void
Puzzle::Square::Square()
{
   flag_ = 'n';
   value_ = -1;
}

/// @brief The method sets the value of the private members passed in the parameters
/// @param anEntry The value to be assigned to the square.
/// @param flagValue The value of the flag ('v','f')
void Puzzle::Square::setAll(int anEntry, char flagValue)
{
   value_ = anEntry;
   flag_ = flagValue;
}

/// @brief The method sets the value to value of the square
/// @param anEntry the value to be assigned to the square.
void Puzzle::Square::setValue(int anEntry)
{
   value_ = anEntry;
}

/// @brief The method returs the value of the flag
/// @return a char denoting the flag
void Puzzle::Square::setFlag(char flagValue)
{
   flag_ = flagValue;
}

/// @brief The method returns the value in the Square (0-9)
/// @return the value
int Puzzle::Square::getValue() const
{
   return value_;
}

/// @brief The method returs the value of the flag
/// @return a char denoting the flag
char Puzzle::Square::getFlag() const
{
   return flag_;
}

/// @brief Checks if flag is a variable 'v'
/// @return true if it is a variable else false
bool Puzzle::Square::isVariable() const
{
   return (flag_ == 'v');
}

/// @brief The default constructor of the Puzzle, it initializes all the data members
Puzzle::Puzzle()
{
   numberOfVariables_ = 0;
   numOfEmptySquares_ = 0;
   state_ = 0;
}

/// @brief This method return the value present in that corresponding row and value.
/// @param row The row position
/// @param column The column position
/// @return The value present in the row and column
int Puzzle::get(int row, int column) const
{
   return grid_[row][column].getValue();
}

/// @brief •	This method set the value in the corresponding row and column only if it is legal
/// (i.e) The row and column does not contain that number and the block does not contain that number. It returns true if the set is successful else false.
/// @param row The row position
/// @param column The column position
/// @param anEntry the value to be added.
/// @return True is the value is added else false;
bool Puzzle::set(int row, int column, int value)
{
   if (isValid(row, column, value))
   {
      grid_[row][column].setValue(value);
      return true;
   }
   return false;
}

/// @brief Return the value of the numOfVariables
/// @return numOfVariables
int Puzzle::size() const
{
   return numberOfVariables_;
}

/// @brief Return the value of the numOfEmptySquares_
/// @return numOfEmptySquares_
int Puzzle::numEmpty() const
{
   return numOfEmptySquares_;
}

/// @brief Helper method os set method to check if addition is valid row, column and block wise
/// @param rowValue The row position
/// @param columnValue The column position
/// @param anEntry The value to be added
/// @return True if valid else False
bool Puzzle::isValid(int rowValue, int columnValue, int anEntry) const
{
   return isRowValid(rowValue, anEntry) && isColumnValid(columnValue, anEntry) && isBlockValid(rowValue, columnValue, anEntry);
}

/// @brief Helper method to check if the value is already present in the row
/// @param rowValue The row position
/// @param anEntry The value to be checked
/// @return True if valid (value not present) else False
bool Puzzle::isRowValid(int rowValue, int anEntry) const
{
   for (int columnValue = 0; columnValue < SIZE; columnValue++)
   {
      if (grid_[rowValue][columnValue].getValue() == anEntry)
      {
         return false;
      }
   }
   return true;
}

/// @brief Helper method to check if the value is already present in the column
/// @param columnValue The column position
/// @param anEntry The value to be checked
/// @return True if valid (value not present) else False
bool Puzzle::isColumnValid(int columnValue, int anEntry) const
{
   for (int rowValue = 0; rowValue < SIZE; rowValue++)
   {
      if (grid_[rowValue][columnValue].getValue() == anEntry)
      {
         return false;
      }
   }
   return true;
}

/// @brief Helper method to check if the value is already present in the block
/// @param rowValue The row position
/// @param columnValue The column position
/// @param anEntry The value to be checked
/// @return True if valid (value not present) else False
bool Puzzle::isBlockValid(int rowValue, int columnValue, int anEntry) const
{
   int blockSize = SIZE / 3;
   // Finding Mid Point of block
   int midRow = ((rowValue / blockSize) * blockSize) + 1;
   int midColumn = ((columnValue / blockSize) * blockSize) + 1;

   // Looping from one row and one colummn before be mid point to one row one column after the midpoint
   for (int row = midRow - 1; row <= midRow + 1; row++)
   {
      for (int column = midColumn - 1; column <= midColumn + 1; column++)
      {
         if (grid_[row][column].getValue() == anEntry)
         {
            return false;
         }
      }
   }
   return true;
}

/// @brief The extraction operator overloading is performed
/// to extract the input of first 81 number ranging from 0-1 and placing in their corresponding square.
/// @param is The object of the istream
/// @param p The address of the puzzle that need to be displayed.
/// @return the object of the i stream
istream &operator>>(istream &is, Puzzle &p) // check with input , exception handling while input is not correct and check for othrt input
{
   // Clearing the contents of Puzzle p if it contains some value
   p.clear();

   char input;
   int sizeOfValidInput = 0;
   int row = 0;
   int column = 0;

   // Reading bit by bit untill we get 81 digits
   while (sizeOfValidInput < 81)
   {
      cin >> input;

      if (isdigit(input))
      {
         int tempData = input - 48;

         if (tempData == 0)
         {
            p.numberOfVariables_++;
            p.numOfEmptySquares_++;
         }
         p.grid_[row][column].setAll(tempData, (tempData != 0 ? 'f' : 'v'));

         // Incrementing row,column and sizeOfValidinpt vasslues
         sizeOfValidInput++;
         row = row + ((column + 1) / SIZE);
         column = (column + 1) % (SIZE);
      }
   }
   return is;
}

/// @brief •	The insertion overloaded operator calls the solve method and prints the sudoku
/// in human readable matrix format by arranging in rows and columns if the sudoku
/// @param os the object of the ostream
/// @param p The address of the puzzle that need to be displayed
/// @return the object of the stream
ostream &operator<<(ostream &os, const Puzzle &p)
{
   os << endl
      << "The Sudokku ";
   if (p.state_ == 1 && p.numEmpty() != 0)
   {
      os << "Cannot be solved" << endl;
   }
   os << endl;

   for (int rowValue = 0; rowValue < SIZE; rowValue++)
   {
      for (int columnValue = 0; columnValue < SIZE; columnValue++)
      {
         if ((rowValue == 3 || rowValue == 6) && columnValue == 0)
            os << "---+---+---" << endl;

         os << p.grid_[rowValue][columnValue].getValue();

         if (columnValue == 2 || columnValue == 5)
            os << "|";

         if (columnValue == 8)
            os << endl;
      }
   }
   return os;
}

/// @brief This method solves the sudoku in recursive backtracking and returns true if solvable else false
/// @param row The row position
/// @param column The column position
/// @return True if solvable else False
bool Puzzle::solve(int row, int column)
{
   state_ = 1; // denoting solve has been called atleast once
   if (numOfEmptySquares_ == 0)
   {
      return true;
   }
   findNextEmptySquare(&row, &column); // assignes the next row column value which has empty square
   for (int guess = 1; guess <= 9; guess++)
   {
      if (set(row, column, guess))
      {
         numOfEmptySquares_--;
         if (solve(row + ((column + 1) / SIZE), (column + 1) % (SIZE)))
         {
            return true;
         }
         grid_[row][column].setValue(0);
         numOfEmptySquares_++;
      }
   }
   return false;
}

/// @brief CLears the value in the puzzle object
void Puzzle::clear()
{
   if (grid_[0][0].getValue() == -1)
      return;
   state_ = 0;
   numberOfVariables_ = 0;
   numOfEmptySquares_ = 0;
}

/// @brief Finds the next empty square and alters the value
/// @param rowValue The value of row
/// @param columnValue The value of column
void Puzzle::findNextEmptySquare(int *rowValue, int *columnValue)
{
   int row = *(rowValue);
   int column = *(columnValue);
   // Iterating till i get a non zero or out of bound
   while (!grid_[row][column].isVariable() && row != 9)
   {
      row = row + ((column + 1) / SIZE);
      column = (column + 1) % (SIZE);
   }
   *(rowValue) = row;
   *(columnValue) = column;
}