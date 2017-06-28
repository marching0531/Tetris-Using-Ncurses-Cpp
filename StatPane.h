#ifndef __STATPANE_H__
#define __STATPANE_H__

#include "Pane.h"

class StatPane : public Pane{

public:
	StatPane(int x,int y,int w,int h);
	void draw();
	void printCounts(int counts[]);
};

#endif //__STATPANE_H__
