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

    Block();

    Block(WINDOW* win, int id, int row, int col);

    void sendVA(int virtualArray[20][20]);

    bool isCollide(WINDOW* win, int row, int col);

    void rotate(WINDOW* win, int row, int col);

    bool down(WINDOW* win, int row, int col);

    bool right(WINDOW* win, int row, int col);

    bool left(WINDOW* win, int row, int col);

    void printBlock(WINDOW* win, int color, int row, int col);

    void bringTemplates();
};
#endif
