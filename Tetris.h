#ifndef TETRIS_H
#define TETRIS_H

#include <signal.h>
#include <sys/time.h>
#include <time.h>

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
	static void alarmFunc(int signal);
};

#endif //TETRIS_H
