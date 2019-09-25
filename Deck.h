#ifndef DECK_H
#define DECK_H

#include "Card.h"

// Header for deck class
class Deck {
	private:	
		Card storage[52];
		char suits[4] = { 'S', 'H', 'D', 'C' };
		char rank[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
	public:
		int topCard = 0;

		Deck();
		void refreshDeck();
		Card deal();
		void shuffle();
		int cardsLeft();
		void showDeck();
};
#endif 

