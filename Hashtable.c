#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"

unsigned int hash(const char* name)
{
    unsigned int hashValue= 0;

   while (*name)
   {
       hashValue = (hashValue * 31) + *name;
       name++;
   }
    return hashValue % TABLE_SIZE;
}

void InitHashTable(HashTable* table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table->buckets[i] = NULL;
    }
    table->itemCount = 0;
}

void AddItem(HashTable* table, Item item)
{
    unsigned int index = hash(item.name);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->item = item;
    newNode->nextNode = table->buckets[index];

    table->buckets[index] = newNode;
}

Item* FindItem(HashTable* table, const char* name)
{
    unsigned int index = hash(name);
    Node* currentNode = table->buckets[index];

    while (currentNode)
    {
        if (strcmp(currentNode->item.name, name) == 0)
        {
            return &currentNode->item;
        }
        currentNode = currentNode->nextNode;
    }
    printf("Item not found\n");
    return NULL;
}

void RemoveItem(HashTable* table, const char* name)
{
    unsigned int index = hash(name);
    Node* currentNode = table->buckets[index];
    Node* previousNode = NULL;

    while (currentNode)
    {
        if (strcmp(currentNode->item.name, name) == 0)
        {
            if (previousNode)
            {
                previousNode->nextNode = currentNode->nextNode;
            }
            else
            {
                table->buckets[index] = currentNode->nextNode;
            }
            free(currentNode);
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }
}

void DisplayTable(HashTable* table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Inventory Slot %d: ", i);

        Node* currentNode = table->buckets[i];
        while (currentNode)
        {
            printf("[%s, %d gold, Rarity %d, %.2f kg] -> ",
            currentNode->item.name, currentNode->item.value,
               currentNode->item.rarity, currentNode->item.weight);
            currentNode = currentNode->nextNode;
        }
        printf("NULL\n");
    }
}

void ClearTable(HashTable* table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* currentNode = table->buckets[i];

        while (currentNode)
        {
            Node* temp = currentNode;
            currentNode = currentNode->nextNode;
            free(temp);
        }
        table->buckets[i] = NULL;
    }
}