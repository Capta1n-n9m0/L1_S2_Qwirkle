#ifndef L1_S2_QWIRKLE_QWIRKLE_H
#define L1_S2_QWIRKLE_QWIRKLE_H

#include "player.h"
#include <stdio.h>
#include "color.h"
#include "helper_functions.h"
#include "Tile.h"
#include "Tiles.h"
#include "Board.h"

void qwirkle_game_loop(int difficulty, int pvp_flag);

void qwirkle_computer(int difficulty, Player player);

void qwirkle_pvp(Player player1, Player player2);

#endif //L1_S2_QWIRKLE_QWIRKLE_H
