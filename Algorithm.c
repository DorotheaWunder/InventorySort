﻿#include "raylib.h"
#include "algorithm.h"
#include "itemdatabase.h"
#include "ui.h"
#include <string.h>

//------------------------------------------------- generalized comparisons
int CompareByName(Item* a, Item* b)
{
    return strcmp(a->name, b->name);
}

int CompareByValue(Item* a, Item* b)
{
    return b->value - a->value;
}

int CompareByRarity(Item* a, Item* b)
{
    return b->rarity - a->rarity;
}

int CompareByWeight(Item* a, Item* b)
{
    return b->weight - a->weight;
}

//------------------------------------------------- Helper functions
void SwapPosition(Item** a, Item** b)
{
    Item* temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(Item** inventory, int low, int high, int (*compare)(Item*, Item*))
{
    Item* pivot = inventory[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (compare(inventory[j], pivot) < 0)
        {
            i++;
            SwapPosition(&inventory[i], &inventory[j]);
        }
    }

    SwapPosition(&inventory[i + 1], &inventory[high]);
    return i + 1;
}

//------------------------------------------------- generalized algorithms
void BubbleSortAlgorithm(Item** inventory, int size, int (*compare)(Item*, Item*))
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (compare(inventory[j], inventory[j + 1]) > 0)
            {
                SwapPosition(&inventory[j], &inventory[j+1]);
            }
        }
    }
}

void QuickSortAlgorithm(Item** inventory, int low, int high, int (*compare)(Item*, Item*))
{
    if (low < high)
    {
        int pivotIndex = Partition(inventory, low, high, compare);

        QuickSortAlgorithm(inventory, low, pivotIndex - 1, compare);
        QuickSortAlgorithm(inventory, pivotIndex + 1, high, compare);
    }
}


//------------------------------------------------- inventory sorting

void SortInventory(Item** inventory, int size, Category category)
{
    int (*compare)(Item*, Item*);

    switch (category)
    {
    case NAME:
        compare = CompareByName;
        break;
    case VALUE:
        compare = CompareByValue;
        break;
    case RARITY:
        compare = CompareByRarity;
        break;
    case WEIGHT:
        compare = CompareByWeight;
        break;
    default:
    }


    //BubbleSortAlgorithm(inventory, size, compare);
    QuickSortAlgorithm(inventory, 0, size - 1, compare);
}