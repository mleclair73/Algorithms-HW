/**
 * Assignment 1a EECE 2560											Ningfang Mi
 * January 23, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Declaration of code class functions and variables. Contains declarations for
 * private variables length, range and vcode. Contains declarations for
 * constructors, printVectors, checkCorrect, and checkIncorrect
 **/

#ifndef codeH
#define codeH

#include <stdlib.h>
#include <iostream>
#include <vector>


using namespace std;

class code
{
private:
	int length;
	int range;
	std::vector<int> vcode;

public:

	// Creates code object with an empty vcode vector
	code();

	// Creates a code object with a specified vcode vector (guess)
	code(const std::vector<int> &guess);

	// Creates a code object given a length n and a range m
	code(const int &n, const int &m);

	// Returns the number of elements in guess that are in vcode in the correct
	// position
	int checkCorrect(const code &guess) const;

	// Returns the number of elements in guess that are in vcode in the incorrect
	// position
	int checkIncorrect(const code &guess) const;

	// Returns the value of vcode at an index i
	int getValue(int i) const{ return vcode.at(i); };

	// Prints the elements in vcode up to index length -1
	void printVector() const;

	// Returns the length of the vcode vector
	int getLength() const {return length;};

	// Sets the value of the length member
	void setLength(const int &n){length = n;};
};// end code

#endif
