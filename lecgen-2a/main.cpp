#include "deck.h"

#include<iostream>

int main()
{
  deck d1 = deck();
  std::cout << "The Deck is: " << std::endl;
  std::cout << d1;
  d1.shuffle();
  std::cout << "The Deck afte shuffling is: " << std::endl;
  std::cout << d1;
  system("pause");
  return 0;
}
