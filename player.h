#ifndef L1_S2_QWIRKLE_PLAYER_H
#define L1_S2_QWIRKLE_PLAYER_H

#include "sha256.h"
#include <string.h>
#include "unsigned_char_string.h"
#include <stdio.h>

#define MAXIMUM_NAME_LENGTH 64
#define MAXIMUM_PASSWORD_LENGTH 32


typedef struct{
    char name[MAXIMUM_NAME_LENGTH];
    BYTE pass_hash[SHA256_BLOCK_SIZE];
    int score;
    int pvp_wins;
    int pvp_loses;
    int pvp_draws;
    int is_player;
} Player;

Player init_new_player(char name[MAXIMUM_NAME_LENGTH], BYTE plane_password[MAXIMUM_PASSWORD_LENGTH]);
void scan_player_name(char name[MAXIMUM_NAME_LENGTH]);



#endif //L1_S2_QWIRKLE_PLAYER_H
