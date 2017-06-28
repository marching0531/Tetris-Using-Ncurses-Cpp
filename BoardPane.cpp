#include <ncurses.h>
#include "BoardPane.h"

BoardPane::BoardPane(int x,int y,int w,int h) : Pane(x,y,w,h){}

void BoardPane::draw(){
                wattron(win_, COLOR_PAIR(11));
                box(win_,0,0);
                wborder(win_, 0, 0, 0, 0, 0, 0, 0, 0);
		            wattroff(win_,COLOR_PAIR(11));
                wrefresh(win_);
}
