#include <string.h>
#include <stdio.h>
#include "raylib.h"
#include "algorithm.h"
#include "hashtable.h"


//------------------------------------------------- generalized comparisons
int CompareByName(Item* a, Item* b)
{
    return strcmp(a->name, b->name);
}

int CompareByAcquisition(Item* a, Item* b)
{
    return a->acquisitionOrder - b->acquisitionOrder;
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

void SortInventory(HashTable* table, Category category)
{
    table->itemCount = 0;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* currentNode = table->buckets[i];
        while (currentNode) {
            table->sortedItems[table->itemCount++] = &currentNode->item;
            currentNode = currentNode->nextNode;
        }
    }

    int (*compare)(Item*, Item*);
    switch (category) {
    case NAME: compare = CompareByName; break;
    case ACQUISITION: compare = CompareByAcquisition; break;
    case VALUE: compare = CompareByValue; break;
    case RARITY: compare = CompareByRarity; break;
    case WEIGHT: compare = CompareByWeight; break;
    default: return;
    }

    QuickSortAlgorithm(table->sortedItems, 0, table->itemCount - 1, compare);

    printf("MENU HAS BEEN SORTED!\n");
}
