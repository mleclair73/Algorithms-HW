#include "code.h"
#include "response.h"
#include "mastermind.h"
/**
 * Assignment 1b EECE 2560											Ningfang Mi
 * January 23, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Main function for Assignment 1b
 * Initializes a mastermidn game object using the default mastermind constructor
 * Calls the playGame() function on the mastermind object to start the game
 **/

int main()
{
	// Initializes game
	mastermind game = mastermind();

	game.playGame();
	system("pause");
  return 0;
} // End main
