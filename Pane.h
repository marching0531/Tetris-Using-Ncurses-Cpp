#ifndef __PANE_H__
#define __PANE_H__

#include <ncurses.h>

class Pane{

	public:

	int width_, height_;
	int x_, y_;
	WINDOW *win_;

	Pane(int x,int y,int w,int h);
	~Pane();
	virtual void draw();
	virtual void printLines(int lines);
	virtual void printCounts(int counts[]);
};
#endif //__PANE_H__
