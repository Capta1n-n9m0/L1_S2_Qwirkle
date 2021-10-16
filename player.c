#include "player.h"


void sha2_password_hashing(BYTE *plain_password,BYTE sha2_hash_password[SHA256_BLOCK_SIZE]){
    SHA256_CTX ctx;

    sha256_init(&ctx);
    sha256_update(&ctx, plain_password, u_strlen(plain_password));
    sha256_final(&ctx, sha2_hash_password);
}

password sha2_salted_100000iter(BYTE plain_password[MAXIMUM_PASSWORD_LENGTH]){
    password res;

    char buf[MAXIMUM_PASSWORD_LENGTH+DEFAULT_SALT_LENGTH+1];
    get_salt(res.salt);
    strncpy(buf, plain_password, MAXIMUM_PASSWORD_LENGTH);
    strncat(buf, res.salt, DEFAULT_SALT_LENGTH);
    sha2_password_hashing(buf, res.hash);
    for(int ii = 1; ii < 100000; ii++) {
        sha2_password_hashing(res.hash, res.hash);
    }

    return res;
}

Player scan_player(){
    char name[MAXIMUM_NAME_LENGTH+1];
    char plain_pass1[MAXIMUM_PASSWORD_LENGTH+1];
    char plain_pass2[MAXIMUM_PASSWORD_LENGTH+1];
    puts("Now you will start user registration process.\n"
         "You will need username(64 chars max) and password(32 chars max).");
    printf("Username: ");
    scan_player_name(name);
    printf("Password: ");
    scan_password(plain_pass1, MAXIMUM_PASSWORD_LENGTH);
    printf("Confirm password: ");
    scan_password(plain_pass2, MAXIMUM_PASSWORD_LENGTH);
    while (strncmp(plain_pass1, plain_pass2, MAXIMUM_PASSWORD_LENGTH) != 0){
        puts("Entered password are not equal! Try again.");
        printf("Password: ");
        scan_password(plain_pass1, MAXIMUM_PASSWORD_LENGTH);
        printf("Confirm password: ");
        scan_password(plain_pass2, MAXIMUM_PASSWORD_LENGTH);
    }
    Player res = init_new_player(name, plain_pass1);
    printf("Welcome, %s!", res.name);
    return res;
}

Player init_new_player(char name[MAXIMUM_NAME_LENGTH], BYTE plain_password[MAXIMUM_PASSWORD_LENGTH]){
    Player result;

    strncpy(result.name, name, MAXIMUM_NAME_LENGTH);

    result.pass = sha2_salted_100000iter(plain_password);

    result.score = 0;
    result.pvp_wins = 0;
    result.pvp_loses = 0;
    result.pvp_draws = 0;

    return result;
}

void scan_player_name(char name[]){
    scan_string(name, MAXIMUM_NAME_LENGTH);
}

void print_player(FILE *f, Player p){
    fprintf(f, "| %s | ", p.name);
    for(int ii = 0; ii < SHA256_BLOCK_SIZE; ii++){
        fprintf(f, "%x", p.pass.hash[ii]);
    }
    fprintf(f, " | %s |\n", p.pass.salt);
}

void scan_password(char *str, int max_len){
    char *buff = (char * ) malloc(max_len + 2);
    int len = 0;
    for(char c = (char)getchar(); c != '\n'; c = (char)getchar()){
        if(len == max_len - 1) break;
        buff[len] = c;
        len++;
    }
    buff[len] = '\0';
    memcpy(str, buff, max_len);
    fflush(stdin);

    free(buff);
}

