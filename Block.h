#include <ncurses.h>

using namespace std;
#ifndef BLOCK_H
#define BLOCK_H

class Block {
private:
public:
    int grid[4][4][4];
    int bounds[4][3];
    int localArray[20][20];
    int blockNum;
    int rotateCount;
    int myColor;

    //Description : Default constructor of block object
    //Parameter : None
    Block();

    //Description : Parameter added constructor of block object 
    //Parameter : window to create block, block id, row and column to indicate
    //block's location
    Block(WINDOW* win, int id, int row, int col);

    //Description : To detect collision, Copy current games grid to
    //shared virtual grid
    //Parameter : A two-dimensional integer array to copy
    void sendVA(int virtualArray[20][20]);

    //Description : Collision check method to check if block spawn space
    //is collided with other block
    //Parameter : Window to check collision, and row, column indicating block's location
    bool isCollide(WINDOW* win, int row, int col);

    //Description : Rotate Current Block
    //Parameter : Window to rotate block and row,column indicating block's location
    void rotate(WINDOW* win, int row, int col);


    //Description : Move down Current Block
    //Parameter : Window to move down block and row,column indicating block's location
    bool down(WINDOW* win, int row, int col);

    //Description : Move right Current Block
    //Parameter : Window to move down block and row,column indicating block's location
    bool right(WINDOW* win, int row, int col);

    //Description : Move left Current Block
    //Parameter : Window to move left block and row,column indicating block's location
    bool left(WINDOW* win, int row, int col);

    //Description : Print right color to current block
    //Parameter : Window to print block and color to paint block, and row,column indicating block's location
    void printBlock(WINDOW* win, int color, int row, int col);

    //Description : Bring Predefined each block's template
    //Parameter : None
    void bringTemplates();
};
#endif
