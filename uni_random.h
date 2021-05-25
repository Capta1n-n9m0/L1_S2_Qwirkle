#ifndef L1_S2_QWIRKLE_UNI_RANDOM_H
#define L1_S2_QWIRKLE_UNI_RANDOM_H

#include <stdlib.h>
#ifdef _WIN32
# define RANDOM() rand()
# define SRANDOM(n) srand()
#else
# define RANDOM() random()
# define SRANDOM(n) srandom()
#endif

#endif //L1_S2_QWIRKLE_UNI_RANDOM_H
