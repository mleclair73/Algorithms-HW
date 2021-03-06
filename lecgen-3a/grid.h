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
};

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

};
