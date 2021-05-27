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
    char color[20], c;
    colored_letter letter;
    while(1){
        // printf("Dear %s, enter a capital letter and a color: ", player.name);
//
        // scanf("%c %s%*c", &c, color);
        // letter = color_letter(c, color);
        // print_colored_letter(letter);
        int n, n_tiles, number;
        printf("Dear %s, enter how many tiles you want in a bag: ", player.name);
        scanf("%d%*c", &n);
        Bag *bag, *deck;
        bag  = createBagWithTiles(n);
        deck = createEmptyBag();
        Tile current;
        printf("You bag contains %d tiles.\n", bag->numberOfTiles);
        printf("You have in hand: \n");
        displayBag(deck);
        while (bag->numberOfTiles){
            printf("Enter how many tiles you want to take from the bag: ");
            scanf("%d%*c", &n_tiles);
            emptyBag(deck);
            deck = getDeckFromBag(bag, n_tiles);
            printf("You bag contains %d tiles.\n", bag->numberOfTiles);
            while(deck->numberOfTiles){
                printf("You have in hand: \n");
                displayBag(deck);
                printf("Choose tile to pick(start from zero)\n");
                scanf("%d%*c", &number);
                current = popFromBag(deck, number);
                printf("You picked: ");
                displayTile(&current);
            }
        }
        emptyBag(deck);
        emptyBag(bag);

        break;
    }
}

void qwirkle_pvp(Player player1, Player player2){

}

