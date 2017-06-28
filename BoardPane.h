#ifndef __BOARDPANE_H__
#define __BOARDPANE_H__

#include "Pane.h"

class BoardPane : public Pane{

public:
        //Description : Parameter added Board Pane constructor
        //Parameter : two integer x,y indicating Board Pane's location and Pane's width, height
	BoardPane(int x,int y,int w,int h);
        
	//Description : Draw Board Pane's own window
        //Parameter : None
	void draw();
};

#endif //__BOARDPANE_H__
