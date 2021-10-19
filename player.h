#ifndef L1_S2_QWIRKLE_PLAYER_H
#define L1_S2_QWIRKLE_PLAYER_H

#include "sha256.h"
#include <string.h>
#include "unsigned_char_string.h"
#include <stdio.h>
#include "passwords.h"
#include "helper_functions.h"
#include <conio.h>

#define MAXIMUM_NAME_LENGTH 64
#define MAXIMUM_PASSWORD_LENGTH 32

typedef struct{
    char name[MAXIMUM_NAME_LENGTH+1];
    password pass;
    int score;
    int pvp_wins;
    int pvp_loses;
    int pvp_draws;
    int is_player;
} Player;

Player scan_player();
Player init_new_player(char name[MAXIMUM_NAME_LENGTH], BYTE plane_password[MAXIMUM_PASSWORD_LENGTH]);
void scan_player_name(char name[MAXIMUM_NAME_LENGTH]);
void print_player(FILE *f, Player p);
void scan_password(char *str, int max_len);
void save_player(FILE *f, Player p);



#endif //L1_S2_QWIRKLE_PLAYER_H
