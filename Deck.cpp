#include "Deck.h"
#include <iostream>
#include <time.h>
using namespace std;

// Implementation of the deck class

// Sets the deck filled with cards
Deck::Deck() {
	int index = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			storage[index].setCard(rank[j], suits[i]);
			index++;
		}
	}
}

// Displays cards in the deck
void Deck::showDeck() {
	int index = 0;

	for (unsigned int i = 0; i < 4; i++) {
		for (unsigned int j = 0; j < 13; j++) {
			storage[index].showCard();
			index++;
		}
		cout << endl;
	}
}

// Resets the deck back to its default 
void Deck::refreshDeck() {
	int index = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			storage[index].setCard(rank[j], suits[i]);
			index++;
		}
	}

	topCard = 0;
}

// Shuffles the cards in the deck
void Deck::shuffle() {
	srand(time(0));
	Card replacement;
	for (unsigned int i = 0; i < 52; i++) {
		int randIndex = rand() % 52;

		// store random card to another location
		replacement = storage[randIndex];

		// turns random index card to indexed card
		storage[randIndex] = storage[i];

		// turns index card to replacement card
		storage[i] = replacement;
	}
}

// Outputs the card at the top
Card Deck::deal() {
	return storage[topCard++];
}

// Returns the number of cards left
int Deck::cardsLeft() {
	return 51 - topCard + 1;
}


