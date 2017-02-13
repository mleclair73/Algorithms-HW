/**
 * Assignment 2a EECE 2560											Ningfang Mi
 * February 9, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Definition of deck class functions. Contains definitions for constructors,
 * overloaded << operator, and shuffle
 **/

#include "deck.h"

//fills deck with 52 cards in order suit 0-3 value 1-13
deck::deck()
{
  front = NULL;
  int suit, val;
  for(suit = 3; suit >= 0; suit--)
  {
    for(val = 13; val > 0; val--)
    {
      node<card> *newCard = new node<card>(card(suit, val),front);
      front = newCard;
    }
  }
}// end deck

std::ostream& operator<<(std::ostream &os, const deck &rhs)
{
  node<card> *current;
  current = rhs.front;
  int i = 1;
  // iterate through list
  while(current != NULL)
  {
    os << current->nodeValue << std::endl;
    current = current->next;
    i++;
  }
  return os;
}// end operator<<

// takes random element, remove from list, put at front or however
void deck::shuffle()
{

	node<card> *curr = front;
	node<card> *prev = NULL;
	int seed;

	for (int r = 0; r < 1000; r++)
	{
		restart:
		seed = rand() % 52 + 1;

      // iterates through list
			for (int j = 1; j < seed; j++)
			{
				prev = curr;
				curr = curr->next;
			}

      // if first element, try again
			if (prev == NULL)
			{
				goto restart;
			}

      //remove link from list & reset curr / prev
			prev->next = curr->next;
			curr->next = front;
			front = curr;
			prev = NULL;
			std::cout << r << std::endl;
	}

};// end shuffle
