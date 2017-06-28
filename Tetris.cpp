#include <ncurses.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include "Pane.h"
#include "InfoPane.h"
#include "HelpPane.h"
#include "NextPane.h"
#include "BoardPane.h"
#include "StatPane.h"
#include "Tetris.h"
#include "Block.h"

static int virtualArray[20][20];
int lines;
int counts[7];
bool moveDown = false;

Tetris::Tetris(){
                initscr();
                start_color();
                cbreak();
                refresh();

                infoPane_ = new InfoPane(1,1,25,5);
                helpPane_ = new HelpPane(1,6,25,12);
                nextPane_ = new NextPane(1,18,25,5);
                boardPane_ = new BoardPane(30,0,22,22);
                statPane_ = new StatPane(55,1,25,23);
                }

Tetris::~Tetris(){
                delete infoPane_;
                delete helpPane_;
                delete nextPane_;
                delete boardPane_;
                delete statPane_;
                endwin();
                }

void Tetris::play(){

    int input = 0;
    updateScreen();
		curs_set(0);
		noecho();
		keypad(stdscr, TRUE);

		bool isPlay = true;

		while(isPlay) {

			for(int i = 0; i < 20; i++){
				for(int j = 0; j < 20; j++){
					virtualArray[i][j] = 8;
				}
			}

		reDraw(boardPane_->win_);

    srand(time(NULL));

    int counts[7] = {0};
    int blockNum = rand() % 7 +1;
    counts[blockNum-1]++;
    statPane_->printCounts(counts);
    bool isAlive = true;
    int lines=0;
    infoPane_->printLines(lines);
		Block* currentBlock = new Block(boardPane_->win_, blockNum, 1,7);
		currentBlock -> sendVA(virtualArray);
		int count = 0;

		while(input != 'q' && isAlive == true){
			bool set = false;
			int x = 7;
			int y = 1;

			werase(nextPane_->win_);
			nextPane_->draw();
			wrefresh(nextPane_->win_);
			wrefresh(boardPane_->win_);

			blockNum = rand() % 7 + 1;
      counts[blockNum-1]++;
			Block* nextBlock = new Block(nextPane_->win_,blockNum,2,9);
			isAlive = currentBlock -> isCollide(boardPane_->win_,y,x);

			while (input != 'q' && set == false){
					if (input == KEY_UP) {
                    currentBlock->rotate(boardPane_->win_, y, x);
                } else if (input == KEY_RIGHT) {
                    if (currentBlock->right(boardPane_->win_, y, x))
                        x += 2;
                } else if (input == KEY_LEFT) {
                    if (currentBlock->left(boardPane_->win_, y, x))
                        x -= 2;
                } else if ((moveDown || input == KEY_DOWN) && y < 20) {
                    if (!currentBlock->down(boardPane_->win_, y, x)) {
                        set = true;
                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            if (currentBlock->grid[currentBlock->rotateCount][i][j] == 1) {
                                virtualArray[(y - 1) + i][(x - 1) + (j * 2)] = currentBlock->blockNum;
                                virtualArray[(y - 1) + i][(x - 1) + (j * 2) + 1] = currentBlock->blockNum;
                            }
                        }
                    }
                    checkRows(boardPane_->win_);
                    reDraw(boardPane_->win_);
                    } else {
                        y++;
                    }
		    moveDown = false;
      } else if (input == ' ') {
		    while (currentBlock->down(boardPane_->win_, y, x))
		        y++;
		    set = true;
		    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            if (currentBlock->grid[currentBlock->rotateCount][i][j] == 1) {
                                virtualArray[(y - 1) + i][(x - 1) + (j * 2)] = currentBlock->blockNum;
                                virtualArray[(y - 1) + i][(x - 1) + (j * 2) + 1] = currentBlock->blockNum;
                            }
                        }
                    }
		    checkRows(boardPane_->win_);
                    reDraw(boardPane_->win_);
	        }

                input = getch();
            }
            currentBlock = nextBlock;
            statPane_->printCounts(counts);
            currentBlock->sendVA(virtualArray);
        }

            if (input != 'q') {
                bool response = false;
                while (!response) {
                    input = getch();
                    if (input == 'q') {
                        response = true;
                        isPlay = false;
                    }
                }
            } else {
                isPlay = false;
            }
        }

    endwin();
}

void Tetris::updateScreen(){
                infoPane_->draw();
                helpPane_->draw();
                nextPane_->draw();
                boardPane_->draw();
                statPane_->draw();
                }

void Tetris::checkRows(WINDOW* win_){
  for(int i=0;i<20;i++){
    bool hole = false;
    for(int j = 0; j<20; j++){
      if(virtualArray[i][j] == 8)
      hole = true;
    }
    if (hole == false){
      for(int l=i; l>0; l--){
        for(int k = 0; k<20; k++){
          virtualArray[l][k] = virtualArray[l-1][k];
        }
      }
      lines++;
      infoPane_->printLines(lines);
    }
  }
}


void Tetris::reDraw(WINDOW* win_){
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_GREEN, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_RED, COLOR_BLACK);
  init_pair(8, COLOR_BLACK, COLOR_BLACK);

  for (int i = 0; i < 20; i ++) {
      for (int j = 0; j < 20; j++) {
          wattron(win_, COLOR_PAIR(virtualArray[i][j]));
          wmove(win_, i + 1, j + 1);
          waddch(win_, ' '|A_REVERSE);
          wattroff(win_, COLOR_PAIR(virtualArray[i][j]));
          wrefresh(win_);
      }
  }
}
