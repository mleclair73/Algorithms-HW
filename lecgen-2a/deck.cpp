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
  front = new node<card>();
  std::cout << front->next << std::endl;
  int suit, val;
  for(suit = 3; suit >= 0; suit--)
  {
    for(val = 13; val > 0; val--)
    {
      node<card> *temp = new node<card>(card(suit, val));
      temp->next = front;
      front = temp;
      //std::cout << temp->nodeValue;
    }
  }
  //fill deck with 52 cards in order suit 0-3 value 1-13
}// end deck

std::ostream& operator<<(std::ostream &os, const deck &rhs) //friend so it can assess members
{
  node<card> *current;
  current = rhs.front;
  int i = 1;
  while(current != NULL)
  {
    std::cout << i << current->nodeValue << std::endl;
    current = current->next;
    i++;
  }
}// end operator<<

void deck::shuffle() //shuffling algo?????????????
{
  node<card> *curr;
  node<card> *prev;
	restart:
	for (int r = 0; r < 10000; r++)
	{

		int seed;
		seed = rand() % 52 + 1;

		if (prev != NULL)
		{

			for (int i = 1; i < seed; i++)
			{
				prev = curr;
				curr = curr->next;
			}

			prev->next = curr->next;
			curr->next = front;
			front = curr;
		}

		else
		{
			goto restart;
		}


	}

	//take random element, remove from list, put at front or however
};// end shuffle
