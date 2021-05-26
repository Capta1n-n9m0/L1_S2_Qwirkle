#ifndef L1_S2_QWIRKLE_COLOR_H
#define L1_S2_QWIRKLE_COLOR_H

#include <stdio.h>
#ifdef _WIN32
# include <windows.h>
# define CONSOLE_COLOR_RED 4
# define CONSOLE_COLOR_GREEN 10
# define CONSOLE_COLOR_BLUE 9
# define CONSOLE_COLOR_YELLOW 14
# define CONSOLE_COLOR_ORANGE 6
# define CONSOLE_COLOR_PURPLE 13
# define CONSOLE_COLOR_WHITE 15
# define CONSOLE_COLOR_RESET 7
# define CONSOLE_COLOR_PRINT(str, color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); printf("%s", str); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)
# define CONSOLE_COLOR_PRINTC(char_, color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); printf("%c", char_); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)
#else
# define CONSOLE_COLOR_RED "\e[0;31m\e[40m"
# define CONSOLE_COLOR_GREEN "\e[0;32m\e[40m"
# define CONSOLE_COLOR_BLUE "\e[0;34m\e[40m"
# define CONSOLE_COLOR_YELLOW "\e[38;5;11m\e[40m"
# define CONSOLE_COLOR_ORANGE "\e[0;33m\e[40m"
# define CONSOLE_COLOR_PURPLE "\e[38;5;5m\e[40m"
# define CONSOLE_COLOR_WHITE "\e[0;37m\e[40m"
# define CONSOLE_COLOR_RESET "\e[0m"
# define CONSOLE_COLOR_PRINT(str, color) printf(color "%s" "\e[0m", str)
# define CONSOLE_COLOR_PRINTc(char_, color) printf(color "%c" "\e[0m", char_)
#endif

#define COLORCODE_RED       1
#define COLORCODE_GREEN     2
#define COLORCODE_BLUE      3
#define COLORCODE_YELLOW    4
#define COLORCODE_ORANGE    5
#define COLORCODE_PURPLE    6
#define COLORCODE_WHITE     7
#define COLORCODE_UNKNOWN   7

typedef unsigned char color;

typedef struct colored_letter_ {
    char letter;
    color c;
}colored_letter;

colored_letter color_letter(char letter, char *color_str);
void print_colored_letter(colored_letter letter);

#endif //L1_S2_QWIRKLE_COLOR_H
