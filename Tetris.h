#ifndef TETRIS_H
#define TETRIS_H

#include "Pane.h"
#include "Block.h"

class Tetris{

Pane *infoPane_, *helpPane_, *nextPane_, *boardPane_, *statPane_;
Block *currentBlock, *nextBlock;

public:
	Tetris();
	~Tetris();
	void play();
	void updateScreen();
	void checkRows(WINDOW* win_);
	void reDraw(WINDOW* win_);
};

#endif //TETRIS_H
