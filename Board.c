#include "Board.h"

Board createEmptyBoard(int rows, int cols){
    Board res;
    res.board = (Tile **)calloc(rows, sizeof(Tile *));

    res.rows = rows;
    res.cols = cols;

    for(int row = 0; row < rows; row++){
        res.board[row] = (Tile *)calloc(cols, sizeof (Tile));
    }

    return res;
}

bool isTileEmpty(Tile tile){
    return !(tile.c != 0 || tile.letter != 0);
}

bool insertTileInBoard(Board *board, Tile tile, int row, int col){
    if(!((0 <= row && row < board->rows)&&(0 <= col && col < board->cols))) return false;
    if(!isTileEmpty(board->board[row][col])) return false;

    board->board[row][col] = tile;

    return true;
}

void displayBoard(Board board){
    printf("    ");
    for(int col = 0; col < board.cols; col++){
        printf("%3d ", col);
    }
    puts("");
    for(int row = 0; row < board.rows; row++){
        printf("%3d ", row);
        for(int col = 0; col < board.cols; col++){
            printf(" ");
            printf(" ");
            displayTile(&board.board[row][col]);
            printf(" ");
        }
        puts("");
    }
}