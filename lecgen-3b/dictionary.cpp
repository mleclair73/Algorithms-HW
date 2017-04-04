/**
* Assignment 3b EECE 2560													Ningfang Mi
* March 22, 2017															ningfang@ece.neu.edu
* Malcolm Leclair & Erik Gentile
*
* Implementations of dictionary class and functions. Contains implementations
* for dictionary constructor, size(), at(), loadDictionary(), overloaded
* operator <<, sortDict(), swap(), binarySearch(), quickSort()
* and heapSort().
**/

#include "dictionary.h"
#include "d_except.h"

using namespace std;

// overloaded output operator to print dictionaryList
ostream& operator<<(ostream &os, const dictionary &dict)
{
	// iterates through all strings in dictionary
	for ( int i = 0; i < dict.dictionaryList.size(); i++)
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
	if (!infile)
	{
		throw fileOpenError(fileName);
		return;
	}

	// push line/word to dictionary
	while (getline(infile, line))
	{
		// remove char from windows linebreak if present
		if (line[line.length() - 1] == '\r')
			line.erase(line.length() - 1);

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
}// end sortDict

// swaps two elements in the wordList at the given indices
void dictionary::swap(const int &first, const int &second)
{
	string temp = dictionaryList.at(first);
	dictionaryList.at(first) = dictionaryList.at(second);
	dictionaryList.at(second) = temp;
}// end sortDict

// binary search for a target puzzleWord between two indies
int dictionary::binarySearch(string key, int left, int right)
{

	while(left <= right)
	{
		int mid = left + ((right - left) / 2);

		// return index if key is found
		if(dictionaryList.at(mid) == key)
		{
			return mid;
		}

		// search the left half of the dictionary
		else if(dictionaryList.at(mid) > key)
		{
			right = mid - 1;
		}

		// search the right half of the dictionary
		else
		{
			left = mid + 1;
		}
	}// end while

	return -1;
}// end binarySearch

// quicksort the dictionary in ascending order
 void dictionary::quickSort(const int &left, const int &right)
 {
	 if(left < right)
	 {
		 int s = partition(left,right);
		 quickSort(left, s - 1);
		 quickSort(s + 1, right);
	}// end if
 }// end quickSort

// helper function for quicksort to divide the dictionary into two
// partitions greater or less than the partition, returns index of
// partition
 int dictionary::partition(const int &p, const int &right)
 {
	 string x = dictionaryList.at(right);
	 int i = p - 1;

	 //move elements into correct partition
	 for(int j = p; j < right; j++)
	 {
		 if(dictionaryList.at(j) <= x)
		 {
			 i++;
			 swap(i,j);
		 }// end if
	 }// end for

	 swap(i + 1, right);
	 return i + 1;
 }// end partition

 void dictionary::heapsort()
 {
	 //heap sort list
	 heap<string> h;
	 h.heapSort(dictionaryList);

	 // fill dictionary with sorted list from sorted heap
	 for (int i = 0; i < dictionaryList.size(); i++)
	 {
		 dictionaryList[i] = h.getItem(i+1);
	 }// end for
 }// end heapsort
