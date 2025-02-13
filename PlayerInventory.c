#include <stdlib.h>
#include <string.h>

#include "itemdatabase.h"
#include "hashsystem.h"
#include "playerinventory.h"


void InitializeInventory(Inventory* inventory)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        inventory->hashTable.hashTable[i] = NULL;
    }
}

void AddToInventory(Inventory* inventory, Item* newItem)
{
    InsertItem(&inventory->hashTable, newItem);
}

void RemoveFromInventory(Inventory* inventory, const char* name)
{
    RemoveItem(&inventory->hashTable, name);
}