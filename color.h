#ifndef L1_S2_QWIRKLE_COLOR_H
#define L1_S2_QWIRKLE_COLOR_H

#include <stdio.h>
#ifdef _WIN32
# include <windows.h>
# define CONSOLE_COLOR_RED 4
# define CONSOLE_COLOR_GREEN 10
# define CONSOLE_COLOR_BLUE 11
# define CONSOLE_COLOR_YELLOW 14
# define CONSOLE_COLOR_RESET 7
# define CONSOLE_COLOR_PRINT(str, color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); printf("%s", str); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)
#else
# define CONSOLE_COLOR_RED "\e[0;31m"
# define CONSOLE_COLOR_GREEN "\e[0;32m"
# define CONSOLE_COLOR_BLUE "\e[0;34m"
# define CONSOLE_COLOR_YELLOW "\e[0;33m"
# define CONSOLE_COLOR_RESET "\e[0m"
# define CONSOLE_COLOR_PRINT(str, color) printf(color "%s" "\e[0m", str)
#endif

#endif //L1_S2_QWIRKLE_COLOR_H
