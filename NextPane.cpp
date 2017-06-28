#include <ncurses.h>
#include "NextPane.h"

NextPane::NextPane(int x,int y,int w,int h) : Pane(x,y,w,h){}

void NextPane::draw(){
              	init_pair(12, COLOR_BLUE, COLOR_BLACK);
                wattron(win_, COLOR_PAIR(12));
		box(win_, 0,0);
                mvwprintw(win_,0,8,"NEXT PANE");
                wattroff(win_,COLOR_PAIR(12));
                wrefresh(win_);
}
