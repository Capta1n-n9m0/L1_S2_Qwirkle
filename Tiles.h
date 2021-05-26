#ifndef L1_S2_QWIRKLE_TILES_H
#define L1_S2_QWIRKLE_TILES_H

#include "Tile.h"
#include <stdlib.h>

typedef struct linkedTile_{
    Tile *tile;
    struct linkedTile_ *next;
}linkedTile;

typedef struct {
    int numberOfTiles;
    linkedTile *firstTile;
}Bag;

Bag *createBagOfTiles(int n);

#endif //L1_S2_QWIRKLE_TILES_H
