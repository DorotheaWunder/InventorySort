#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"


HashTable inventory;
InventorySystem inventorySystem;
int nextAcquisitionNumber = 1;

void CreateItemlist()
{
    InitHashTable(&inventorySystem.itemList);

    AddItem(&inventorySystem.itemList, (Item){"Rusty Sword", 0,50, 1, 3.5f});
    AddItem(&inventorySystem.itemList, (Item){"Sword", 0,100, 2, 4.5f});
    AddItem(&inventorySystem.itemList, (Item){"Diamond Sword", 0,500, 4, 5.0f});
    AddItem(&inventorySystem.itemList, (Item){"Excalibur", 0,10000, 5, 5.5f});

    AddItem(&inventorySystem.itemList, (Item){"Rusty Shield", 0,50, 1, 3.0f});
    AddItem(&inventorySystem.itemList, (Item){"Shield", 0,100, 2, 5.5f});
    AddItem(&inventorySystem.itemList, (Item){"Diamond Shield", 0,550, 4, 6.5f});
    AddItem(&inventorySystem.itemList, (Item){"Legendary Shield", 0,5000, 5, 10.5f});

    AddItem(&inventorySystem.itemList, (Item){"Leather Jerkin", 0,150, 1, 5.0f});
    AddItem(&inventorySystem.itemList, (Item){"Iron Breastplate", 0,500, 2, 15.5f});
    AddItem(&inventorySystem.itemList, (Item){"Steel Armor", 0,1500, 3, 25.0f});
    AddItem(&inventorySystem.itemList, (Item){"Enchanted Armor", 0,5000, 4, 25.0f});

    AddItem(&inventorySystem.itemList, (Item){"Lesser Healing Potion", 10, 1, 0.5f});
    AddItem(&inventorySystem.itemList, (Item){"Healing Potion", 0,25, 1, 1.0f});
    AddItem(&inventorySystem.itemList, (Item){"Greater Healing Potion", 0,50, 2, 1.5f});
    AddItem(&inventorySystem.itemList, (Item){"Elixir", 0,250, 3, 1.5f});
}

void CreateInventory()
{
    InitHashTable(&inventorySystem.playerInventory);

    AddItem(&inventorySystem.playerInventory, (Item){"Rusty Sword", nextAcquisitionNumber++, 50, 1, 3.5f});

    AddItem(&inventorySystem.playerInventory, (Item){"Rusty Shield", nextAcquisitionNumber++, 50, 1, 3.0f});

    AddItem(&inventorySystem.playerInventory, (Item){"Leather Jerkin", nextAcquisitionNumber++, 150, 1, 5.0f});

    AddItem(&inventorySystem.playerInventory, (Item){"Lesser Healing Potion", nextAcquisitionNumber++, 10, 1, 0.5f});
}

void InitializeItems()
{
    CreateItemlist();
    CreateInventory();
}

void GainItem()
{
    int totalItems = 0;
    Item* items[TABLE_SIZE * 5];

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* currentNode = inventorySystem.itemList.buckets[i];

        while (currentNode)
        {
            items[totalItems++] = &currentNode->item;
            currentNode = currentNode->nextNode;
        }
    }

    if (totalItems > 0)
    {
        int randomIndex = rand() % totalItems;
        Item newItem = *items[randomIndex];
        newItem.acquisitionOrder = nextAcquisitionNumber++;
        AddItem(&inventorySystem.playerInventory, newItem);
    }
}

void LoseItem()
{
    int totalItems = 0;
    Item* items[TABLE_SIZE * 5];

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* currentNode = inventorySystem.playerInventory.buckets[i];
        while (currentNode)
        {
            items[totalItems++] = &currentNode->item;
            currentNode = currentNode->nextNode;
        }
    }

    if (totalItems > 0)
    {
        int randomIndex = rand() % totalItems;
        RemoveItem(&inventorySystem.playerInventory, items[randomIndex]->name);
    }
}

void GainAll()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* currentNode = inventorySystem.itemList.buckets[i];
        while (currentNode)
        {
            Item newItem = currentNode->item;
            newItem.acquisitionOrder = nextAcquisitionNumber++;
            AddItem(&inventorySystem.playerInventory, newItem);
            currentNode = currentNode->nextNode;
        }
    }
}

void LoseAll()
{
    //ClearTable(&inventorySystem.playerInventory);
}
