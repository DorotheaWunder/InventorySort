#ifndef INVENTORY_H
#define INVENTORY_H

#include "hashtable.h"

extern HashTable inventory;
extern InventorySystem inventorySystem;

void CreateItemlist();
void CreateInventory();
void InitializeItems();

void GainItem();
void LoseItem();
void GainAll();
void LoseAll();


#endif //INVENTORY_H
