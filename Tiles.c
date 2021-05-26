#include "Tiles.h"

Bag *createBagOfTiles(int n){
    assert(n>0);
    Bag *res = (Bag *)malloc(sizeof (Bag));
    res->numberOfTiles = n*16;
    linkedTile *current = (linkedTile*) malloc(sizeof(linkedTile));
    res->firstTile = current;
    for(int i = 0; i < n; i++) {
        current->tile = createTile('A', "red");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('B', "red");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('C', "red");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('D', "red");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('A', "green");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('B', "green");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('C', "green");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('D', "green");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('A', "blue");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('B', "blue");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('C', "blue");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('D', "blue");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('A', "yellow");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('B', "yellow");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('C', "yellow");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
        current->tile = createTile('D', "yellow");
        current->next = (linkedTile *) malloc(sizeof(linkedTile));
        current = current->next;
    }
    return res;
}