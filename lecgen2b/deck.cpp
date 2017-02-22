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
	for (suit = 3; suit >= 0; suit--)
	{
		for (val = 13; val > 0; val--)
		{
			node<card> *newCard = new node<card>(card(suit, val), front);
			front = newCard;
		}
	}
}// end deck


//deallocates the list of cards
deck::~deck()
{
	node<card> *curr = front;
	node<card> *prev = NULL;

	for (int j = 0; j < 52; j++)
	{
		prev = curr;
		curr = curr->next;
		delete prev;
	}
}


std::ostream& operator<<(std::ostream &os, const deck &rhs) //friend so it can assess members
{
	node<card> *current;
	current = rhs.front;
	int i = 1;
	while (current != NULL)
	{
		std::cout << current->nodeValue << std::endl;
		current = current->next;
		i++;
	}
	return os;
}// end operator<<


void deck::shuffle() //shuffling algo?????????????
{

	node<card> *curr = front;
	node<card> *prev = NULL;
	int seed;

	for (int r = 0; r < 1000; r++)
	{
	restart:
		seed = rand() % 52 + 1;
		//std::cout << seed << std::endl;

		for (int j = 1; j < seed; j++)
		{
			prev = curr;
			curr = curr->next;
		}

		if (prev == NULL)
		{
			goto restart;
		}

		prev->next = curr->next; //closes break in linked list
		curr->next = front;
		front = curr;
		prev = NULL;
		std::cout << r << std::endl;
	}

	// take random element, remove from list, put at front or however
};  // end shuffle



	// returns the top card in the deck then removes that top card
void deck::deal()
{
	node<card> *curr = front;
	node<card> *prev = NULL;

	prev = curr;
	curr = curr->next;
	std::cout << front->nodeValue;
	delete prev;
}

	// the passed card is placed on the bottom of the deck
void deck::replace(const card& bottomcard)
{
	node<card> *curr = front;
	node<card> *prev = NULL;
	node<card> *bottomcard = &bottomcard;
	//???????????

	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next; 
	}

	curr->next = *bottomcard;
	
}