/**
 * Assignment 2b EECE 2560											Ningfang Mi
 * February 23, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Declaration of deck class and functions including constructor for a 52 card
 * deck, overloaded operator<< f,  shuffle replace, deal and getFront.
 **/

#ifndef DECK
#define DECK

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include "d_node.h"
#include "card.h"

class deck
{
private:
  // points to first node in list
  node<card> *front;

public:
  // default constructor creats a deck of 52 cards
  deck(const bool &newDeck);

  // destructor for a deck of cards
  ~deck();

  // prints all of the cards in a deck with ostream
  friend std::ostream& operator<<(std::ostream &os, const deck &rhs);

  // shuffles thhe cards to a random order
  void shuffle();

  // returns the top card in the deck
	// the card is also removed from the deck
	card deal();

  // places a card at the bottom of the deck
  void replace(const card &bottomcard);

  //getter for front
  node<card> * getFront(){return front;};

};// end deck class

#endif
