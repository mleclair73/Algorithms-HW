/**
* Assignment 3b EECE 2560											Ningfang Mi
* March 22, 2017										   ningfang@ece.neu.edu
* Malcolm Leclair & Erik Gentile
*
* Declaration of main function. Also contains declarations
* and implementations for search() and findMatches().
**/

#include "dictionary.h"
#include "grid.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <typeinfo>


using namespace std;

// solves given word search
void search(int n);

// finds all words in word search
void findMatches(dictionary &dict,grid &g);

void test()
{
	dictionary d;
	string n = "mini_dictionary.txt";
	d.loadDictionary(n);
	//d.quickSort(0,d.size()-1);
	d.heapsort();
	cout << d << endl;
	cout << "sorted" << endl;
	string s = "apple";
	string a = "zygote";
	//cout << (d.binarySearch(s,0,d.size()-1))<< endl;
	//cout << (d.binarySearch(a,0,d.size()-1))<< endl;

	// string filename = "input5.txt";
	// grid g1;
	// g1.loadMatrix(filename);
	// // loads matrix from file
	//
	//
	// dictionary dictionary1;
	// string n = "dictionary.txt";
	//
	// // loads dictionary
	// dictionary1.loadDictionary(n);
	// cout << "dict: " << typeid(dictionary1.at(1).c_str()).name() << endl << endl;
	//
	// // sorts dictionary alphabetically
	// dictionary1.quickSort(0,dictionary1.size()-1);
	// cout << "dict post sort: " << typeid(dictionary1.at(1).c_str()).name() << endl << endl;
	//
	// //dictionary1.quickSort(0,dictionary1.size()-1);
	//
	// string apple = "apple";
	// int index = dictionary1.wordLookup(apple.c_str(), 0, dictionary1.size()-1);
	// cout << index << endl;
}

int main()
{
	int n;
	cout << "Which algorithm would you like to use to sort the dictionary?" << endl;
	cout << "Enter 1 for Insertion Sort." << endl;
	cout << "Enter 2 for Quick Sort." << endl;
	cout << "Enter 3 for Heap Sort." << endl;

	cin >> n;

	search(n);
	system("pause");
    return 0;
}// end main function

// finds all words in word search
void findMatches(dictionary &dict, grid &g)
{
	vector<int> indices;
	vector<int> xs;
	vector<int> ys;	vector<gword> foundWords;

	// length of dictionary
	int dictionaryLength = dict.size() - 1;
	int index;

	// sets foundWords vector equal to result of findWords()
	foundWords = (g.findWords());

	for(int i = 0; i < foundWords.size(); i++)
	{
		int index = dict.binarySearch(foundWords[i].str, 0, dictionaryLength);
		if(index != -1)
		{
			indices.push_back(index);				// adds index to indices vector
			xs.push_back(foundWords[i].x);			// adds x to xs vector
			ys.push_back(foundWords[i].y);			// adds y to ys vector
		}
	}

	for(int i = 0; i< indices.size(); i++)
	{
		cout << xs[i] << " " << ys[i] << " " << indices[i]  << " " << dict.at(indices[i]) << endl;
	}
}// end findMatches

// solves given word search
void search(int n)
{

string filename;
cout << "Please enter the name of the grid that you want to solve: ";
cin >> filename;
// prompts for filename of word search to be solved

grid g1;
g1.loadMatrix(filename);
// loads matrix from file


dictionary dictionary1;
string d = "dictionary.txt";

// loads dictionary
dictionary1.loadDictionary(d);

// sorts dictionary alphabetically//

// sort via insertion sort
if (n == 1)
{
	dictionary1.sortDict();
}

// sort via quick sort
if (n == 2)
{
	dictionary1.quickSort(0, dictionary1.size() - 1);
}

// sort via heap sort
if (n == 3)
{
	dictionary1.heapsort();
}

//cout << dictionary1;

//string sorted = "sorted.txt";
//string sorted1 = "sorted_dictionary.txt";
//ofstream myfile;
//myfile.open (sorted.c_str());
//myfile << dictionary1 << endl;
//myfile.close();

//dictionary dictionary2;
//dictionary2.loadDictionary(sorted1);

// finds all words in word search
findMatches(dictionary1, g1);

} // end search
