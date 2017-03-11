/**
* Assignment 3a EECE 2560													Ningfang Mi
* March 19, 2016															ningfang@ece.neu.edu
* Malcolm Leclair & Erik Gentile
*
* Declaration of card class and functions. Contains prototypes for constructor,
* setValue, setSuit, getValue, getSuit and  overloaded << operator,
**/

#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>


using namespace std;


class dictionary
{
private:
	//dictionary vector
	vector<string> wordList;

public:

	// default constructor for dictionary
	dictionary();

	// loads dictionary into vector
	void loadDictionary(const string &filename);

	//overloaded output operator to print word list
	friend ostream& operator<<(ostream& os, const dictionary &dict); //, vector<string> dictVector);

	// sorts words using selectionsort
	void sortDict();

	//swaps two elements in the wordList at the given indeces
	void swap(const int &first, const int &second);

	// Word lookup via binary search
	//void wordLookup(? ? ? );

};

#endif
