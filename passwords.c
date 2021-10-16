#include "passwords.h"

char symbols[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void get_salt(BYTE *salt){
    for(int ii = 0; ii < DEFAULT_SALT_LENGTH; ii++){
        salt[ii] = symbols[RANDOM() % strlen(symbols)];
    }
    salt[DEFAULT_SALT_LENGTH] = '\0';
}