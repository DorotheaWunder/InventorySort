#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"


HashTable inventory;

void CreateInventory()
{
    InitHashTable(&inventory);

    AddItem(&inventory, (Item){"Rusty Sword", 50, 1, 3.5f});
    AddItem(&inventory, (Item){"Sword", 100, 2, 4.5f});
    AddItem(&inventory, (Item){"Diamond Sword", 500, 4, 5.0f});
    AddItem(&inventory, (Item){"Excalibur", 10000, 5, 5.5f});

    AddItem(&inventory, (Item){"Rusty Shield", 50, 1, 3.0f});
    AddItem(&inventory, (Item){"Shield", 100, 2, 5.5f});
    AddItem(&inventory, (Item){"Diamond Shield", 550, 4, 6.5f});
    AddItem(&inventory, (Item){"Legendary Shield", 5000, 5, 10.5f});

    AddItem(&inventory, (Item){"Leather Jerkin", 150, 1, 5.0f});
    AddItem(&inventory, (Item){"Iron Breastplate", 500, 2, 15.5f});
    AddItem(&inventory, (Item){"Steel Armor", 1500, 3, 25.0f});
    AddItem(&inventory, (Item){"Enchanted Armor", 5000, 4, 25.0f});

    AddItem(&inventory, (Item){"Lesser Healing Potion", 10, 1, 0.5f});
    AddItem(&inventory, (Item){"Healing Potion", 25, 1, 1.0f});
    AddItem(&inventory, (Item){"Greater Healing Potion", 50, 2, 1.5f});
    AddItem(&inventory, (Item){"Elixir", 250, 3, 1.5f});
}

