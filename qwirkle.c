#include "qwirkle.h"

void qwirkle_game_loop(int difficulty, int pvp_flag){
    printf("Hello and welcome to the ");
    CONSOLE_COLOR_PRINT("Q ", CONSOLE_COLOR_RED);
    CONSOLE_COLOR_PRINT("W ", CONSOLE_COLOR_GREEN);
    CONSOLE_COLOR_PRINT("I ", CONSOLE_COLOR_BLUE);
    CONSOLE_COLOR_PRINT("R ", CONSOLE_COLOR_YELLOW);
    CONSOLE_COLOR_PRINT("K ", CONSOLE_COLOR_ORANGE);
    CONSOLE_COLOR_PRINT("L ", CONSOLE_COLOR_PURPLE);
    CONSOLE_COLOR_PRINT("E ", CONSOLE_COLOR_WHITE);
    puts("!");
    if(!pvp_flag){
        puts("Please, enter your name below. Maximum length is 63 symbols.");
        Player player;
        scan_player_name(player.name);
        qwirkle_computer(difficulty, player);
    } else{

    }
}

void qwirkle_computer(int difficulty, Player player){
    printf("%s\n", player.name);
}

void qwirkle_pvp(Player player1, Player player2){

}