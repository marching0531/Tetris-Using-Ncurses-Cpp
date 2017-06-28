#ifndef __INFOPANE_H__
#define __INFOPANE_H__

#include "Pane.h"

class InfoPane:public Pane{

public:
	InfoPane(int x,int y,int w,int h);
	void draw();
	void printLines(int lines);
};

#endif//__INFOPANE_H__
