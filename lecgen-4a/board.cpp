/* Erik Gentile and Malcolm Leclair
* Project 4a
* March 30, 2017
* Engineering Algorithms
* Implementation of Board Class and functions
*/

#include"board.h"

// Overloaded << operator for matrix<bool>
ostream &operator<<(ostream &ostr, matrix<bool> &m)
{
    for(int i = 1; i < m.rows(); i++)
    {
        cout << i << " | ";
        for(int j = 1; j < m.cols(); j++)
            cout << m[i][j] << " ";
        cout << endl;
    }// end for
    cout << endl;
} // &operator<<()

// Board constructor
board::board(int sqSize):value(BoardSize+1,BoardSize+1)
{
    int numVals = MaxValue - MinValue + 1;
    // all conflict mats are 10x10 for 1-9 index
    rowConflicts.resize(BoardSize + 1, numVals + 1);
    colConflicts.resize(BoardSize + 1, numVals + 1);
    cellConflicts.resize(BoardSize + 1, numVals + 1);
    // board size is 10x10 for 1-9 index
    clear();
}// end board()

// Mark all possible values as Blank
void board::clear()
{
    for (int y = 1; y <= BoardSize; y++)
        for (int x = 1; x <= BoardSize; x++)
        {
            value[x][y] = Blank;
        }// end for

    for(int i = 1; i < rowConflicts.rows(); i++)
        for(int val = 1; val < rowConflicts.cols(); val++)
        {
            rowConflicts[i][val] = false;
            colConflicts[i][val] = false;
            cellConflicts[i][val] = false;
        }// end for
}// end clear()

// Read a Sudoku board from the input file.
void board::initialize(ifstream &fin)
{
    char ch;

    clear();

    for (int y = 1; y <= BoardSize; y++)
        for (int x = 1; x <= BoardSize; x++)
        {
            fin >> ch;

            // If the read char is not Blank
            if (ch != '.')
                setCell(x,y,ch-'0');   // Convert char to int
        }// end for
}// end initialize()

// Return the square number of cell i,j (counting from left to right,
// top to bottom.  Note that i and j each go from 1 to BoardSize
int squareNumber(int x, int y)
{
    // Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
    // coordinates of the square that i,j is in.

    return SquareSize * ((x-1)/SquareSize) + (y-1)/SquareSize + 1;
}// end squareNumber()

// Overloaded output operator for vector class.
ostream &operator<<(ostream &ostr, vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        ostr << v[i] << " ";
    ostr << endl;
    return ostr;
}// end &operator<<()

// Returns the value stored in a cell.  Throws an exception
// if bad values are passed.
ValueType board::getCell(int x, int y)
{
    if (x >= 1 && x <= BoardSize && y >= 1 && y <= BoardSize)
        return value[x][y];
    else
        throw rangeError("bad value in getCell");
}// end getCell()

// Returns true if cell i,j is blank, and false otherwise.
bool board::isBlank(int x, int y)
{
    if (x < 1 || x > BoardSize || y < 1 || y > BoardSize)
        throw rangeError("bad value in setCell");

    return (getCell(x,y) == Blank);
}// end isBlank()

// Prints the current board.
void board::print()
{
    for (int i = 1; i <= BoardSize; i++)
    {// end updateCellConflicts
        if ((i-1) % SquareSize == 0)
        {
            cout << " -";
            for (int j = 1; j <= BoardSize; j++)
                cout << "---";
            cout << "-";
            cout << endl;
        }// end if
        for (int j = 1; j <= BoardSize; j++)
        {
            if ((j-1) % SquareSize == 0)
                cout << "|";
            if (!isBlank(j,i))
                cout << " " << getCell(j,i) << " ";
            else
                cout << "   ";
        }//end for
            cout << "|";
            cout << endl;
    }// end for

    cout << " -";
    for (int j = 1; j <= BoardSize; j++)
        cout << "---";
    cout << "-";
    cout << endl;
}// end print()

void board::clearCell(int x, int y)
{

    int curVal = getCell(x, y);
    int sq = squareNumber(x, y);
    if(curVal != Blank)
    {
        cellConflicts[sq][curVal] = false;
        rowConflicts[y][curVal] = false;
        colConflicts[x][curVal] = false;
    }// end if
    setCell(x , y, -1);
}// end clearCell()

// sets the value at the xy position of the grid and updates conflicts
void board::setCell(int x, int y, int val)
{
    value[x][y] = val;
    updateConflicts(x, y, val);

}// end setCell()

//prints all of the three conflict lists
void board::printConflicts()
{
    cout << "Row Conflicts:" << endl << "  | ";

    for(int i = 1; i < rowConflicts.rows(); i++)
        cout << i << " ";
    cout << endl << "----------------------" << endl;
    cout << rowConflicts;

    cout << "Col Conflicts:" << endl << "  | ";
    for(int i = 1; i < rowConflicts.rows(); i++)
        cout << i << " ";
    cout << endl  << "----------------------" << endl;
    cout << colConflicts;

    cout << "Cell Conflicts:" << endl << "  | ";

    for(int i = 1; i < rowConflicts.rows(); i++)
        cout << i << " ";
    cout << endl << "----------------------" << endl;
    cout << cellConflicts;
}// end printConflicts()

void board::updateConflicts(int x, int y, int val)
{
    int cell = squareNumber(x, y);
    int curVal = getCell(x, y);
    if(val != Blank)
    {
        cellConflicts[cell][val] = true;
        rowConflicts[y][val] = true;
        colConflicts[x][val] = true;
    }// end if
    else
    {
        updateRowConflicts(y);
        updateColConflicts(x);
        updateCellConflicts(squareNumber(x,y));
    }// end else
}// end updateConflicts()

// updates the conflicts for all values in a row
void board::updateRowConflicts(int row)
{
    for(int i = 1; i < value.rows(); i++)
        if(getCell(row,i) != -1)
        {
            rowConflicts[row][getCell(row,i)] = true;
        }// end if
}// end updateRowConflicts()

// updates the conflicts for all values in the col
void board::updateColConflicts(int col)
{
    for(int i = 1; i < value.cols(); i++)
        if(getCell(i, col) != -1)
        {
            colConflicts[col][getCell(i,col)] = true;
        }// end if
}// end updateColConflicts()

// updates the conflicts for values in the cell
void board::updateCellConflicts(int cell)
{
    int ox;
    int oy;
    int val;
    switch(cell)
    {
        case 1: ox = 1;
                oy = 1;
                break;
        case 2: ox = 4;
                oy = 1;
                break;
        case 3: ox = 7;
                oy = 1;
                break;
        case 4: ox = 1;
                oy = 4;
                break;
        case 5: ox = 4;
                oy = 4;
                break;
        case 6: ox = 7;
                oy = 4;
                break;
        case 7: ox = 1;
                oy = 7;
                break;
        case 8: ox = 4;
                oy = 7;
                break;
        case 9: ox = 7;
                oy = 7;
                break;
    }// end case
    for(int y = 0; y <SquareSize; y++)
        for(int x = 0; x < SquareSize; x++)
            {
                val = getCell(ox+x, oy+y);
                if(val != Blank)
                    cellConflicts[cell][val] = true;
            }// end for
}// end updateCellConflicts

// is the board solved
bool board::isSolved()
{
    for(int x = 1; x <= BoardSize; x++)
    {
        for(int y = 1; y <=BoardSize; y++)
        {
            if(getCell(x,y) == Blank)
                return false;
        }// end for
    }// end for
    return true;
}// end isSolved()
