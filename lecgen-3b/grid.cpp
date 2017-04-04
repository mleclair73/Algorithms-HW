/**
* Assignment 3b EECE 2560									Ningfang Mi
* March 22, 2017											ningfang@ece.neu.edu
* Malcolm Leclair & Erik Gentile
*
* Implementation of grid class and functions. Contains
* implementations for grid constructor loadMatrix(),
* overloaded operator<<, and findWords().
**/


#include "grid.h"

using namespace std;

// default constructor
grid::grid()
{
	mat = matrix<char>(1, 1, 'a');
}

// read letters in the grid -- stores them in a matrix
void grid::loadMatrix(const string &fileName)
{
	int rows, cols;
	string line;
	ifstream infile;
	infile.open(fileName.c_str());

	if(!infile)
	{
		throw fileOpenError(fileName);
		return;
	}
	infile >> rows;
	infile >> cols;
	getline(infile,line);				  // removes line break after rows and cols
	mat.resize(rows,cols);

	int i = 0;
	char letter;

	// while loop reads file into matrix using stringstream
	while(getline (infile, line) && i < rows)
	{
		stringstream letters(line);
		int j = 0;

		//while letters in line
		while(letters && j < cols)
		{
			letters >> letter;
			mat[i][j] = letter;
			j++;
		}// end while letters in line

		i++;
	}//end while file

	infile.close();
}// end loadMatrix()

 // overloaded operator << to output the grid
ostream& operator<<(ostream &os, const grid &g)
{
	for(int i = 0; i < g.mat.rows(); i++)
	{
		for(int j = 0; j < g.mat.cols(); j++)
		{
			os << g.mat[i][j] << " ";
		}
		cout << endl;
	}
	return os;
}// end overloaded operator<< function

 // generates vector of found wordNposn structs
vector<gword> grid::findWords()
{
	vector<gword>wordList;
	string guess;
	string word = "";

	// wordNpos is a structure containing the string of the word found
	// and the starting posn
	gword wordNpos;


	for(int i = 0; i < mat.rows(); i++)
	{
		for(int j = 0; j < mat.cols(); j++)
		{
			for(int length = 5; length <= mat.rows(); length++)
			{
				for(int direction = 0; direction < 8; direction++)
				{
					int x = i;
					int y = j;
					word = "";

					for(int index = 0; index < length; index++)
					{
						//grid wrapping
						if(x >= mat.rows())
						{
							x = 0;
						}

						if(y >= mat.rows())
						{
							y = 0;
						}

						if(x < 0)
						{
							x = mat.rows() - 1;
						}

						if(y < 0)
						{
							y = mat.rows() - 1;
						}

						word += mat[x][y];

						//direction selection
						switch(direction)
						{
							case 0: x++;		// up right diagonal direction
									y++;
							break;

							case 1: x++;		// right direction
							break;

							case 2: x++;		// down right diagonal direction
									y--;
							break;

							case 3: y++;		// up direction
							break;

							case 4: y--;		// down direction
							break;

							case 5: x--;		// up left diagonal direction
									y++;
							break;

							case 6: x--;		// left direction
							break;

							case 7: x--;		// down left direction
									y--;
							break;
						}
					} // end switch

					// store info in struct
					wordNpos.str = word;
					wordNpos.x = i;
					wordNpos.y = j;

					// load wordList vector with wordNpos
					wordList.push_back(wordNpos);
				}
			}
		}
	}

	return wordList;
} // end findWords()
