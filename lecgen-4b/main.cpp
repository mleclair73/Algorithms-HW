/* Erik Gentile and Malcolm Leclair
* Project 4a
* March 30, 2017
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
void readFile(ifstream &fin, string fileName);

int main()
{
    ifstream fin;

    // Read the sample grid from the file.
    string fileName = "sudoku1.txt";
    readFile(fin, fileName);
    cout << "#########################################" << endl;
    fileName = "sudoku2.txt";
    readFile(fin, fileName);
    cout << "#########################################" << endl;
    fileName = "sudoku3.txt";
    readFile(fin, fileName);
}

void readFile(ifstream &fin, string fileName)
{
    cout << fileName << endl;
    fin.open(fileName.c_str());
	// if file cannot open, give error
    if (!fin)
    {
        cerr << "Cannot open " << fileName << endl;
        exit(1);
    }

    try
    {
        board b1(SquareSize);

        while (fin && fin.peek() != 'Z')
        {
            b1.initialize(fin);
            b1.print();
            b1.printConflicts();
			cout << "Is the board solved? 0 for False, 1 for True: ";
			cout << b1.isSolved() << endl;
            b1.clearCell(1,1);					// Clear Cell 1,1 Test
            cout << "Cell 1,1 cleared" << endl;
            b1.print();
            b1.printConflicts();

        }
    }
    catch  (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
    fin.close();
}
