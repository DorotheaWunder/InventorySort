#ifndef HASHSYSTEM_H
#define HASHSYSTEM_H

#include "itemdatabase.h"

typedef struct Node
{
    Item* item;
    struct Node* previous;
    struct Node* next;
} Node;

#define TABLE_SIZE 20

typedef struct HashTable
{
    Node* hashTable[TABLE_SIZE];
} HashTable;


unsigned int hash(const char* name);
void InsertItem(HashTable* table, Item* newItem);
void RemoveItem(HashTable* table, const char* name);


#endif //HASHSYSTEM_H
