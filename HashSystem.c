#include "hashsystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int hash(const char* name)
{
    unsigned int hashValue = 0;

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
        table->hashTable[i] = NULL;
    }
}

void InsertItem(HashTable* table, Item* newItem)
{
    if (newItem == NULL) return;
    unsigned int index = hash(newItem->name) % TABLE_SIZE;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;

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
        if (currentNode->item != NULL && strcmp(currentNode->item->name, name) == 0)
        {
            if (currentNode->previous)
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

Item* FindItem(HashTable* table, const char* name)
{
    unsigned int index = hash(name) % TABLE_SIZE;
    Node* current = table->hashTable[index];

    while (current != NULL)
    {
        if (current->item != NULL && strcmp(current->item->name, name) == 0)
        {
            return current->item;
        }
        current = current->next;
    }

    return NULL;
}