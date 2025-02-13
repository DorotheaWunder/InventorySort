#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include "itemdatabase.h"
#include "hashsystem.h"

typedef struct Inventory
{
    HashTable hashTable;
} Inventory;




void InitializeInventory(Inventory* inventory);
void AddToInventory(Inventory* inventory, Item* newItem);
void RemoveFromInventory(Inventory* inventory, const char* name);

#endif //PLAYERINVENTORY_H
