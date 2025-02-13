#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "itemdatabase.h"
#include "ui.h"

typedef enum Category
{
    NAME,
    VALUE,
    RARITY,
    WEIGHT

    //--- last aquired?
} Category;


int CompareByName(Item* a, Item* b);
int CompareByValue(Item* a, Item* b);
int CompareByRarity(Item* a, Item* b);
int CompareByWeight(Item* a, Item* b);

void SwapPosition(Item** a, Item** b);

void BubbleSortAlgorithm(Item** inventory, int size, int (*compare)(Item*, Item*));

void SortInventory(Item** inventory, int size, Category category);

#endif //ALGORITHM_H
