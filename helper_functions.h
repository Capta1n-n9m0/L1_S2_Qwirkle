#ifndef L1_S2_QWIRKLE_HELPER_FUNCTIONS_H
#define L1_S2_QWIRKLE_HELPER_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
# include <windows.h>
# define SLEEP(s) Sleep((int)(s*1000))
#else
# include <unistd.h>
# define SLEEP(s) sleep(s)
#endif


void scan_string(char *str, int max_len);

#endif //L1_S2_QWIRKLE_HELPER_FUNCTIONS_H
