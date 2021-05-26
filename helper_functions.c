#include "helper_functions.h"

void scan_string(char *str, int max_len){
    char *buff = (char * ) malloc(max_len + 2);
    int len = 0;
    for(char c = (char)getchar(); c != '\n'; c = getchar()){
        if(len == max_len - 1) break;
        buff[len] = c;
        len++;
    }
    buff[len] = '\0';
    memcpy(str, buff, max_len);

    free(buff);
}