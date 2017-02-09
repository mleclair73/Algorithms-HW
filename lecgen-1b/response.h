/**
 * Assignment 1b EECE 2560											Ningfang Mi
 * February 2, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Definition of response class and functions. Contains definitions for
 * constructor, setters, getters, overloaded == operator and overloaded <<
 * operator
 **/

#ifndef responseH
#define responseH

#include <iostream>

using namespace std;

class response
{

  private:
    int correct;
    int incorrect;

  public:
    //Creates a response initializing correct and incorrect to 0
    response();

    //Creates a response given the number of correct and incorrect responses
    response(const int &c, const int &i);

    //Sets the number correct
    void setCorrect(const int &c) {correct = c;};

    //Sets the number incorrect
    void setIncorrect(const int &i) {incorrect = i;};

    //Returns the number correct in the response
    int getCorrect() const {return correct;};

    //Returns the number incorrect in the response
    int getIncorrect() const {return incorrect;};

    //Overloaded == operator that comopares responses returning true if equal
    friend bool operator==(const response &lhs, const response &rhs);

    //Overloaded << operator that returns an ostream&
    friend ostream& operator<<(ostream& os, const response &rhs);
}; //end of response
#endif //end of response.h
