#include "color.h"

colored_letter color_letter(char letter, char *color_str){
    color c;
    colored_letter res;
    if(strcmp(color_str, "red")==0)
        c = COLORCODE_RED;
    else if(strcmp(color_str, "green")==0)
        c = COLORCODE_GREEN;
    else if(strcmp(color_str, "blue")==0)
        c = COLORCODE_BLUE;
    else if(strcmp(color_str, "yellow")==0)
        c = COLORCODE_YELLOW;
    else if(strcmp(color_str, "purple")==0)
        c = COLORCODE_PURPLE;
    else if(strcmp(color_str, "orange")==0)
        c = COLORCODE_ORANGE;
    else if(strcmp(color_str, "white")==0)
        c = COLORCODE_WHITE;
    // no black color here, because background is black
    else
        c = COLORCODE_WHITE;
    res.letter = letter;
    res.c = c;
    return res;
}

void print_colored_letter(colored_letter letter){
    switch (letter.c) {
        case COLORCODE_RED:
            CONSOLE_COLOR_PRINTC(letter.letter, CONSOLE_COLOR_RED);
            break;
        case COLORCODE_GREEN:
            CONSOLE_COLOR_PRINTC(letter.letter, CONSOLE_COLOR_GREEN);
            break;
        case COLORCODE_BLUE:
            CONSOLE_COLOR_PRINTC(letter.letter, CONSOLE_COLOR_BLUE);
            break;
        case COLORCODE_YELLOW:
            CONSOLE_COLOR_PRINTC(letter.letter, CONSOLE_COLOR_YELLOW);
            break;
        case COLORCODE_PURPLE:
            CONSOLE_COLOR_PRINTC(letter.letter, CONSOLE_COLOR_PURPLE);
            break;
        case COLORCODE_ORANGE:
            CONSOLE_COLOR_PRINTC(letter.letter, CONSOLE_COLOR_ORANGE);
            break;
        case COLORCODE_WHITE:
            CONSOLE_COLOR_PRINTC(letter.letter, CONSOLE_COLOR_WHITE);
            break;
        default:
            CONSOLE_COLOR_PRINTC(letter.letter, CONSOLE_COLOR_WHITE);
            break;
    }
}