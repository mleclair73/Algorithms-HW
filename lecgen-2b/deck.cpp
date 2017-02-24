/**
 * Assignment 2b EECE 2560											Ningfang Mi
 * February 23, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Definition of deck class functions. Contains definitions for constructors,
 * overloaded << operator, shuffle, replace and deal
 **/

#include "deck.h"

deck::deck(const bool &newDeck)
{
  front = NULL;
  int suit, val;
  if (newDeck == true)
  {
    for(suit = 3; suit >= 0; suit--)
    {
      for(val = 13; val > 0; val--)
      {
        node<card> *newCard = new node<card>(card(suit, val),front);
        front = newCard;
      }// end for val
    }// end for suit
  }// end if
}// end deck

deck::~deck()
{
	node<card> *prev = NULL;

	// iterates through list deleting the front node until none remain
	while(front!= NULL)
	{
		prev = front;
		front = front->next;
		delete prev;
	}// end while

}//end ~deck

std::ostream& operator<<(std::ostream &os, const deck &rhs)
{
  node<card> *current;
  current = rhs.front;
  int i = 1;
  // iterate through list
  while(current != NULL)
  {
    os << i << ":" << current->nodeValue;
    current = current->next;
    i++;
  }
  return os;
}// end operator<<

void deck::shuffle()
{
  std::cout << "Shuffling Deck ... \n";
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
			//std::cout << r << std::endl;
	}

};// end shuffle

card deck::deal()
{
	node<card> *prev = NULL;
  if(front == NULL)
  {
    throw std::invalid_argument("Can't deal an empty list");
  }
    card retCard = front->nodeValue;                //get value from node

    prev = front;                                   //iterate front
    front = front->next;

  	delete prev;
    return retCard;

}// end deal

void deck::replace(const card& bottomcard)
{
	node<card> *curr = front;
	node<card> *prev = NULL;
	node<card> *bottomCardNode = new node<card>(bottomcard, NULL);

  if(front == NULL)
  {
    front = bottomCardNode;                       //empty deck insertion
    return;
  }

	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;                            //insert after all cards in
	}                                               //deck
  curr->next = bottomCardNode;
}// end replace
