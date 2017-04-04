#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include "Board.hpp"

class TicTacToe
{
private:
	Board myBoard;
	char currentPlayer;

public:
	TicTacToe(char player);
	
	void play();
};

#endif
