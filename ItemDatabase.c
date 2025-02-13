#include <stdlib.h>
#include <string.h>

#include "itemdatabase.h"

Item* inventory[INVENTORY_SIZE] = { NULL };

Item* createItem(const char* name, int value, int rarity, float weight)
{
    Item* newItem = (Item*)malloc(sizeof(Item));

    if (newItem != NULL)
    {
        strcpy(newItem->name, name);
        newItem->value = value;
        newItem->rarity = rarity;
        newItem->weight = weight;
    }
    return newItem;
}

void InitializeInventory()
{
    inventory[0] = createItem("Rusty Sword", 50, 1, 3.5f);
    inventory[1] = createItem("Sword", 100, 2, 4.5f);
    inventory[2] = createItem("Diamond Sword", 500, 4, 5.0f);
    inventory[3] = createItem("Excalibur", 10000, 5, 5.5f);

    inventory[4] = createItem("Rusty Shield", 50, 1, 3.0f);
    inventory[5] = createItem("Shield", 100, 2, 5.5f);
    inventory[6] = createItem("Diamond Shield", 550, 4, 6.5f);
    inventory[7] = createItem("Legendary Shield", 5000, 5, 10.5f);

    inventory[8] = createItem("Leather Jerkin", 150, 1, 5.0f);
    inventory[9] = createItem("Iron Breastplate", 500, 2, 15.5f);
    inventory[10] = createItem("Steel Armor", 1500, 3, 25.0f);
    inventory[11] = createItem("Enchanted Armor", 5000, 4, 25.0f);

    inventory[12] = createItem("Lesser Healing Potion", 10, 1, 0.5f);
    inventory[13] = createItem("Healing Potion", 25, 1, 1.0f);
    inventory[14] = createItem("Greater Healing Potion", 50, 2, 1.5f);
    inventory[15] = createItem("Elixir", 250, 3, 1.5f);
}