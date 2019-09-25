#include "Card.h"
#include <iostream>
using namespace std;

// Implementation of card class

// Default card constructor
Card::Card() {
	rank = '?';
	suit = '?';
}

// Setting the card to a certain rank and suit
Card::Card(char r, char s) {
	rank = r;
	suit = s;
}

// Returns rank
int Card::getValue() {
	// Returns integer corresponding to the rank
	switch (rank){
		case 'A':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'T': 
		case 'J':
		case 'Q':
		case 'K':
			return 10;
		default:
			break;
	}
}

// Shows rank and suit of a card
void Card::showCard() {
	if (rank == 'T') {
		cout << 10;
		cout << suit << ' '; 
	}
	else {
		cout << rank << suit << ' ';
	}
}

// Sets an existing card to a different rank and suit
void Card::setCard(char r, char s) {
	rank = r;
	suit = s;
}
