#include "Deck.h"
#include <iostream>
#include <cstdlib>
using namespace std;


Deck::Deck()
{
	count = 52;
	int card = 0;
	char suit;
	char rank;

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			suit = 'H';
		}
		else if (i == 1)
		{
			suit = 'D';
		}
		else if (i == 2)
		{
			suit = 'C';
		}
		else
		{
			suit = 'S';
		}
		for (int j = 0; j < 13; j++)
		{
			if (j == 0)
			{
				rank = 'A';
			}
			else if (j == 1) {
				rank = '2';
			}
			else if (j == 2) {
				rank ='3';
			}
			else if (j == 3) {
				rank = '4';
			}
			else if (j == 4) {
				rank = '5';
			}
			else if (j == 5) {
				rank = '6';
			}
			else if (j == 6) {
				rank = '7';
			}
			else if (j == 7) {
				rank = '8';
			}
			else if (j == 8)
			{
				rank = '9';
			}
			else if (j == 9)
			{
				rank = 'T';
			}
			else if (j == 10) {
				rank = 'J';
			}
			else if (j == 11)
			{
				rank = 'Q';	
			}
			else
			{
				rank = 'K';
			}
			
			cardDeck[card].setCard(suit, rank);
			card++;
		}
	}
}

void Deck::shuffle()
{
	
	for (int i = 0; i < 1000000; i++)
	{
		int x = rand() % count;
		int y = rand() % count;
		Card c1;
		c1 = cardDeck[x];
		cardDeck[x] = cardDeck[y];
		cardDeck[y] = c1;
	}
}

Card Deck::deal()
{
	return cardDeck[--count];
}

void Deck::displayCardAt(int i)
{
	 cardDeck[i].displayCard();
}

int Deck::cardsLeft()
{
	return count;
}

void Deck::reset()
{
	count = 52;
	int card = 0;
	char suit;
	char rank;

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			suit = 'H';
		}
		else if (i == 1)
		{
			suit = 'D';
		}
		else if (i == 2)
		{
			suit = 'C';
		}
		else
		{
			suit = 'S';
		}
		for (int j = 0; j < 13; j++)
		{
			if (j == 0)
			{
				rank = 'A';
			}
			else if (j == 1) {
				rank = '2';
			}
			else if (j == 2) {
				rank = '3';
			}
			else if (j == 3) {
				rank = '4';
			}
			else if (j == 4) {
				rank = '5';
			}
			else if (j == 5) {
				rank = '6';
			}
			else if (j == 6) {
				rank = '7';
			}
			else if (j == 7) {
				rank = '8';
			}
			else if (j == 8)
			{
				rank = '9';
			}
			else if (j == 9)
			{
				rank = 'T';
			}
			else if (j == 10) {
				rank = 'J';
			}
			else if (j == 11)
			{
				rank = 'Q';
			}
			else
			{
				rank = 'K';
			}

			cardDeck[card].setCard(suit, rank);
			card++;
		}
	}
}
		
	