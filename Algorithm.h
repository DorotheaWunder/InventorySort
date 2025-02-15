#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "hashtable.h"
#include "ui.h"

typedef enum Category
{
    NAME,
    VALUE,
    RARITY,
    WEIGHT

    //--- last aquired?
} Category;

typedef enum Algorithm
{
    BUBBLE,
    QUICK
} Algorithm;


int CompareByName(Item* a, Item* b);
int CompareByValue(Item* a, Item* b);
int CompareByRarity(Item* a, Item* b);
int CompareByWeight(Item* a, Item* b);

void SwapPosition(Item** a, Item** b);
int Partition(Item** inventory, int low, int high, int (*compare)(Item*, Item*));

void BubbleSortAlgorithm(Item** inventory, int size, int (*compare)(Item*, Item*));
void QuickSortAlgorithm(Item** inventory, int low, int high, int (*compare)(Item*, Item*));

void SortInventory(HashTable* table, Category category);

#endif //ALGORITHM_H
