#ifndef __NEXTPANE_H__
#define __NEXTPANE_H__

#include "Pane.h"

class NextPane : public Pane{

public:
        //Description : Parameter added Next Pane constructor
        //Parameter : two integer x,y indicating Next Pane's location and Pane's width, height
        NextPane(int x,int y,int w,int h);

        //Description : Draw Next Pane's own window
        //Parameter : None
        void draw();
};

#endif//__NEXTPANE_H__
