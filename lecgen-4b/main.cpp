/* Erik Gentile and Malcolm Leclair
* Project 4a
* April 5, 2017
* Engineering Algorithms
*/

/********************main.cpp**********************
* Contains main file and global board variables.
***************************************************/

#include "board.h"
#include "global.h"

const int Blank = -1;  // Indicates that a cell is blank

const int SquareSize = 3;  //  The number of cells in a small square
                           //  (usually 3).  The board has
                           //  SquareSize^2 rows and SquareSize^2
                           //  columns.

const int BoardSize = SquareSize * SquareSize;

const int MinValue = 1; // MinValue for Numbers in puzzle
const int MaxValue = 9; // MaxValue for Numbers in puzzle

int numSolutions= 0; // number of possible solutions
int readFile(ifstream &fin, string fileName); // solves all puzzles returns
                                              // average iterations required
using namespace std;

int main()
{
    ifstream fin;

    // Read the sample grid from the file.
    string fileName = "sudoku.txt";
    int avg = readFile(fin, fileName);
    cout << "Average #of recursions iterations required to solve a puzzle: " << avg << endl;
}// end main

// reads the file, solves all the puzzles in the board and returns the average
// number of iterations required to solve
int readFile(ifstream &fin, string fileName)
{
    int puzzlesSolved;
    int totalRecursiveCount;
    //cout << fileName << endl;
    fin.open(fileName.c_str());
	// if file cannot open, give error
    if (!fin)
    {
        cerr << "Cannot open " << fileName << endl;
        exit(1);
    }// end if

    try
    {
        board b1(SquareSize);

        while (fin && fin.peek() != 'Z')
        {
            b1.initialize(fin);
            //b1.print();
            b1.solve();
            if (b1.getRecursiveCount() != 0)
            {
                totalRecursiveCount += b1.getRecursiveCount();
                puzzlesSolved += 1;
            }// end if

        }// end while
        return totalRecursiveCount/puzzlesSolved;

    }// end try

    catch  (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }// end catch

    fin.close();
}// end readFile()
