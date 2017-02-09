/**
 * Assignment 1a EECE 2560											Ningfang Mi
 * January 23, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Definition of code class functions. Contains definitions for constructors,
 * printVector, checkCorrect, and checkIncorrect
 **/
#include "code.h"

code::code()
{
	std::vector<int> vcode ();

}

code::code(const int &n, const int &m)
{

	length = n;
	range = m;

	// Pushes a random number between (0,m-1) to the vector for a total of n
	// elements

	for (int i = 0; i < n; i++)
	{
		vcode.push_back(rand() % m);
	}

}

code::code(const std::vector<int> &guess)
{
	length = guess.size();
	vcode = guess;
}

void code::printVector() const
{

	// Prints each digit to console
	for (int i = 0; i < length; i++)
	{
		cout << vcode[i] << " ";
	}

	cout << endl;
} // end print

int code::checkCorrect(const code &guess) const
{
	// Compares each position of the two codes and iterates a counter if values
	// are a match

	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if(vcode.at(i) == guess.getValue(i))
		{
			count ++;
		}
	}

	return count;
} // end checkCorrect

int code::checkIncorrect(const code &guess) const
{
	vector<int> guessList(range);
	vector<int> secretList(range);
	int totalShared =0;

	// Returns 0 if length or range is 0 as no matches are possible
	if (range == 0 || length == 0)
	{
		return 0;
	}

	// Iterates through the two codes, creating two vectors containing the number
	// of occurances of each number guessList(i) = n occurances of i in the guess

	for (int i = 0; i < length; i++)
	{
		if (vcode.at(i) <= range)
		{
			secretList.at(vcode.at(i)) += 1;
		}
		if (guess.getValue(i) < range)
		{
			guessList.at(guess.getValue(i)) += 1;
		}
	} // end for

	// Iterates through the range of numbers(the length of the guessList and
	// secretList) and adds the lower of the two (the number shared) to the sum
	// of shared numbers

	for (int i = 0; i < range; i++)
	{
		if(secretList.at(i) <= guessList.at(i))
		{
			totalShared += secretList.at(i);
		}
		else
		{
			totalShared += guessList.at(i);
		}
	} //end for

	// Subtracts the number correct from the total number shared to give the number
	// of shared numbers in the wrong positions

	totalShared -= checkCorrect(guess);

	return totalShared;
} // end checkIncorrect
