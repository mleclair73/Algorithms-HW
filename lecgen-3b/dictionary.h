/**
* Assignment 3b EECE 2560													Ningfang Mi
* March 22, 2017															ningfang@ece.neu.edu
* Malcolm Leclair & Erik Gentile
*
* Declaration of dictionary class and functions. Contains prototypes for
* dictionary constructor size(), at(), loadDictionary(), overloaded operator <<,
* sortDict(), swap(), binarySearch(), quickSort() and heapSort().
**/

#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>
#include "heap.h"

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

	// binary search for a target puzzleWord between two indices
	int binarySearch(string key, int left, int right);

	// sorts the function using quicksort algorithm
	void quickSort(const int &left, const int &right);

	// splits the subset of the dictionary into two parts, of elements
	// greater/equal to the partiion or less than the partition
	int partition(const int &p, const int &right);

	// sorts dictionary using heapsort
	void heapsort();

};// end dictionary

#endif// end DICTIONARY
