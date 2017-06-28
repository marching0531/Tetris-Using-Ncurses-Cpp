#include <ncurses.h>
#include "StatPane.h"

StatPane::StatPane(int x,int y,int w,int h) : Pane(x,y,w,h){}

void StatPane::draw(){
                init_pair(13, COLOR_CYAN, COLOR_BLACK);
                wattron(win_, COLOR_PAIR(13));
                box(win_, 0, 0);
                mvwprintw(win_, 0, 7, "STATISTICS");
                wattroff(win_,COLOR_PAIR(13));

                init_pair(1, COLOR_CYAN, COLOR_BLACK);
                wattron(win_, COLOR_PAIR(1));
                mvwhline(win_, 1, 2, ACS_CKBOARD, 6);
                mvwprintw(win_, 1, 12, "--");
                mvwprintw(win_, 1, 16, "0");
                wattroff(win_,COLOR_PAIR(1));
                wrefresh(win_);

		            init_pair(2, COLOR_BLUE, COLOR_BLACK);
                wattron(win_, COLOR_PAIR(2));
                mvwhline(win_, 4, 2, ACS_CKBOARD, 6);
                mvwprintw(win_, 4, 12, "--");
                mvwprintw(win_, 4, 16, "0");
                mvwhline(win_, 3, 2, ACS_CKBOARD, 2);
                wattroff(win_,COLOR_PAIR(2));
		            wrefresh(win_);

                init_pair(4, COLOR_YELLOW, COLOR_BLACK);
                wattron(win_, COLOR_PAIR(4));
                mvwhline(win_, 6, 2, ACS_CKBOARD, 4);
                mvwhline(win_, 7, 2, ACS_CKBOARD, 4);
                mvwprintw(win_, 6, 12, "--");
                mvwprintw(win_, 6, 16, "0");
                wattroff(win_,COLOR_PAIR(4));

                init_pair(5, COLOR_GREEN, COLOR_BLACK);
                wattron(win_, COLOR_PAIR(5));
                mvwhline(win_, 9, 4, ACS_CKBOARD, 4);
                mvwhline(win_, 10, 2, ACS_CKBOARD, 4);
                mvwprintw(win_, 9, 12, "--");
                mvwprintw(win_, 9, 16, "0");
		            mvwhline(win_, 20,1,ACS_HLINE,width_-2);
                mvwprintw(win_, 21, 2, "Sum 	:	");
                wattroff(win_,COLOR_PAIR(5));

		            init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
                wattron(win_, COLOR_PAIR(6));
                mvwhline(win_, 12, 4, ACS_CKBOARD, 2);
                mvwhline(win_, 13, 2, ACS_CKBOARD, 6);
                mvwprintw(win_, 12, 12, "--");
                mvwprintw(win_, 12, 16, "0");
                wattroff(win_,COLOR_PAIR(6));

		            init_pair(7, COLOR_RED, COLOR_BLACK);
                wattron(win_, COLOR_PAIR(7));
                mvwhline(win_, 15, 2, ACS_CKBOARD, 4);
                mvwhline(win_, 16, 4, ACS_CKBOARD, 4);
                mvwprintw(win_, 15, 12, "--");
                mvwprintw(win_, 15, 16, "0");
                wattroff(win_,COLOR_PAIR(7));

		            init_pair(3, COLOR_WHITE, COLOR_BLACK);
                wattron(win_, COLOR_PAIR(3));
                mvwhline(win_, 18, 6, ACS_CKBOARD, 2);
                mvwhline(win_, 19, 2, ACS_CKBOARD, 6);
                mvwprintw(win_, 18, 12, "--");
                mvwprintw(win_, 18, 16, "0");
                wattroff(win_,COLOR_PAIR(3));

		wrefresh(win_);


}

void StatPane::printCounts(int counts[]){

    int sum=0;
    mvprintw(2, 71, "%d", counts[0]);sum+=counts[0];
    mvprintw(5, 71, "%d", counts[1]);sum+=counts[1];
    mvprintw(7, 71, "%d", counts[3]);sum+=counts[3];
    mvprintw(10, 71, "%d", counts[4]);sum+=counts[4];
    mvprintw(13, 71, "%d", counts[5]);sum+=counts[5];
    mvprintw(16, 71, "%d", counts[6]);sum+=counts[6];
    mvprintw(19, 71, "%d", counts[2]);sum+=counts[2];

    mvprintw(22, 71, "%d", sum);


}
