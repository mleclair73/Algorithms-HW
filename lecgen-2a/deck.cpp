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
  for(suit = 3; suit >= 0; suit--)
  {
    for(val = 13; val > 0; val--)
    {
      node<card> *temp = new node<card>(card(suit, val));
      temp->next = front;
      front = temp;
      std::cout << temp->nodeValue;
    }
  }
  //fill deck with 52 cards in order suit 0-3 value 1-13
}// end deck

std::ostream& operator<<(std::ostream &os, const deck &rhs) //friend so it can assess members
{
  node<card> *current = new node<card>;
  current = rhs.front;
  while(current != NULL)
  {
    std::cout << current << std::endl;
    current = current->next;
  }
}// end operator<<

void deck::shuffle()
{
  //take random element, remove from list, put at front or however
}// end shuffle
