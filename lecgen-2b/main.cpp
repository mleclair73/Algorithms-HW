/**
 * Assignment 2b EECE 2560											Ningfang Mi
 * February 23, 2016															ningfang@ece.neu.edu
 * Malcolm Leclair & Erik Gentile
 *
 * Main function for assignment
 **/

#include "deck.h"
#include<string>
#include<sstream>
#include<iostream>
#include<time.h>

void playFlip();
void cardtoPoints(int &points, card &flip);
void flipFalse(bool (&flipArr)[24]);
void tripleShuffle(deck &d);
void deal24(deck &game, deck &hand);

using namespace std;
int main()
{
  srand(time(NULL));
  playFlip();
  system("pause");
  return 0;
}//end main

void playFlip()
{
  deck flip = deck(true);                     // make deck of 52 cards
  tripleShuffle(flip);                        // shuffle 3 times

  deck hand = deck(false);                    // make empty deck
  deal24(flip, hand);                         // deal first 24 from flip to hand

  bool flipped[24];                           // array of booleans to determine
  flipFalse(flipped);                         // if card is used, init to False

  cout << "The cards remaining in the deck are :\n" << flip;

  int points = 0;
  string response;
  int cardChoice;
  node<card> *curr;


  while(true)
  {
    cout << "Your hand is:\n" << hand << endl;
    cout << "Enter the number of a card to flip or press q to end the game"
         << endl;
    curr = hand.getFront();
    startloop:
    cin >> response;
    if(response == "q")
    {
      cout << "You earned: " << points << " points\n";
      return;   //or go to
    }

    stringstream stoi(response);
    stoi >> cardChoice;

    if((cardChoice == 0)| (cardChoice > 24))
    {
      cout << "please input a valid input\n";
      goto startloop;
    }

    if(flipped[cardChoice] == false)
    {
      flipped[cardChoice] = true;
      for(int i = 0; i < cardChoice-1; i++)
      {
        curr = curr->next;
      }

      cardtoPoints(points, curr->nodeValue);
      cout << "The card you chose was:\n" << curr->nodeValue << endl;
    }//end if(flipped[cardChoice])

    else
    {
      cout << "Please input the value of a card you haven't flipped yet\n\n";
    }
  }//end while(true)

  cout << "You earned: " << points << " points\n";
  return;
}// end playFlip

//converts a card to a point value
void cardtoPoints(int &points, card &flip)
{
  switch(flip.getValue())
  {
    case 1:  points += 10;
             break;
    case 7:  points /= 2;
             break;
    case 8:  break;
    case 9:  break;
    case 10: break;
    case 11: points += 5;
             break;
    case 12: points += 5;
             break;
    case 13: points += 5;
             break;
    default: points = 0;
             break;
    }

    if(flip.getSuit() == 2)
    {
      points++;
    }
}// end cardtoPoints

//sets all values in a boolean array[24] to false
void flipFalse(bool (&flipArr)[24])
{
  for(int i = 0; i < 24; i++)
  {
    flipArr[i] = false;
  }
}// end flipFalse

//shuffles a deck d 3 times
void tripleShuffle(deck &d)
{
  for(int i = 0; i < 3; i++)
  {
    d.shuffle();
  }
}// end tripleShuffle

//takes 24 top cards from game and places into hand
void deal24(deck &game, deck &hand)
{
  for(int i = 0; i < 24; i++)
  {
    hand.replace(game.deal());
  }
}// end deal24
