/**
 * Assignment 1b EECE 2560											Ningfang Mi
 * February 2, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Declaration of response class functions. Contains definitions for
 * constructor, overloaded == operator and overloaded <<
 * operator
 **/
#include "response.h"

response::response()
{
  //initializes values at 0 if no parameters are given
  correct = 0;
  incorrect = 0;
}

response::response(const int &c = 0, const int &i = 0)
{
  correct = c;
  incorrect = i;
}

bool operator==(const response &lhs, const response &rhs)
{
  return (lhs.getCorrect() == rhs.getCorrect()) &&
         (lhs.getIncorrect() == rhs.getIncorrect());
}

ostream& operator<<(ostream& os, const response &rhs)
{
  return os << rhs.getCorrect() << " Correct and " << rhs.getIncorrect()
            << " Incorrect \n";
}
