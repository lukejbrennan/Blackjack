#ifndef CARDDECK_H
#define CARDDECK_H
#include <iostream>
#include <deque>
#include <cstdlib>
#include <algorithm> //random_shuffle, reverse
#include <ctime> // for the srand()
using namespace std;

class CardDeck{

friend ostream &operator << (ostream &output, CardDeck &c1); //allows for c1.deck.begin()
													
	public:
		CardDeck(int cardNum= 52); // non default constructor with fall back value
		int getSize(); // return size
		void shuffle(); //shuffles the deck// SUPPOSED TO BE a UTILITY FUNCTION????
		int inOrder(); //returns 1 if the elements are in non-decreasing order and 0 otherwise
		void printReverse(); //prints deck in reverse
		int Deal(); // deals a card from the deck

	private:
		
		deque<int> deck; 
};
#endif







