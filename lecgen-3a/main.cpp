/**
* Assignment 3a EECE 2560											Ningfang Mi
* March 13, 2016										   ningfang@ece.neu.edu
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
void search();

// finds all words in word search
void findMatches(dictionary &dict,grid &g);

void test()
{
	dictionary d;
	string n = "dictionary.txt";
	d.loadDictionary(n);
	d.quickSort(0,d.size()-1);
	cout << d << endl;
	string s = "zymurgy";
	string a = "apple"
	cout << d.wordLookup(s,0,d.size()-1);
	cout << (s < a) << endl;
	cout << (s.c_str() < s.c_str()) << endl;
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
	test();
  return 0;
}// end main function

// finds all words in word search
void findMatches(dictionary &dict, grid &g)
{
	// cout << "finding matches" << endl;
	vector<int> indices;
	vector<int> xs;
	vector<int> ys;
	vector<gword> foundWords;

	// length of dictionary
	int dictionaryLength = dict.size() - 1;
	int index;
	string s;

	// cout << "dict: " << typeid(dict.at(1).c_str()).name() << endl << endl;
	// cout << "words: " << typeid(foundWords[1].str.c_str()).name() << endl;
	// sets foundWords vector equal to result of findWords()

	foundWords = (g.findWords());
	for(int i = 0; i < foundWords.size(); i++)
	{
		//string testWord = foundWords[i].str.c_str();
		int index = dict.wordLookup(foundWords[i].str, 0, dictionaryLength);
		if(index != -1)
		{
			cout << "words: " << typeid(foundWords[i].str.c_str()).name() << endl;
			cout << "dict:  " << typeid(dict.at(index).c_str()).name() << endl;
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
void search()
{

string filename;
cout << "Please enter the name of the grid that you want to solve: ";
cin >> filename;
// prompts for filename of word search to be solved

grid g1;
g1.loadMatrix(filename);
// loads matrix from file


dictionary dictionary1;
string n = "dictionary.txt";

// loads dictionary
dictionary1.loadDictionary(n);

// sorts dictionary alphabetically
//dictionary1.quickSort(0,dictionary1.size()-1);
dictionary1.quickSort(0,dictionary1.size()-1);
// finds all words in word search
findMatches(dictionary1, g1);

} // end search
