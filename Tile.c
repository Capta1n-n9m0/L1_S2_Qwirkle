#include "Tile.h"

Tile *createTile_p(const char letter, const char* color_str){
    if(!('A' <= letter && letter <= 'D')){
        SLEEP(0.5);
        fprintf(stderr, "Illegal letter %c!\n", letter);
        assert(0);
    }
    Tile *res = (Tile *)malloc(sizeof(Tile));
    res->letter = letter;
    if(strcmp(color_str, "red")==0)
        res->c = COLORCODE_RED;
    else if(strcmp(color_str, "green")==0)
        res->c = COLORCODE_GREEN;
    else if(strcmp(color_str, "blue")==0)
        res->c = COLORCODE_BLUE;
    else if(strcmp(color_str, "yellow")==0)
        res->c = COLORCODE_YELLOW;
    else {
        SLEEP(0.5);
        fprintf(stderr, "Unrecognised color: %s!\n", color_str);
        assert(0);
    }
    return res;
}

Tile createTile(char letter, const char* color_str){
    if(!('A' <= letter && letter <= 'D')){
        SLEEP(0.5);
        fprintf(stderr, "Illegal letter %c!\n", letter);
        assert(0);
    }
    Tile res;
    res.letter = letter;
    if(strcmp(color_str, "red")==0)
        res.c = COLORCODE_RED;
    else if(strcmp(color_str, "green")==0)
        res.c = COLORCODE_GREEN;
    else if(strcmp(color_str, "blue")==0)
        res.c = COLORCODE_BLUE;
    else if(strcmp(color_str, "yellow")==0)
        res.c = COLORCODE_YELLOW;
    else {
        SLEEP(0.5);
        fprintf(stderr, "Unrecognised color: %s!\n", color_str);
        assert(0);
    }
    return res;
}

void displayTile(const Tile *tile){
    if(!('A' <= tile->letter && tile->letter <= 'D')){
        SLEEP(0.5);
        fprintf(stderr, "Illegal letter %c!\n", tile->letter);
        assert(0);
    }
    switch (tile->c) {
        case COLORCODE_RED:
            CONSOLE_COLOR_PRINTC(tile->letter, CONSOLE_COLOR_RED);
            break;
        case COLORCODE_GREEN:
            CONSOLE_COLOR_PRINTC(tile->letter, CONSOLE_COLOR_GREEN);
            break;
        case COLORCODE_BLUE:
            CONSOLE_COLOR_PRINTC(tile->letter, CONSOLE_COLOR_BLUE);
            break;
        case COLORCODE_YELLOW:
            CONSOLE_COLOR_PRINTC(tile->letter, CONSOLE_COLOR_YELLOW);
            break;
        default:
            SLEEP(0.5);
            fprintf(stderr, "Unrecognised color code: %d!\n", tile->c);
            assert(0);
            break;
    }
}

void freeTile(Tile *tile){
    tile->letter = 0;
    tile->c = 0;
    free(tile);
}