#ifndef L1_S2_QWIRKLE_TILES_H
#define L1_S2_QWIRKLE_TILES_H

#include "Tile.h"
#include <stdlib.h>
#include "uni_random.h"
#include "color.h"

typedef struct linkedTile_{
    Tile tile;
    struct linkedTile_ *next;
}linkedTile;

typedef struct {
    int numberOfTiles;
    linkedTile *firstTile;
}Bag;

void addNewTileToBag(Bag *bag, Tile tile);

Bag *createBagWithTiles(int n);
Bag *createEmptyBag();
void emptyBag(Bag *bag);
Tile popRandomTileFromBag(Bag *bag);
void displayBag(Bag *bag);
Bag *getDeckFromBag(Bag *bag, int n);
Tile popFromBag(Bag *bag, int n);

#endif //L1_S2_QWIRKLE_TILES_H
