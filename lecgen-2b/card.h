/**
 * Assignment 2b EECE 2560											Ningfang Mi
 * February 23, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Declaration of card class and functions. Contains prototypes for constructor,
 * setValue, setSuit, getValue, getSuit,  overloaded << operator, copy
 * constructor and overladed = operator.
 **/
#ifndef CARD
#define CARD

#include<iostream>
#include<string>
#include<sstream>

class card
{

private:
  // 0: Clubs, 1: Diamonds, 2: Hearts, 3: Spades
  int suit;
  // 1: Ace, ... 11: Jack, 12: Queen, 13: King
  int value;

public:
  // default constructor for card
  card();

  // constructor for a given suit and values
  card(const int &s, const int &v);

  // copy constructor for card
  card(const card &rhs);

  // set a card's suit
  void setSuit(const int &s);

  // set a card's value
  void setValue(const int &v);

  // get a card's suit
  int getSuit();

  // get a card's value
  int getValue();

  // prints the value and suit with ostream (prints names from the stored ints)
  friend std::ostream& operator<<(std::ostream& os, const card &rhs);

  // overloaded assignment operator
	// creates object with identical parameters to object passed in
  card& operator=(const card &rhs);

};// end card class

#endif
