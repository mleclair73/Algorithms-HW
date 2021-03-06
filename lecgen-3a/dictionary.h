/**
* Assignment 3a EECE 2560													Ningfang Mi
* March 13, 2016															ningfang@ece.neu.edu
* Malcolm Leclair & Erik Gentile
*
* Declaration of dictionary class and functions. Contains prototypes for
* dictionary constructor size(), at(), loadDictionary(), overloaded operator <<,
* sortDict(), swap(), and wordLookup().
**/

#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;


class dictionary
{
private:
	// vector continaing each word in the dictionary
	vector<string> dictionaryList;


public:
	// access size of the dictionary vector
	int size(){return dictionaryList.size();};

	// access value at index of dictionary vector
	string at(const int &i){return dictionaryList.at(i);};

	// loads dictionary from a file into vector
	void loadDictionary(const string &filename);

	// overloaded output operator to print dictionaryList
	friend ostream& operator<<(ostream& os, const dictionary &dict);

	// sorts words using selectionsort
	void sortDict();

	// swaps two elements in the wordList at the given indices
	void swap(const int &first, const int &second);

	// binary search for a target puzzleWord between two indies
	int wordLookup(string puzzleWord, int indexLow, int indexHigh);

	void quickSort(const int &right, const int &left);

	int partition(const int &lo, const int &hi);
};// end dictionary

#endif
