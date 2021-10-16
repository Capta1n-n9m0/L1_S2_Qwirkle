#ifndef L1_S2_QWIRKLE_PASSWORDS_H
#define L1_S2_QWIRKLE_PASSWORDS_H

#include "sha256.h"
#include "uni_random.h"
#include <string.h>

#define DEFAULT_SALT_LENGTH 16

typedef struct {
    BYTE hash[SHA256_BLOCK_SIZE+1];
    BYTE salt[DEFAULT_SALT_LENGTH+1];
}password;

void get_salt(BYTE *salt);


#endif //L1_S2_QWIRKLE_PASSWORDS_H
