#ifndef __BOARDPANE_H__
#define __BOARDPANE_H__

#include "Pane.h"

class BoardPane : public Pane{

public:
	BoardPane(int x,int y,int w,int h);
	void draw();
};

#endif //__BOARDPANE_H__
