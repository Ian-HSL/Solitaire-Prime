// Ian Ho-Sing-Loy
// CECS 282-07
// Prog 1 - Solitaire Prime
// 9/18/2019

// Plays the Solitaire prime menu. 
// Allows option for new deck, shuffle, display deck, and play solitaire prime

#include "Card.h"
#include "Deck.h"
#include <vector>
#include <conio.h>
#include <iostream>
using namespace std;

// Prototype of isPrime method
bool isPrime(int primeTest);

// Prototype of the solitaire game function
void solitaireGame(Deck& deck);

int main(){
	int response = 0;
	Deck deck;

	// While loop keeps running until 5 is selected
	do {
		cout << "Welcome to Solitaire Prime!" << endl <<
			"1) New Deck" << endl <<
			"2) Display Deck" << endl <<
			"3) Shuffle Deck" << endl <<
			"4) Play Solitaire Prime" << endl <<
			"5) Exit" << endl;
		cin >> response;

		switch (response) {
		case 1:
			deck.refreshDeck();
			break;
		case 2:
			deck.showDeck();
			break;
		case 3:
			deck.shuffle();
			break;
		case 4:
			solitaireGame(deck);
			break;
		case 5:
			break;
		default:
			break;
		}
	} while (response != 5);

	return 0;
}

// Evaluates whether a number is prime
bool isPrime(int primeTest) {
	// Prime Number Generator begin

	// Generates all prime numbers under 300
	int limit = 300;
	int index = 0;
	vector<int> primeList{ 2, 3, 5 };
	double ceiling = primeList.back() / double(primeList[index]);

	// Is last prime number smaller than the user-inputted maximum?
	while (primeList.back() < limit) {
		while (primeList[index] <= ceiling) {
			if (primeList.back() % primeList[index] == 0) {
				primeList.back() += 2;
				index = 0;
				ceiling = primeList.back() / primeList[index];
			}
			else if (primeList.back() % primeList[index] != 0) {
				index += 1;
				ceiling = primeList.back() / primeList[index];
			}
		}
		primeList.push_back(primeList.back() + 2);
		index = 0;
		ceiling = primeList.back() / primeList[index];
	}
	primeList.pop_back();
	primeList.pop_back();
	
	// Prime Number Generator end

	int i = 0;

	// Tests whether the number is divisible by prime numbers generated
	if (primeTest == 1) { // returns false when the number is 1
		return false;
	} else {
		while (primeTest > primeList[i]) {
			// If number is divisible by one of the prime numbers, returns false
			if (primeTest % primeList[i] == 0) {
				return false;
			} else {
				i++;
			}
		}
		return true;
	}
}

void solitaireGame(Deck &deck) {
	int pileCount = 0; // Number of piles
	int cardCount = 0; // Keeps track of the index of the deck
	int pileSum = 0; // Sum of the value of cards dealed
	vector<Card> pile; // "Table" where the cards dealed will be in

	cout << "Playing Solitaire Prime!!!" << endl;

	// While loop keeps running cards left is 0
	do {
		// Add a dealed card to table
		pile.push_back(deck.deal());

		// Add value to pileSum
		pileSum = pileSum + pile[cardCount].getValue();

		if (pile.size() == 1){
			pile[cardCount].showCard();
		} else {
			cout << ", ";
			pile[cardCount].showCard();
		}

		if (isPrime(pileSum) == true) {
			// Display pileSum when pileSum is prime
			cout << " Prime: " << pileSum << endl;

			// Empty the pile
			pile.clear();

			if (deck.cardsLeft() == 0) {
				cout << "Winner in " << pileCount << " piles!" << endl;
			}
			// Resets to default values and updates the pileCount
			cardCount = 0;
			pileSum = 0;
			pileCount++;

		} else {
			if (deck.cardsLeft() == 0) {
				cout << "Loser" << endl;
			}
			else {
				cardCount++;
			}
		}

	} while (deck.cardsLeft() != 0);

	// After game ends, refresh the deck to default
	deck.refreshDeck();
}
