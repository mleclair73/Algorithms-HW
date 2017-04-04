/**
* Assignment 3a EECE 2560													Ningfang Mi
* March 13, 2016															ningfang@ece.neu.edu
* Malcolm Leclair & Erik Gentile
*
* Implementations of dictionary class and functions. Contains implementations
* for dictionary constructor, size(), at(), loadDictionary(), overloaded
* operator <<, sortDict(), swap(),  and wordLookup().
**/

#include "dictionary.h"
#include "d_except.h"

using namespace std;

// overloaded output operator to print dictionaryList
ostream& operator<<(ostream &os, const dictionary &dict)
{
	// iterates through all strings in dictionary
	for (int i = 0; i < dict.dictionaryList.size(); i++)
	{
		os << dict.dictionaryList.at(i) << endl;
	}

	return os;
}// end operator<<

// overloaded output operator to print dictionaryList
void dictionary::loadDictionary(const string& fileName)
{
	string line;
	ifstream infile;
	infile.open(fileName.c_str());

	// error handling
	if(!infile)
	{
		fileOpenError(fileName.c_str());
		return;
	}

	// push line/word to dictionary
	while(getline (infile, line))
	{
		dictionaryList.push_back(line);
	}
	infile.close();
}// end loadDictionary

// sorts words using selectionsort
void dictionary::sortDict()
{
	int size = dictionaryList.size();
	int min;

	for(int i = 0; i <= (size - 2); i++)
	{
		min = i;

		for(int j = i + 1; j <= (size - 1); j++)
		{
			if((dictionaryList.at(j) < dictionaryList.at(min)) == 1)
			{
				min = j;
			}
		}
		swap(i,min);
	}// end for
}

// swaps two elements in the wordList at the given indices
void dictionary::swap(const int &first, const int &second)
{
	//cout << "swap" << first << ", " << second << endl;
	string temp = dictionaryList[first];
	dictionaryList[first] = dictionaryList[second];
	dictionaryList[second] = temp;
}// end sortDict

// binary search for a target puzzleWord between two indies
int dictionary::wordLookup(string puzzleWord, int indexLow, int indexHigh)
 {
	 int index = floor((indexLow + indexHigh) / 2);

	 // while indexHigh greater than indexLow
	 while (indexLow <= indexHigh)
	 {
		 if (dictionaryList[index] == puzzleWord)
		 {
			 return index;
		 }

		 else if (puzzleWord < dictionaryList[index])
		 {
			indexHigh = index - 1;
			return wordLookup(puzzleWord, indexLow, indexHigh);
		 }

		 else
		 {
			 indexLow = index + 1;
			 return wordLookup(puzzleWord, indexLow, indexHigh);
		 }

	 }// end while
	 return -1;
 }// end wordLookup()

 void dictionary::quickSort(const int &left, const int &right)
 {
	 //cout << "quicksorting" << endl;
	 if(left < right)
	 {
		 int p = partition(left,right);
		 quickSort(left, p - 1);
		 quickSort(p + 1, right);
	 }
 }

int dictionary::partition(const int &lo, const int &hi)
{
	//set pivot
	string x = dictionaryList.at(hi);
	//initalize i
	int i = lo - 1;

	for(int j = lo; j <= hi-1; j++)
	{

		if(dictionaryList.at(j) <= x)
		{
			i = i + 1;
			swap(i, j);
		}
	}
	swap(i + 1, hi);
	return (i + 1);
}
