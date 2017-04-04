/**
* Assignment 3b EECE 2560									Ningfang Mi
* March 22, 2017											ningfang@ece.neu.edu
* Malcolm Leclair & Erik Gentile
*
* Declaration of grid class and functions. Contains
* declarations for grid constructor loadMatrix(),
* overloaded operator<<, and findWords().
**/

#ifndef GRID_H
#define GRID_D

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <string>
#include "d_matrix.h"

using namespace std;

struct gword
{
		string str;
		int x;
		int y;
};// gword struct

class grid
{
private:
	matrix<char> mat;

public:

	// default constructor
	grid();

	// read letters in the grid -- stores them in a matrix
	void loadMatrix(const string &gridname);

	// overloaded operator for
	friend ostream& operator<<(ostream& os, const grid &grd);

	vector<gword> findWords();

}; // grid class

#endif // GRID_H
