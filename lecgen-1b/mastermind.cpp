/**
 * Assignment 1b EECE 2560											Ningfang Mi
 * February 2, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Definition of mastermind class functions. Contains definitions for
 * constructor, print secret, humanGuess, getResponse, isSolved and
 * playGame functions
 **/
#include "mastermind.h"
#include <vector>

mastermind::mastermind()
{
  m = 10;
  n = 5;
}

mastermind::mastermind(const int &n_, const int &m_)
{
  n = n_;
  m = m_;
}

void mastermind::printSecret()
{
  secret.printVector();
}

void mastermind::humanGuess()
{
  int temp;
  std::vector<int> tempvec(secret.getLength(),0);

  // Prompts user for guess code
  for (int i = 0; i < secret.getLength(); i++)
	{
		cout << "Enter a value for position " << i << endl;
		cin >> temp;
		tempvec.at(i) = temp;
	}

  // Stores input values as guess
  guess = code(tempvec);
}

void mastermind::getResponse(const code &g)
{
  // Stores # correct & incorrect in state
  state.setCorrect(secret.checkCorrect(g));
  state.setIncorrect(secret.checkIncorrect(g));
}

bool mastermind::isSolved()
{
  return state == solved;
}

void mastermind::playGame()
{

  secret = code(n, m);
  solved = response(secret.checkCorrect(secret), secret.checkIncorrect(secret));
  printSecret();

  int i = 0;

  //Get up to 10 guesses if correct code is not entered
  while(i < 10 && !isSolved())
  {
    // Prompts user for guess
    humanGuess();

    // Calculates response and prints to console
    getResponse(guess);
    cout << state << endl;
  }

  // Determines if the player has won, and outputs corresponding text
  if(isSolved())
  {
    cout << "You won!" << endl;
  }

  else
  {
    cout << "You lost!!" << endl;
  }
} // end playGame
