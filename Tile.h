#ifndef L1_S2_QWIRKLE_TILE_H
#define L1_S2_QWIRKLE_TILE_H

#include "color.h"
#include <assert.h>
#include "helper_functions.h"

typedef colored_letter Tile;

Tile *createTile(char letter, const char* color_str);
void displayTile(const Tile *tile);
void freeTile(Tile *tile);

#endif //L1_S2_QWIRKLE_TILE_H
