/**
 * Assignment 2a EECE 2560											Ningfang Mi
 * February 9, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Definition of card class functions. Contains definitions for constructor,
 * setValue, setSuit, getValue, getSuit and  overloaded << operator,
 **/

#include "card.h"

card::card()
{
  suit = 0;
  value = 0;
}// end card()

card::card(const int &s, const int &v)
{
  suit = s;
  value = v;
}// end card(int, int)

void card::setSuit(const int &s)
{
  suit = s;
}// end setSuit

void card::setValue(const int &v)
{
  value = v;
}// end setValue

int card::getSuit()
{
  return suit;
}// end getSuit

int card::getValue()
{
  return value;
}// end getValue

&ostream operator<<(ostream& os, const card &rhs)
{
  string val;
  switch(value)
  {
    case 1: val = "Ace";
    case 11: val = "Jack";
    case 12: val = "Queen";
    case 13: val = "King";
    default: val = std::toString(value);
  }

  string st;
  switch(suit)
  {
    case 0: st = "Clubs";
    case 1: st = "Diamonds";
    case 2: st = "Hearts";
    case 3: st = "Spades";
    default: st = "invalid suit type"
  }

  return os << "Suit: " << st << " Value: " << value << std::endl;
}//end operator<<
