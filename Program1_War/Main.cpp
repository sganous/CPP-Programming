#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;

int main()
{
	int choice;
	Deck myDeck;
	do {
		cout << "Main Menu:" << endl;
		cout << "1) Get a new card deck" << endl;
		cout << "2) Show all remaining cards in the deck" << endl;
		cout << "3) Shuffle" << endl;
		cout << "4) Play WAR!" << endl;
		cout << "5) EXIT" << endl;
		cout << endl;

		cin >> choice;
			if (choice == 1)
			{
				myDeck.reset();
			}
			else if (choice == 2)
			{
				for (int i = 0; i < myDeck.cardsLeft(); i++)
				{
					myDeck.displayCardAt(i);
				}
			}
			else if (choice == 3)
			{
				myDeck.shuffle();
			}
			else if (choice == 4)
			{

				int p1_points = 0;
				int p2_points = 0;
				char play = 'Y';

				cout << "Get Ready To Play WAR!!!" << endl;

				myDeck.shuffle();

				while (play == 'Y')
				{
					cout << "There are " << myDeck.cardsLeft() << "  cards in the deck." << endl;
					cout << "...dealing..." << endl;
					cout << "One for you..." << endl;
					Card p1 = myDeck.deal();
					p1.displayCard();
					cout << "One for me..." << endl;
					Card p2 = myDeck.deal();
					p2.displayCard();
					cout << "You have " << p1.getValue() << " points" << endl;
					cout << "I have " << p2.getValue() << " points" << endl;

					//War Logic
					if (p1.getValue() > p2.getValue())
					{
						cout << "You Win!" << endl;
						p1_points++;
					}
					else if (p1.getValue() < p2.getValue())
					{
						cout << "You Lose!" << endl;
						p2_points++;
					}
					else
					{
						cout << "Tie Game!" << endl;
					}

					if (myDeck.cardsLeft() >= 2) {
						cout << "Wanna play again? (Y/N)" << endl;
						cin >> play;
					}
					else
					{
						play = 'N';
					}
				}

				cout << "Here is the final score:" << endl;
				cout << "You won " << p1_points << " hands" << endl;
				cout << "I won " << p2_points << " hands" << endl;
				if (p1_points > p2_points)
				{
					cout << "You are the Champion of the World!" << endl;
					cout << endl;
				}
				else if (p1_points < p2_points)
				{
					cout << "You lose :(" << endl;
					cout << endl;
				}
				else
				{
					cout << "Its a tie game..." << endl;
					cout << endl;
				}
			}

	} while (choice != 5);
	return 0;
}