#include "deck.h"

#include<iostream>

int main()
{
	deck d1 = deck();
	std::cout << "The Deck is: " << std::endl;
	std::cout << d1;
	d1.shuffle();
	std::cout << "The Deck after shuffling is: " << std::endl;
	std::cout << d1;
	std::cout << "The top card of the deck is: " << std::endl;
	d1.deal();
	system("pause");
	return 0;
}
