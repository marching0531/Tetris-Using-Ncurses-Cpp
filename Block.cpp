#include "Block.h"
#include "Templates.h"

using namespace std;

Block::Block(WINDOW* win, int num, int row, int col)
{
    rotateCount = 0;
    blockNum = num;
    bringTemplates();
    printBlock(win, blockNum, row, col);
    wrefresh(win);
}

void Block::sendVA(int virtualArray[20][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            localArray[i][j] = virtualArray[i][j];
        }
    }
}

bool Block::isCollide(WINDOW* win, int row, int col) {
    bool collision = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[rotateCount][i][j] == 1) {
                if (localArray[(row - 1) + i][(col - 1) + (j * 2)] != 8)
                    collision = true;
            }
        }
    }
    printBlock(win, blockNum, row, col);
    return !collision;
}

void Block::rotate(WINDOW* win, int row, int col) {
    bool collision = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[rotateCount][i][j] == 2) {
                int y = (row - 1) + i;
                int x = (col - 1) + (j * 2);
                int tmp = localArray[(row - 1) + i][(col - 1) + (j * 2)];
                if (tmp != 8 || x < 0 || x > 19 || y > 21)
                    collision = true;
            }
        }
    }
    if (collision == false)
    printBlock(win, 8, row, col);

    if (rotateCount < 3)
        this->rotateCount++;
    else
        this->rotateCount = 0;
    bringTemplates();
    printBlock(win, blockNum, row, col);
}


bool Block::down(WINDOW* win, int row, int col) {
    bool collision = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[rotateCount][i][j] == 1) {
                if (localArray[row + i][(col - 1) + (j * 2)] != 8)
                    collision = true;
            }
        }
    }
    if (row > (20 - bounds[rotateCount][1]) || collision == true) {
        return false;
    } else {
      printBlock(win, 8, row++, col);
      printBlock(win, blockNum, row, col);
      return true;
    }
}

bool Block::right(WINDOW* win, int row, int col) {
    bool collision = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[rotateCount][i][j] == 1) {
                if (localArray[(row - 1) + i][(col - 1) + (j * 2) + 2] != 8)
                    collision = true;
            }
        }
    }
    if ((col + (bounds[rotateCount][2] * 2)) >= 20 || collision == true) {
        return false;
    } else {
      printBlock(win, 8, row, col);
      col += 2;
      printBlock(win, blockNum, row, col);
        return true;
    }
}

bool Block::left(WINDOW* win, int row, int col) {
    bool collision = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[rotateCount][i][j] == 1) {
                if (localArray[(row - 1) + i][(col - 1) + (j * 2) - 1] != 8)
                    collision = true;
            }
        }
    }
    if ((col + (bounds[rotateCount][0] * 2)) <= 1 || collision == true) {
        return false;
    } else {
      printBlock(win, 8, row, col);
      col -= 2;
      printBlock(win, blockNum, row, col);
        return true;
    }
}

void Block::printBlock(WINDOW *win, int color, int row, int col) {
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_RED, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_BLACK);
    for (int i = 0; i < 4; i++) {
        int tmpcol = col;
        for (int j = 0; j < 4; j++) {
            if (grid[rotateCount][i][j] == 1) {
                wattron(win, COLOR_PAIR(color));
                wmove(win, row, tmpcol);
                waddch(win, ' '|A_REVERSE);
                wmove(win, row, tmpcol + 1);
                waddch(win, ' '|A_REVERSE);
                wattroff(win, COLOR_PAIR(color));
                wrefresh(win);
            }
            tmpcol += 2;
        }
        row++;
    }
}

void Block::bringTemplates() {
    if (blockNum == 1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                grid[rotateCount][i][j] = grid1[rotateCount][i][j];
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++)
                bounds[i][j] = bounds1[i][j];
        }
    }
    if (blockNum == 2) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                grid[rotateCount][i][j] = grid2[rotateCount][i][j];
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++)
                bounds[i][j] = bounds2[i][j];
        }
    }
    if (blockNum == 3) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                grid[rotateCount][i][j] = grid3[rotateCount][i][j];
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++)
                bounds[i][j] = bounds3[i][j];
        }
    }
    if (blockNum == 4) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                grid[rotateCount][i][j] = grid4[rotateCount][i][j];
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++)
                bounds[i][j] = bounds5[i][j];
        }
    }
    if (blockNum == 5) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                grid[rotateCount][i][j] = grid5[rotateCount][i][j];
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++)
                bounds[i][j] = bounds5[i][j];
        }
    }
    if (blockNum == 6) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                grid[rotateCount][i][j] = grid6[rotateCount][i][j];
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++)
                bounds[i][j] = bounds6[i][j];
        }
    }
    if (blockNum == 7) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                grid[rotateCount][i][j] = grid7[rotateCount][i][j];
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++)
                bounds[i][j] = bounds7[i][j];
        }
    }
}
