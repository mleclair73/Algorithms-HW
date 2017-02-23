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

card::card(const card &rhs)
{
  (*this) = rhs;
}// end card(card)

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

std::ostream& operator<<(std::ostream& os, const card &rhs)
{
  //parse value
  std::string val;
  switch(rhs.value)
  {
    case 1: val = "Ace";
            break;
    case 11: val = "Jack";
            break;
    case 12: val = "Queen";
            break;
    case 13: val = "King";
            break;
    default: {std::stringstream ss;
              ss << rhs.value;
              val = ss.str();}
            break;
  }

  //parse suit
  std::string st;
  switch(rhs.suit)
  {
    case 0: st = "Clubs";
            break;
    case 1: st = "Diamonds";
            break;
    case 2: st = "Hearts";
            break;
    case 3: st = "Spades";
            break;
    default: st = "please use a valid suit";
            break;
  }


  return os << "Suit: " << st << ", Value: " << val << std::endl;
}//end operator<<

card& card::operator=(const card & rhs)
{
	suit = rhs.suit;
	value = rhs.value;
  return *this;
}//return operator=
