#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include "raylib.h"
#include "ui.h"
#include "hashtable.h"
#include "algorithm.h"

#define SCREEN_WIDTH 1580
#define SCREEN_HEIGHT 900


void InitializeMenuPanels();
void DrawAllPanels();
void DrawMenuTable(Table table, HashTable* inventory);

void InitnializeButtons();
bool IsHovering(Button button);
void DrawButtonElement(Button button);
void DrawAllButtons();
Category SelectCategory();



void DrawMenu();
void UpdateMenu(HashTable* inventory);

#endif //MENU_H
