#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

class Card
{
private:
	char rank;
	char suit;
public:
	Card();
	Card(char s, char r);
	void setCard(char s, char r);
	int getValue();
	void displayCard();
};
#endif
