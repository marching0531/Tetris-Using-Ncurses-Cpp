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
        //Description : Default Tetris game constructor
        //Parameter : None
	Tetris();

        //Description : Default Tetris game Destructor
        //Parameter : None
	~Tetris();

        //Description : Method to Play Tetris game
        //Parameter : None
	void play();

        //Description : Update each Pane of tetris game
        //Parameter : None
	void updateScreen();

        //Description : Check all of rows of the game window to see
	//if that there are any completed rows
        //Parameter : Window to check
	void checkRows(WINDOW* win_);

        //Description : Redraw game window after any adjustment
        //Parameter : Window to Redraw
	void reDraw(WINDOW* win_);

        //Description : Signal handler for the game clock
        //Parameter : None
	static void alarmFunc(int signal);
};

#endif //TETRIS_H
