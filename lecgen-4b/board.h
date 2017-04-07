/* Erik Gentile and Malcolm Leclair
* Project 4a
* April 5, 2017
* Engineering Algorithms
*/

/********************board.cpp**********************
* Contains board class and class functions declarations.
***************************************************/

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <fstream>
#include <stdlib.h>
#include "global.h"
#include <cmath>

using namespace std;

class board // begin board class
{
public:
	board(int);
	void clear();
	void initialize(ifstream &fin);				// initializes board
	void print();								// prints board
	bool isBlank(int, int);						// is cell blank?
	void setCell(int, int, int);				// sets cell at location to value
	ValueType getCell(int, int);				// retrieves cell contents
	bool isSolved();							// is board solved?
	void updateConflicts(int, int, int);		// updates conflict matrices
	void clearCell(int, int);					// clears cell
	void printConflicts();						// prints conflict matrices
	void updateRowConflicts(int);				// updates row conflicts matrix
	void updatesquareConflicts(int);				// updates cell conflicts matrix
	void updateColConflicts(int);				// updates col conflicts matrix

	void solve();								// solves the board
	int cellConflicts(int x, int y);			// returns the number of conflicts for a
												// cell
	int countConflicts(const matrix<bool> &m, int i);
												// counts the # of true values in the
												// conflict matrix m where row = 0,
												// col = 1 and cell = 2, at matrix
												// index i
	void findBestBlankCell(int &i, int &j);		// finds the cell with the most
												// conflicts
	void findFirstBlankCell(int &i, int &j); 	// finds the first blank cell l->r
												//t->b
	int getRecursiveCount(){return recursiveCount;};
private:

	// The following matrices go from 1 to BoardSize in each
	// dimension, i.e., they are each (BoardSize+1) * (BoardSize+1)
	matrix<bool> rowConflicts;
	matrix<bool> colConflicts;
	matrix<bool> squareConflicts;

	matrix<ValueType> value;
	
	bool solved;
	int recursiveCount;
}; // end board class

#endif
