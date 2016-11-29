#include <iostream>
#include "Card.h"
using namespace std;

class Deck
{
private:
	Card cardDeck[52];
	int count;

public:
	Deck();
	void displayCardAt(int);
	Card deal();
	int cardsLeft();
	void shuffle();
	void reset();
};