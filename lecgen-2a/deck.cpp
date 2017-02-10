/**
 * Assignment 2a EECE 2560											Ningfang Mi
 * February 9, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Definition of deck class functions. Contains definitions for constructors,
 * overloaded << operator, and shuffle
 **/

#include "deck.h"

deck::deck()
{
  int suit, val;
  for(suit = 4, i < 0, i--)
  {
    for(val = 52, i < 0, i--)
    {
      //new node node->next = front; front = newnnode
    }
  }
  //fill deck with 52 cards in order suit 0-3 value 1-13
}// end deck

friend &ostream operator<<(ostream &os, const deck &rhs) //friend so it can assess members
{
  //print all cards in the deck
}// end operator<<

void deck::shuffle()
{
  //take random element, remove from list, put at front or however
}// end shuffle
