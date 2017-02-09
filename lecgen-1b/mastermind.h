/**
 * Assignment 1b EECE 2560											Ningfang Mi
 * February 2, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Declaration of mastermind class functions. Contains declarations for
 * constructor, printSecret, humanGuess, getResponse, isSolved and
 * playGame functions
 **/

#ifndef mastermindH
#define mastermindH

#include "code.h"
#include "response.h"

using namespace std;

class mastermind
{
  private:
    int m;
    int n;
    code secret;
    code guess;
    response state;
    response solved;

  public:

    mastermind(const int &n_, const int &m_);

    mastermind();

    // Prints the secret code
    void printSecret();

    // Reads a guess from the player
    void humanGuess();

    // Evaluates a players guess returning a code object
    void getResponse(const code &g);

    // Returns true if the response indicates the board is solved passed a response
    bool isSolved();

    // Initializes a secret code, prints it, and gets a guess, prints the response
    // continues for 10 turns

    void playGame();

}; // end mastermind

#endif
