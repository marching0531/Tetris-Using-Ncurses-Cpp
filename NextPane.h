#ifndef __NEXTPANE_H__
#define __NEXTPANE_H__

#include "Pane.h"

class NextPane : public Pane{

public:
        NextPane(int x,int y,int w,int h);

        void draw();
};

#endif//__NEXTPANE_H__
