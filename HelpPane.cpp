#include <ncurses.h>
#include "HelpPane.h"

HelpPane::HelpPane(int x,int y,int w,int h) : Pane(x,y,w,h){}

void HelpPane::draw(){
              	init_pair(11, COLOR_WHITE, COLOR_BLACK);
                wattron(win_, COLOR_PAIR(11));
		box(win_,0,0);

                mvwprintw(win_,0,8,"HELP PANE");
                mvwprintw(win_,2,2,"LEFT ARROW : Left");
                mvwprintw(win_,4,2,"RIGHT ARROW : Right");
                mvwprintw(win_,6,2,"DOWN ARROW : Down");
                mvwprintw(win_,8,2,"UP ARROW : Rotate");
                mvwprintw(win_,10,2,"q : Quit");
                wattroff(win_,COLOR_PAIR(11));
                wrefresh(win_);
}
