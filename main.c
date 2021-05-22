#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include "color.h"

void print_help();

int main(int argc, char **argv) {
    assert(argc > 0);
    char args[] = "hn:d:lp:o:";
    int difficulty;
    char *ptr;
    if(argc == 1){
        puts("Here goes plain execution sequence.");
    }
    else{
        // puts("But here i look at arguments.");
        for (int opt = getopt(argc, argv, args); opt!=-1; opt = getopt(argc, argv, args)){
            switch (opt) {
                case 'h':
                    print_help();
                    exit(0);
                    break;
                case 'n':
                    printf("Name : %s.\n", optarg);
                    break;
                case 'd':
                    difficulty = strtol(optarg, &ptr, 10);
                    printf("Difficulty: %d.\n", difficulty);
                    break;
                case 'l':
                    puts("Leaderboard.");
                    break;
                case 'p':
                    puts("PVP mode.");
                    break;
                case ':':
                    printf("There should be parameter after %s\n", argv[optind-1]);
                    exit(1);
                    break;
                case '?':
                    printf("Unrecognized argument: %c\n", optopt);
                    break;
                default:
                    puts("Lol wtf. getopt just return smth wierd");
                    printf("Wierd: %c or %d", opt, opt);
                    exit(2);
                    break;
            }
        }
    }
    return 0;
}

void print_help(){
    // puts("Function that should display help message.");
    printf("      ===== ");
    CONSOLE_COLOR_PRINT("Q ", CONSOLE_COLOR_RED);
    CONSOLE_COLOR_PRINT("W ", CONSOLE_COLOR_GREEN);
    CONSOLE_COLOR_PRINT("I ", CONSOLE_COLOR_BLUE);
    CONSOLE_COLOR_PRINT("R ", CONSOLE_COLOR_YELLOW);
    CONSOLE_COLOR_PRINT("K ", CONSOLE_COLOR_RED);
    CONSOLE_COLOR_PRINT("L ", CONSOLE_COLOR_GREEN);
    CONSOLE_COLOR_PRINT("E ", CONSOLE_COLOR_BLUE);
    puts(" =====");
    puts("Qwirkle project : sub-alfa 1.0");
    puts("Preset:");
    puts("  Draw bag: At the beginning of the game, the 32 tiles are put in a draw bag.");
    puts("  Deck:     Each player picks 6 tiles at random from the draw bag. These 6 tiles form the player’s deck.");
    puts("  Board:    One more tile is picked from the bag and put in the middle of the board.");
    puts("Rules:");
    puts("  The global aim in Qwirkle is to make tile sequences:");
    puts("    Neighbor: Two tiles are neighbors if and only if they have one adjoining edge.");
    puts("              Two tiles with only adjoining corners are not neighbors.");
    puts("    Sequence: A tile sequence is a set of several neighboring tiles on the same line (row or column),");
    puts("              which have the same letter or the same color.");
    puts("              But a sequence cannot contain any identical tiles(same color AND same letter).");
    puts("    Complete: A complete tile sequence is a sequence of four tiles in which all four colors or all four letters appear.");
    puts("");
    //puts("");
    puts("  Each player, in a turn :");
    puts("    1. Chooses one tile from her 2 deck and puts it on the board, ");
    puts("       such that the entire board contains only valid sequences.");
    puts("    2. If she does not have such a tile in her deck, then she skips her turn.");
    puts("    3. If she has put a tile on the board, she picks one tile from the draw bag and adds it to her deck,");
    puts("       so that it contains, again, 6 tiles.");
    puts("");
    //puts("");
    puts("Usage: qwirkle [OPTIONS]");
    puts("Options:");
    puts("  -h:         Displays help and exits with code 0");
    puts("  -n NAME:    Write you name here to save record in local leaderboard.");
    puts("  -d LEVEL:   Let's you choose strength 0-3 of a computer. Default is 2.");
    puts("              Anything lager than 3 is considered 3. Anything lower that 0 is considered 0");
    puts("  -l:         Displays local leaderboard and exits with code 0");
    puts("  -p NAME_P1: PVP mode. Requires player one name and needs -o option afterwards.");
    puts("  -o NAME_P2: Name of the opponent at PVP mode.");
    puts("");
    puts("Examples:");
    puts("  qwirkle");
    puts("  qwirkle -l");
    puts("  qwirkle -d 2 -n Abbas");
    puts("  qwirkle -p Abbas -o Arash");
    puts("");
    //puts("");
}