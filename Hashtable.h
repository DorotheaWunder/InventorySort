#ifndef HASHTABLE_H
#define HASHTABLE_H

#define NAME_LENGTH 50
#define TABLE_SIZE 15

typedef struct Item
{
    char name[NAME_LENGTH];
    int value;
    int rarity;
    float weight;
} Item;

typedef struct Node
{
    Item item;
    struct Node* nextNode;
} Node;

typedef struct HashTable
{
    Node* buckets[TABLE_SIZE];
    Item* sortedItems[TABLE_SIZE * 5];
    int itemCount;
} HashTable;


unsigned int hash(const char* name);
void InitHashTable(HashTable* table);
void AddItem(HashTable* table, Item item);
void RemoveItem(HashTable* table, const char* name);
void DisplayTable(HashTable* table);

#endif //HASHTABLE_H
