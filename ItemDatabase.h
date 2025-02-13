#ifndef ITEMDATABASE_H
#define ITEMDATABASE_H

typedef struct Item
{
    char name[50];
    int value;
    int rarity;
    float weight;
} Item;

#define INVENTORY_SIZE 15
extern Item* inventory[];

Item* createItem(const char* name, int value, int rarity, float weight);
void InitializeDatabase();

#endif //ITEMDATABASE_H
