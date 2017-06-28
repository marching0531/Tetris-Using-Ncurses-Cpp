#ifndef __INFOPANE_H__
#define __INFOPANE_H__

#include "Pane.h"

class InfoPane:public Pane{

public:
        //Description : Parameter added Info Pane constructor
        //Parameter : two integer x,y indicating Info Pane's location and Pane's width, height
	InfoPane(int x,int y,int w,int h);

        //Description : Draw Info Pane's own window
        //Parameter : None
	void draw();
	
        //Description : Print current completed lines and score
        //Parameter : One integer of Current completed line number
	void printLines(int lines);
};

#endif//__INFOPANE_H__
