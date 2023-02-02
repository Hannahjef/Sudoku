// Puzzle Header File
//  Created by Hannah Jeffi Leo Paul -Student No:2279688 [11/22/2022]
#include <iostream>
#include <string>
const int SIZE = 9;
using namespace std;

class Puzzle
{
private:
   class Square
   {
      /// flag denotes the type of square 'v' - variable 'f' - fixed
      char flag_;
      /// The value stored in the square
      int value_;

   public:
      /// @brief Default constructor of Square Class, it creates an instance of the class
      /// by initializing the value of its private members.
      ///@return void
      Square();

      /// @brief The method sets the value of the private members passed in the parameters
      /// @param anEntry The value to be assigned to the square.
      /// @param flagValue The value of the flag ('v','f')
      void setAll(int anEntry, char flagValue);

      /// @brief The method sets the value to value of the square
      /// @param anEntry the value to be assigned to the square.
      void setValue(int anEntry);

      /// @brief The method returns the value in the Square (0-9)
      /// @return the value
      int getValue() const;

      /// @brief The method sets the flag
      /// @param flagValue The value to be set
      void setFlag(char flagValue);

      /// @brief The method returs the value of the flag
      /// @return a char denoting the flag
      char getFlag() const;

      /// @brief Checks if flag is a variable 'v'
      /// @return true if it is a variable else false
      bool isVariable() const;
   };

private:
   Square grid_[SIZE][SIZE];

   int state_;
   int numberOfVariables_;
   int numOfEmptySquares_;

public:
   /// @brief The default constructor of the Puzzle, it initializes all the data members
   Puzzle();

   /// @brief •	The extraction operator overloading is performed
   /// to extract the input of first 81 number ranging from 0-1 and placing in their corresponding square.
   /// @param is The object of the istream
   /// @param p The address of the puzzle that need to be displayed.
   /// @return the object of the i stream
   friend istream &operator>>(istream &is, Puzzle &p);

   /// @brief •	The insertion overloaded operator calls the solve method and prints the sudoku
   /// in human readable matrix format by arranging in rows and columns if the sudoku
   /// @param os the object of the ostream
   /// @param p The address of the puzzle that need to be displayed
   /// @return the object of the stream
   friend ostream &operator<<(ostream &os, const Puzzle &p);

   /// @brief This method solves the sudoku in recursive backtracking and returns true if solvable else false
   /// @param row The row position
   /// @param column The column position
   /// @return True if solvable else False
   bool solve(int row, int column);

private:
   /// @brief •	This method set the value in the corresponding row and column only if it is legal
   /// (i.e) The row and column does not contain that number and the block does not contain that number. It returns true if the set is successful else false.
   /// @param row The row position
   /// @param column The column position
   /// @param anEntry the value to be added.
   /// @return True is the value is added else false;
   bool set(int row, int column, int anEntry);

   /// @brief This method return the value present in that corresponding row and value.
   /// @param row The row position
   /// @param column The column position
   /// @return The value present in the row and column
   int get(int row, int column) const;

   /// @brief Return the value of the numOfVariables
   /// @return numOfVariables
   int size() const;

   /// @brief Return the value of the numOfEmptySquares
   /// @return numOfEmptySquares
   int numEmpty() const;

   /// @brief Helper method os set method to check if addition is valid row, column and block wise
   /// @param rowValue The row position
   /// @param columnValue The column position
   /// @param anEntry The value to be added
   /// @return True if valid else False
   bool isValid(int rowValue, int columnValue, int anEntry) const;

   /// @brief Helper method to check if the value is already present in the row
   /// @param rowValue The row position
   /// @param anEntry The value to be checked
   /// @return True if valid (value not present) else False
   bool isRowValid(int rowValue, int anEntry) const;

   /// @brief Helper method to check if the value is already present in the column
   /// @param columnValue The column position
   /// @param anEntry The value to be checked
   /// @return True if valid (value not present) else False
   bool isColumnValid(int columnValue, int anEntry) const;

   /// @brief Helper method to check if the value is already present in the block
   /// @param rowValue The row position
   /// @param columnValue The column position
   /// @param anEntry The value to be checked
   /// @return True if valid (value not present) else False
   bool isBlockValid(int rowValue, int columnValue, int anEntry) const;

   /// @brief Clears the puzzle p by initiating the member variables
   void clear();

   /// @brief Finds the next empty square and alters the value
   /// @param rowValue The value of row
   /// @param columnValue The value of column
   void findNextEmptySquare(int *rowValue, int *columnValue);
};