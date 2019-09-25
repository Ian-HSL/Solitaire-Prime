#ifndef CARD_H
#define CARD_H

// Header for card class
class Card {
	private: 
		char suit;
		char rank;
	public:
		Card();
		Card(char r, char s);

		void setCard(char r, char s);
		int getValue();
		void showCard();
};

#endif 

