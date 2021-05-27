#include "Tiles.h"

Bag *createEmptyBag(){
    Bag *res = (Bag *)malloc(sizeof (Bag));

    res->firstTile = NULL;
    res->numberOfTiles = 0;

    return res;
}

linkedTile *createChainedTile(Tile tile, linkedTile *next){
    linkedTile *res;
    res = (linkedTile *)malloc(sizeof(linkedTile));
    res->tile = tile;
    res->next = next;
    return res;
}

void addNewTileToBag(Bag *bag, Tile tile){
    bag->numberOfTiles++;
    linkedTile *current;
    if(bag->firstTile){
        current = bag->firstTile;
        while(current){
            if(current->next)
                current = current->next;
            else
                break;
        }
        current->next = createChainedTile(tile, NULL);
    }
    else{
        bag->firstTile = createChainedTile(tile, NULL);
    }
}

Bag *createBagWithTiles(int n){
    assert(n > 0);
    Bag *res;
    res = createEmptyBag();
    for(int i = 0; i < n; i ++){
        addNewTileToBag(res, createTile('A', "red"));
        addNewTileToBag(res, createTile('B', "red"));
        addNewTileToBag(res, createTile('C', "red"));
        addNewTileToBag(res, createTile('D', "red"));
        addNewTileToBag(res, createTile('A', "green"));
        addNewTileToBag(res, createTile('B', "green"));
        addNewTileToBag(res, createTile('C', "green"));
        addNewTileToBag(res, createTile('D', "green"));
        addNewTileToBag(res, createTile('A', "blue"));
        addNewTileToBag(res, createTile('B', "blue"));
        addNewTileToBag(res, createTile('C', "blue"));
        addNewTileToBag(res, createTile('D', "blue"));
        addNewTileToBag(res, createTile('A', "yellow"));
        addNewTileToBag(res, createTile('B', "yellow"));
        addNewTileToBag(res, createTile('C', "yellow"));
        addNewTileToBag(res, createTile('D', "yellow"));
    }
    return res;
}

void emptyBag(Bag *bag){
    linkedTile *curr, *prev;
    curr = bag->firstTile;
    while(curr){
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    free(curr);
    free(bag);
}

void removeTile(Bag *bag, int n){
    assert(n < bag->numberOfTiles);
    assert(bag->firstTile);
    linkedTile *curr, *prev;
    if(n == 0){
        curr = bag->firstTile;
        bag->firstTile = curr->next;
        free(curr);
    }
    else {
        curr = bag->firstTile;
        for(int i = 0; i < n; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr);
    }
}



Tile popFromBag(Bag *bag, int n){
    assert(n < bag->numberOfTiles);
    linkedTile *curr;
    Tile res;
    curr = bag->firstTile;
    int i;
    for(i = 0; i < n;i++){
        curr = curr->next;
    }
    res = curr->tile;
    removeTile(bag, i);
    bag->numberOfTiles--;
    return res;
}

Tile popRandomTileFromBag(Bag *bag){
    int n;
    n = RANDOM() % bag->numberOfTiles;
    return popFromBag(bag, n);
}
Bag *getDeckFromBag(Bag *bag, int n){
    if(n > bag->numberOfTiles) n = bag->numberOfTiles;
    assert(n >= 0);
    Bag *res;
    res = createEmptyBag();
    for(int i = 0; i < n; i++){
        addNewTileToBag(res, popRandomTileFromBag(bag));
    }
    return res;
}

void displayBag(Bag *bag){
    linkedTile *curr;
    curr = bag->firstTile;
    if(curr){
        while (curr){
            print_colored_letter(curr->tile);
            printf(" ");
            curr = curr->next;
        }
        puts("");
    }
    else{
        puts("Your deck is empty.");
    }
}

