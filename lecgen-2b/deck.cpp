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
  //std::cout << "deck made\n";
}// end deck

//deallocates the list of cards
deck::~deck()
{
	node<card> *prev = NULL;

	// iterates through list deleting the front node untill none remain
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

// takes random element, remove from list, put at front or however
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

// returns the top card in the deck then removes that top card
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


// the passed card is placed on the bottom of the deck
void deck::replace(const card& bottomcard)
{
	node<card> *curr = front;
	node<card> *prev = NULL;
	node<card> *bottomCardNode = new node<card>(bottomcard, NULL);
  if(front == NULL)
  {
    front = bottomCardNode;
    return;
  }

	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
  curr->next = bottomCardNode;
}// end replace
