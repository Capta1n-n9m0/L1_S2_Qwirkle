#include "player.h"

void sha2_password_hashing(BYTE plain_password[MAXIMUM_PASSWORD_LENGTH],BYTE sha2_hash_password[SHA256_BLOCK_SIZE]){
    SHA256_CTX ctx;

    sha256_init(&ctx);
    sha256_update(&ctx, plain_password, u_strlen(plain_password));
    sha256_final(&ctx, sha2_hash_password);
}

Player init_new_player(char name[MAXIMUM_NAME_LENGTH], BYTE plain_password[MAXIMUM_PASSWORD_LENGTH]){
    Player result;

    strncpy(result.name, name, MAXIMUM_NAME_LENGTH);

    sha2_password_hashing(plain_password, result.pass_hash);

    result.score = 0;
    result.pvp_wins = 0;
    result.pvp_loses = 0;
    result.pvp_draws = 0;

    return result;
}

void scan_player_name(char name[MAXIMUM_NAME_LENGTH]){
    char buff[MAXIMUM_NAME_LENGTH];
    int len = 0;
    for(char c = (char)getchar(); c != '\n'; c = getchar()){
        if(len == MAXIMUM_NAME_LENGTH - 1) break;
        buff[len] = c;
        len++;
    }
    buff[len] = '\0';
    memcpy(name, buff, MAXIMUM_NAME_LENGTH);
}
