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
        player = scan_player();
        print_player(stdout, player);
        //qwirkle_computer(difficulty, player);
    } else{

    }
}

void qwirkle_computer(int difficulty, Player player){
    printf("%s\n", player.name);
    char color[20], c;
    colored_letter letter;
    while(1){
        int n, n_tiles, number, b_rows, b_cols, row, col;
        printf("Dear %s, enter how many tile sets you want in a bag: ", player.name);
        scanf("%d%*c", &n);
        printf("Dear %s, choose number of rows and columns: ", player.name);
        scanf("%d %d%*c", &b_rows, &b_cols);
        Board board = createEmptyBoard(b_rows, b_cols);
        Bag *bag, *deck;
        bag  = createBagWithTiles(n);
        deck = createEmptyBag();
        Tile current;
        displayBoard(board);
        printf("You bag contains %d tiles.\n", bag->numberOfTiles);
        printf("You have in hand: \n");
        displayBag(deck);
        while (bag->numberOfTiles){
            emptyBag(deck);
            deck = getDeckFromBag(bag, 6);
            printf("You bag contains %d tiles.\n", bag->numberOfTiles);
            while(deck->numberOfTiles){
                printf("You have in hand: \n");
                displayBag(deck);
                printf("Choose tile to pick(start from zero) and position on the board\n");
                scanf("%d %d %d%*c", &number, &row, &col);
                current = popFromBag(deck, number);
                while(!insertTileInBoard(&board, current, row, col)){
                    printf("Invalid place. Please, try again\n");
                    printf("Enter row and col:");
                    scanf("%d %d%*c", &row, &col);
                }
                displayBoard(board);
                if(bag->numberOfTiles!=0)addNewTileToBag(deck, popRandomTileFromBag(bag));
            }
        }
        emptyBag(deck);
        emptyBag(bag);

        break;
    }
}

void qwirkle_pvp(Player player1, Player player2){

}

