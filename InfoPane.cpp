#include <ncurses.h>
#include "InfoPane.h"

InfoPane::InfoPane(int x,int y,int w,int h) : Pane(x,y,w,h){}

void InfoPane::draw(){
                init_pair(9, COLOR_GREEN, COLOR_BLACK);
                wattron(win_, COLOR_PAIR(9));
		box(win_, 0, 0);
                mvwprintw(win_,0,8,"INFO PANE");
                mvwprintw(win_,2,2,"Full Lines : ");
		wattroff(win_, COLOR_PAIR(9));
		init_pair(10,COLOR_RED, COLOR_BLACK);
		wattron(win_, COLOR_PAIR(10));
                mvwprintw(win_,3,4,"SCORE : ");
		wattroff(win_, COLOR_PAIR(10));
                wrefresh(win_);
}

void InfoPane::printLines(int lines){
  mvprintw(3, 16, "%d", lines);
  mvprintw(4, 16, "%d", lines*10);

}
