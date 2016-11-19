#include "CardDeck.h"
using namespace std;


CardDeck::CardDeck(int cardNum_in){
	// stores 0 through CardNum_in-1 elements in deck:
	for( int i=0; i<cardNum_in; i++){
		deck.push_back(i);   
	}
	//Convert card numbers to blackjack numbers. 
	for( int i=0; i<cardNum_in; i++){
		deck[i]=(i+1)%13; //convert all numbers to be from 0 to 12
		if (deck[i]==1 | deck[i]==0 | deck[i]== 12) //change 0, 1, and 12 to be facecards (leave 11's for aces and 2-10 to be 2-10)
			deck[i]= 10; 
	}
}

int CardDeck::getSize(){
	return deck.size();	 
}

void CardDeck::shuffle(){
	random_shuffle(deck.begin(), deck.end());
}

int CardDeck::inOrder(){
	int count=0;
	for(int i=0; i<deck.size(); i++){
		if (deck[i]<=deck[i+1]){
			count++; // counts the number of pairs that are in the correct order
		}
	}
	if (count== (deck.size()-1)) // if there are as many pairs in the correct order as there are possible pairs, then
		return 1; // deck is in non decreasing order
	else
		return 0; // deck is not in non decreasing order
}

ostream &operator << (ostream &output, CardDeck &c1){ //overload << op to print deck with 
													//commas between elements
	deque<int>::const_iterator i; // initialize i as a constant iterator of a deque of ints
	for (i=c1.deck.begin(); i!=c1.deck.end()-1; ++i){
		output << *i << ", "; 
	}
	output << *i << endl; 

	return output;
}	

void CardDeck::printReverse(){ //print deck in reverse
	reverse(deck.begin(), deck.end()); //use reverse algorithm to put deck in reverse order
	deque<int>::const_iterator i; //printing process is the same as printing forwards from here
	for (i=deck.begin(); i!=deck.end()-1; ++i){
		cout << *i << ", "; // we can use cout here because we have already overloaded 
							// the << operator
	}

	cout << *i << endl;
}

int CardDeck::Deal(){
	int deal;	
	deal=deck.front();
	deck.pop_front();
	return deal; // return the card
}


/*
void CardDeck::BlackJack(){
	//initialize players
	int	sum_player=0;
	int sum_dealer=0;	
	
	//set variable for player's choice of hit or stand
	char player_move;

	//shuffle the deck	
	deck.shuffle(); 

	//deal and display the player's first two cards
	sum_player+= deck.Deal();
	cout << "Your cards are: " << deck.Deal();
	sum_player+= deck.Deal();
	cout << " and " << deck.Deal() << endl;
		//chck for loss


	//deal the dealers card. She only gets one card faceup, so just display and count that card for now
	sum_dealer+= deck.Deal();
	cout << "The dealer has: " << deck.Deal() << endl;

	//Let player hit or stand
	cout << "Would you like to hit (h) or stand (s): " << endl;
	cin >> player_move;
	while (player_move == 'h'){
	 	sum_player+= deck.Deal();
		cout << "Card dealt: " << deck.Deal();
		/// check for loss!
		cout << "Would you like to hit (h) or stand (s): " << endl; //prepare for iteration
		cin >> player_move;
	}

	//Now that player has chosen to stand, evaluate the dealers hand
	while(sum_dealer < 17){ //while the dealers sum is less than 17, keep dealing to the dealer
		sum_dealer+=deck.Deal();
	}

??problem was that i couldn't call other member functions inside this function without instantiating an object...
is there a way around this??


*/













































