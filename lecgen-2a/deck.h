/**
 * Assignment 2a EECE 2560											Ningfang Mi
 * February 9, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Declaration of deck class and functions including constructor for a 52 card
 * deck, overloaded operator<< f, and shuffle.
 **/

#ifndef DECK.H
#define DECK.H

#include <iostream>
#include "d_node.h"
#include "card.h"

class deck
{
private:
  // points to first node in list
  node<card> *front;
public:
  // default constructor creats a deck of 52 cards
  deck();

  // prints all of the cards in a deck with ostream
  friend &ostream operator<<(ostream &os, const deck &rhs);

  // shuffles thhe cards to a random order
  void shuffle();

};// end deck class


#endif
