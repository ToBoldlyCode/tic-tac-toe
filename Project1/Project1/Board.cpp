#include <iostream>
#include "Board.hpp"
using namespace std;

Board::Board()							//fill the board with placeholders
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '.';
		}
	}
}

/*********************************************************************
** bool Board::makeMove(int x, int y, char player)
** Checks if the coordinates entered are empty or not. Places a mark for
** the currently player and returns true if the space is empty. Returns
** false if the space is occupied.
*********************************************************************/
bool Board::makeMove(int x, int y, char player)
{
	if (board[x][y] == '.')
	{
		board[x][y] = player;
		return true;
	}

	else
	{
		return false;
	}
}

/*********************************************************************
** int Board::gameState()
** Checks the status of the game and returns an integer associated with
** an enumerated state defined in Board.hpp.
*********************************************************************/
int Board::gameState()
{
	int state = 0;				//0 = game in process
	bool full = true;			//flag to check if the board is full

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '.') //if the board contains a placeholder
			{
				full = false;		//the board is not full
			}
		}
	}

	if (state == 0 && full == true) //if no one has won and the board is full
	{
		state = 1;					//the game is a draw
	}

	for (int i = 0; i < 3; i++)		//iterate through board spaces
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) //check vertical wins
		{
			if (board[i][0] == 'x')
			{
				state = 2;
			}

			else if (board[i][0] == 'o')
			{
				state = 3;
			}
		}

		if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) //check horizontal wins
		{
			if (board[0][i] == 'x')
			{
				state = 2;
			}

			else if (board[0][i] == 'o')
			{
				state = 3;
			}
		}
	}

	if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
		(board[0][2] == board[1][1] && board[0][2] == board[2][0])) //check diagonal wins
	{
		if (board[1][1] == 'x')
		{
			state = 2;
		}

		else if (board[1][1] == 'o')
		{
			state = 3;
		}
	}

	switch (state)
	{
	case inProgress: return 0;
		break;
	case draw: return 1;
		break;
	case x: return 2;
		break;
	case o: return 3;
		break;
	default: cout << "panic" << endl;
	}
}

/*********************************************************************
** void Board::print()
** Prints the current game board with coordinates.
*********************************************************************/
void Board::print()
{
	cout << " 012" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i << board[i][0] << board[i][1] << board[i][2] << endl;
	}
}
