#ifndef __HELPPANE_H__
#define __HELPPANE_H__

#include "Pane.h"

class HelpPane : public Pane{

public :
        //Description : Parameter added Help Pane constructor
        //Parameter : two integer x,y indicating Board Pane's location and Pane's width, height
	HelpPane(int x,int y,int w,int h);

        //Description : Draw Help Pane's own window
        //Parameter : None
	void draw();

};

#endif //__HELPPANE_H__
