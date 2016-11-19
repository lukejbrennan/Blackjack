#include <iostream>
#include "CardDeck.h"

int main(){
	srand(time(0)); 

	//Initialize variables
	char winner; //set a variable to keep track of who won
	char game_status= 'y'; //controls whether or not game continues; y is for yes, play again. n is for no, make it stop
	int player_wins=0; // number of times the player has won
	int dealer_wins=0; // number of times dealer has won
	CardDeck *c1= new CardDeck(52); // makes a deck of 52 cards using pointer c1
	int	sum_player; //player's score
	int sum_dealer; // dealer's	score
	char player_move; //set variable for player's choice of hit or stand
	int dealNow; //stores the current value of c1->Deal()
	int gameover; //someone has won if gameover=1; gameover=0 means that the game is still going on

	//Play BlackJack	
	while(game_status == 'y'){		
		//Clean-up from last game. Initialize in preparation for next game
		gameover=0; // game is going on
		sum_player=0;
		sum_dealer=0;

		//shuffle the deck	
		(*c1).shuffle(); // equivalent to c1->shuffle();

		//deal and display the player's first two cards
		dealNow=c1->Deal();
		
		//Check if we need a new deck		
		if(c1->getSize()< 15){ //if there are fewer than 15 cards left in the deck
			cout << "Cards in deck: " << c1->getSize() << ". Getting new deck..."<< endl;			
			delete c1; // delete the old constructor
			CardDeck *c1= new CardDeck(52); // fill in the whole where the old object used to be with a newly created object
			c1->shuffle(); //shuffle
		}		

		sum_player+= dealNow;
		cout << "Your cards are: " << dealNow;
		dealNow=c1->Deal();

		//Check if we need a new deck		
		if(c1->getSize()< 15){ //if there are fewer than 15 cards left in the deck
			cout << "Cards in deck: " << c1->getSize() << ". Getting new deck..."<< endl;
			delete c1; // delete the old constructor
			CardDeck *c1= new CardDeck(52); // fill in the whole where the old object used to be with a newly created object
			c1->shuffle(); //shuffle
		}

		sum_player+= dealNow;
		cout << " and " << dealNow << endl;

		//Check for player loss
		if(sum_player>=22){ //if player has lost, assign winner variable to be 'd' (dealer has won)
			winner='d';
			cout << "You lost because you went over 21! You had: " << sum_player << endl;
			gameover=1;
		}	

		//deal the dealers card. She only gets one card faceup, so just display and count that card for now
		dealNow=c1->Deal();	

		//Check if we need a new deck		
		if(c1->getSize()< 15){ //if there are fewer than 15 cards left in the deck
			cout << "Cards in deck: " << c1->getSize() << ". Getting new deck..."<< endl;
			delete c1; // delete the old constructor
			CardDeck *c1= new CardDeck(52); // fill in the whole where the old object used to be with a newly created object
			c1->shuffle(); //shuffle
		}	

		sum_dealer+= dealNow;
		cout << "The dealer has: " << dealNow << endl;

		//Let player hit or stand
		cout << "Would you like to hit (h) or stand (s): ";
		cin >> player_move;
		while (player_move == 'h'){
			dealNow=c1->Deal();

			//Check if we need a new deck		
			if(c1->getSize()< 15){ //if there are fewer than 15 cards left in the deck
				cout << "Cards in deck: " << c1->getSize() << ". Getting new deck..."<< endl;				
				delete c1; // delete the old constructor
				CardDeck *c1= new CardDeck(52); // fill in the whole where the old object used to be with a newly created object
				c1->shuffle(); //shuffle
			}

		 	sum_player+= dealNow;
			cout << "Card dealt: " << dealNow << endl;
			cout << "Your current score: " << sum_player << endl;
			if(sum_player>=22){ //if player has lost, assign winner variable to be 'd' (dealer has won)
				winner='d'; //dealer has won
				cout <<"You lost because you went over 21! You had: " << sum_player << endl;
				gameover=1;
				break; //if player lost, break the while loop
			}				
			cout << "Would you like to hit (h) or stand (s): "; //prepare for iteration
			cin >> player_move;
		}

		//Now that player has chosen to stand, evaluate the dealers hand
		while((!gameover) && (sum_dealer < 17)) { //while the dealers sum is less than 17 and the game is ongoing
			dealNow=c1->Deal();	
			cout << "Dealer recieved: " << dealNow << endl; // shows the card that the dealer got
			//Check if we need a new deck		
			if(c1->getSize()< 15){ //if there are fewer than 15 cards left in the deck
				cout << "Cards in deck: " << c1->getSize() << ". Getting new deck..."<< endl;				
				delete c1; // FREES MEMORY THAT WAS ALLOCATED TO THE POINTER'S OBJECT
							//FREES MEMORY THAT POINTER POINTED TO
				CardDeck *c1= new CardDeck(52); // fill in the whole where the old object used to be with a newly created object
				c1->shuffle(); //shuffle
			}

			sum_dealer+=dealNow;
			if (sum_dealer>=22){ //check for loss (dealer's loss)
				winner=	'p'; //winner is player
				cout <<"You won because the Dealer went over 21! Dealer had: " << sum_dealer << endl;
				gameover=1;
				break;	//break out of while loop because player has won
			}
		}
		
		//Check for win or loss if neither party went over 21
		if(!gameover){ //if game is still to be decided, check scores
			if(sum_player>sum_dealer){
				winner='p'; //player wins if score is greater than dealer
				cout << "You won! You had: " << sum_player << ". Dealer had: " << sum_dealer << endl;
			}
			else{
				winner='d'; //otherwise dealer wins
				cout << "You lost... You had: " << sum_player << ". Dealer had: " << sum_dealer << endl;
			}
		
		}
		//Keep track of how many times the player and dealer have won
		if(winner=='p')
			player_wins++;

		else if (winner= 'd')
			dealer_wins++;

		//display record
		cout << "You have won " << player_wins << " times" << endl;
		cout << "The dealer has won " << dealer_wins << " times" << endl;

		//Ask if the player would like to play again...
		cout << "Would you like to play again? Type y for yes, n for no: ";
		cin >> game_status;
		cout << endl; 
	}	
}













































