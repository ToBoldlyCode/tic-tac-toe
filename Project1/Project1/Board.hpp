#ifndef BOARD_HPP
#define BOARD_HPP

enum stateEnum {inProgress, draw, x, o};

class Board
{
private:
	char board[3][3];

public:
	Board();

	bool makeMove(int x, int y, char player);

	int gameState();
	void print();
};

#endif
