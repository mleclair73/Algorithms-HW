#include "dictionary.h"
#include "d_except.h"

using namespace std;

dictionary::dictionary()
{

}//end dictionary

ostream& operator<<(ostream &os, const dictionary &dict) //, vector<string> wordList)
{
		for (int i = 0; i < dict.wordList.size(); i++)
	{
		os << dict.wordList.at(i) << endl;
	}

	return os;
}//end operator<<

void dictionary::loadDictionary(const string& fileName)
{
	string line;
	ifstream infile;
	infile.open(fileName.c_str());

	//error handling
	if(!infile)
	{
		fileOpenError(fileName.c_str());
		return;
	}

	//read each line
	int i = 0;
	while(getline (infile, line))
	{
		wordList.push_back(line);
		i++;
	}

	infile.close();

}//end loadDictionary

void dictionary::sortDict()
{
	int size = wordList.size();
	int min;

	for(int i = 0; i <= (size - 2); i++)
	{

		min = i;
		for(int j = i + 1; j <= (size - 1); j++)
		{
			if((wordList.at(j) < wordList.at(min)) == 1)
			{
				min = j;
			}
		}

		swap(i,min);
	}
	// while (count != size) // ??
	// {
	// 	for (int i = 0; i < size; i++)
	// 	{
	// 		if (word1biggerthanword2(dictVector[word1], dictVector[word2]))
	// 		{
	// 			min = word2;
	// 		}
	// 		word1++;
	// 		word2++;
	// 	}
	//
	// 	temp = dictVector[count];
	// 	dictVector[count] = dictVector[min];
	// 	dictVector[min] = temp;
	//
	// 	count++;
	// 	word1 = count;
	// 	word2 = word1 + 1;
	// }

}//end sortDictVector

void dictionary::swap(const int &first, const int &second)
{
	string temp = wordList[first];
	wordList[first] = wordList[second];
	wordList[second] = temp;
}

// bool dictionary::word1biggerthanword2(string string1, string string2)
// {
// 	for (int i = 0; i < string1.length() || i < string2.length(); i++)
// 	{
// 		if (string1[i] < string2[i])
// 		{
// 			return true;
// 		}
//
// 		else if (string1[i] > string2[i])
// 		{
// 			return false;
// 		}
//
// 	}
//
// 	if (string1.length() < string2.length())
// 	{
// 		return true;
// 	}
//
// 	else
// 	{
// 		return false;
// 	}
// }
