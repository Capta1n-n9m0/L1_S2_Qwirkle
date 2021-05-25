#include "unsigned_char_string.h"

int u_strlen(const unsigned char * string){
    int length;
    for(length = 0; string[length]; length++);
    return length;
}