#include <iostream>
#include "Card.h"
using namespace std;

Card::Card()
{
	rank = 'z';
	suit = 'z';
}

Card::Card(char aSuit, char aRank)
{
	rank = aRank;
	suit = aSuit;
}

void Card::setCard(char aSuit, char aRank)
{
	rank = aRank;
	suit = aSuit;
}

int Card::getValue()
{
	if (rank == 'A')
	{
		return 1;
	}
	else if (rank == '2')
	{
		return 2;
	}
	else if (rank == '3')
	{
		return 3;
	}
	else if (rank == '4')
	{
		return 4;
	}
	else if (rank == '5')
	{
		return 5;
	}
	else if (rank == '6')
	{
		return 6;
	}
	else if (rank == '7')
	{
		return 7;
	}
	else if (rank == '8')
	{
		return 8;
	}
	else if (rank == '9')
	{
		return 9;
	}
	else
	{
		return 10;
	}

}

void Card::displayCard()
{
	char card_pic[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			card_pic[i][j] = ' ';
		}
	}
	
	card_pic[0][0] = '+';
	card_pic[0][1] = '-';
	card_pic[0][2] = '-';
	card_pic[0][3] = '-';
	card_pic[0][4] = '-';
	card_pic[0][5] = '-';
	card_pic[0][6] = '-';
	card_pic[0][7] = '-';
	card_pic[0][8] = '+';

	card_pic[8][0] = '+';
	card_pic[8][1] = '-';
	card_pic[8][2] = '-';
	card_pic[8][3] = '-';
	card_pic[8][4] = '-';
	card_pic[8][5] = '-';
	card_pic[8][6] = '-';
	card_pic[8][7] = '-';
	card_pic[8][8] = '+';

	card_pic[1][0] = '|';
	card_pic[2][0] = '|';
	card_pic[3][0] = '|';
	card_pic[4][0] = '|';
	card_pic[5][0] = '|';
	card_pic[6][0] = '|';
	card_pic[7][0] = '|';

	card_pic[1][8] = '|';
	card_pic[2][8] = '|';
	card_pic[3][8] = '|';
	card_pic[4][8] = '|';
	card_pic[5][8] = '|';
	card_pic[6][8] = '|';
	card_pic[7][8] = '|';

	//Suit Arrangements
	card_pic[1][1] = rank;
	card_pic[7][7] = rank;

	if (rank == 'A')
	{
		card_pic[4][4] = suit;
	}
	else if (rank == '2')
	{
		card_pic[2][4] = suit;
		card_pic[6][4] = suit;
	}
	else if (rank == '3')
	{
		card_pic[2][4] = suit;
		card_pic[6][4] = suit;
		card_pic[4][4] = suit;
	}
	else if (rank == '4')
	{
		card_pic[2][3] = suit;
		card_pic[2][5] = suit;
		card_pic[6][3] = suit;
		card_pic[6][5] = suit;
	}
	else if (rank == '5')
	{
		card_pic[2][3] = suit;
		card_pic[2][5] = suit;
		card_pic[6][3] = suit;
		card_pic[6][5] = suit;
		card_pic[4][4] = suit;
	}
	else if (rank == '6')
	{
		card_pic[2][3] = suit;
		card_pic[2][5] = suit;
		card_pic[6][3] = suit;
		card_pic[6][5] = suit;
		card_pic[4][3] = suit;
		card_pic[4][5] = suit;
	}
	else if (rank == '7')
	{
		card_pic[2][3] = suit;
		card_pic[2][5] = suit;
		card_pic[6][3] = suit;
		card_pic[6][5] = suit;
		card_pic[4][3] = suit;
		card_pic[4][5] = suit;
		card_pic[3][4] = suit;
	}
	else if (rank == '8')
	{
		card_pic[2][3] = suit;
		card_pic[2][5] = suit;
		card_pic[6][3] = suit;
		card_pic[6][5] = suit;
		card_pic[4][3] = suit;
		card_pic[4][5] = suit;
		card_pic[3][4] = suit;
		card_pic[5][4] = suit;
	}
	else if (rank == '9')
	{
		card_pic[2][3] = suit;
		card_pic[2][5] = suit;
		card_pic[3][3] = suit;
		card_pic[3][5] = suit;
		card_pic[4][4] = suit;
		card_pic[5][3] = suit;
		card_pic[5][5] = suit;
		card_pic[6][3] = suit;
		card_pic[6][5] = suit;
	}
	else if (rank == 'T')
	{
		card_pic[2][3] = suit;
		card_pic[2][5] = suit;
		card_pic[3][3] = suit;
		card_pic[3][5] = suit;
		card_pic[4][3] = suit;
		card_pic[4][5] = suit;
		card_pic[5][3] = suit;
		card_pic[5][5] = suit;
		card_pic[6][3] = suit;
		card_pic[6][5] = suit;
	}
	else if (rank == 'J')
	{
		card_pic[4][4] = suit;
		card_pic[4][5] = suit;
		card_pic[4][3] = suit;
		card_pic[3][4] = suit;
		card_pic[5][4] = suit;
	}
	else if (rank == 'Q')
	{
		card_pic[2][3] = suit;
		card_pic[2][4] = suit;
		card_pic[2][5] = suit;
		card_pic[3][3] = suit;
		card_pic[3][4] = suit;
		card_pic[4][3] = suit;
		card_pic[4][4] = suit;
		card_pic[4][5] = suit;
		card_pic[5][3] = suit;
		card_pic[5][4] = suit;
		card_pic[6][3] = suit;
		card_pic[6][4] = suit;
		card_pic[6][5] = suit;
	}
	else
	{
		card_pic[6][4] = suit;
		card_pic[5][4] = suit;
		card_pic[5][3] = suit;
		card_pic[5][5] = suit;
		card_pic[4][4] = suit;
		card_pic[3][4] = suit;
		card_pic[2][4] = suit;
	}


	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << card_pic[i][j];
		}
		cout << endl;
	}







}





