#include "TicTacToe.hpp"
#include <iostream>
#include <string>
using namespace std;

/*********************************************************************
** TicTacToe::TicTacToe(char player)
** Constructor for the user to set the first player.
*********************************************************************/
TicTacToe::TicTacToe(char player)
{
	currentPlayer = player;
}

/*********************************************************************
** void TicTacToe::play()
** Starts the game and loops until there is a win or draw, then declares
** the outcome.
*********************************************************************/
void TicTacToe::play()
{
	int a,
		b;


	while (myBoard.gameState() == inProgress)
	{
		myBoard.print();
		cout << "Player " << currentPlayer << ": please enter your move." << endl;
		cin.clear();
		cin >> a >> b;

		//Keep looping if the player enters an occupied space
		while (myBoard.makeMove(a, b, currentPlayer) == false)
		{
			cout << "That square is already taken" << endl;
			cout << "Player " << currentPlayer << ": please enter your move." << endl;
			cin.clear();
			cin >> a >> b;
		}

		myBoard.makeMove(a, b, currentPlayer);

		//switch players
		if (currentPlayer == 'x')
		{
			currentPlayer = 'o';
		}

		else if (currentPlayer == 'o')
		{
			currentPlayer = 'x';
		}

		myBoard.gameState();
	}

	//When the game is no longer in progress, state the outcome
	switch (myBoard.gameState())
	{
	case draw: cout << "the game is a draw" << endl;
		break;
	case x: cout << "\'x\' has won" << endl;
		break;
	case o: cout << "\'o\' has won" << endl;
		break;
	default: cout << "Error." << endl;
	}
}

int main()
{
	char firstPlayer;

	cout << "Which player should go first? Enter x or o" << endl;
	cin >> firstPlayer;

	TicTacToe myGame(firstPlayer);
	myGame.play();

	return 0;
}