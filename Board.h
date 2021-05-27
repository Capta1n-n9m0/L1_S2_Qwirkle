#ifndef L1_S2_QWIRKLE_BOARD_H
#define L1_S2_QWIRKLE_BOARD_H

#include "Tile.h"
#include "color.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    Tile **board;
    int rows;
    int cols;
}Board;

bool insertTileInBoard(Board *board, Tile tile, int row, int col);

Board createEmptyBoard(int rows, int cols);

void displayBoard(Board board);

#endif //L1_S2_QWIRKLE_BOARD_H
