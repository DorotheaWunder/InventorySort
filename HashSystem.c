#include "hashsystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int hash(const char* name)
{
    unsigned int hashValue = 0;
    while (*name)
    {
        hashValue = (hashValue << 5) + *name++;
    }
    return hashValue;
}

void InsertItem(HashTable* table, Item* newItem)
{
    unsigned int index = hash(newItem->name) % TABLE_SIZE;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = newItem;
    newNode->previous = NULL;
    newNode->next = table->hashTable[index];

    if (table->hashTable[index] != NULL)
    {
        table->hashTable[index]->previous = newNode;
    }

    table->hashTable[index] = newNode;
}

void RemoveItem(HashTable* table, const char* name)
{
    unsigned int index = hash(name) % TABLE_SIZE;

    Node* currentNode = table->hashTable[index];

    while (currentNode != NULL)
    {
        if (strcmp(currentNode->item->name, name) == 0)
        {
            if (currentNode->previous != NULL)
            {
                currentNode->previous->next = currentNode->next;
            }
            else
            {
                table->hashTable[index] = currentNode->next;
            }

            if (currentNode->next != NULL)
            {
                currentNode->next->previous = currentNode->previous;
            }

            free(currentNode->item);
            free(currentNode);

            return;
        }
        currentNode = currentNode->next;
    }
}