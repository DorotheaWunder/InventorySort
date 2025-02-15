// #include <stdio.h>
// #include <stdlib.h>
// #include "raylib.h"
// #include "ui.h"
// #include "itemdatabase.h"
// #include "algorithm.h"
// #include "playerinventory.h"
// #include "menu.h"
//
// Algorithm selectedAlgorithm = BUBBLE;
//
// Panel inventoryPanel;
// Panel categoryPanel;
// Panel algorithmPanel;
//
// void InitializePanels()
// {
//     InitPanelElement(&inventoryPanel,
//         (Rectangle){ 20, 20, 1300, 740 },
//         (Color){ 80, 80, 80, 255 },
//         "--- Inventory -------------------------------------------");
//
//     InitPanelElement(&categoryPanel,
//         (Rectangle){ 1340, 20, 220, 360 },
//         (Color){ 130, 130, 130, 255 },
//         "Sort by:");
//
//     InitPanelElement(&algorithmPanel,
//         (Rectangle){ 1340, 400, 220, 480 },
//         (Color){ 130, 130, 130, 255 },
//         "Using:");
// }
//
// void DrawAllPanels()
// {
//     DrawPanelElement(inventoryPanel);
//     DrawPanelElement(categoryPanel);
//     DrawPanelElement(algorithmPanel);
// }
//
// TableHeader tableHeader;
// TableContent tableContent;
//
// void InitializeTable(HashTable** playerInventory, int inventorySize)
// {
//     const char* headers[4] = { "Name", "Value", "Rarity", "Weight" };
//
//     InitHeaderElement(&tableHeader,
//         (Rectangle){ 30, 100, 1280, 50 },
//         GRAY,
//         headers,
//         30);
//
//     InitContentElement(&tableContent,
//         (Rectangle){ 30, 150, 600, 10 },
//         LIGHTGRAY,
//         playerInventory,
//         inventorySize,
//         25);
//
//     // InitContentElement(&tableContent,
//     // (Rectangle){ 30, 150, 600, 10 },
//     // LIGHTGRAY,
//     // playerInventory,
//     // inventorySize,
//     // 25);
// }
//
// Button byName;
// Button byValue;
// Button byRarity;
// Button byWeight;
//
// Button bubbleSort;
// Button quickSort;
//
// Button gainItem;
// Button getAll;
// Button loseItem;
//
// void InitnializeButtons()
// {
//     //----------------------------------------------------------- sorting category
//     InitButtonElement(&byName,
//         (Rectangle){ 1350, 100, 200, 40 },
//         DARKGRAY, LIGHTGRAY,
//         "NAME");
//
//     InitButtonElement(&byValue,
//         (Rectangle){ 1350, 160, 200, 40 },
//         DARKGRAY, LIGHTGRAY,
//         "VALUE");
//
//     InitButtonElement(&byRarity,
//         (Rectangle){ 1350, 230, 200, 40},
//         DARKGRAY, LIGHTGRAY,
//         "RARITY");
//
//     InitButtonElement(&byWeight,
//         (Rectangle){ 1350, 300, 200, 40 },
//         DARKGRAY, LIGHTGRAY,
//         "WEIGHT");
//
//
//     //----------------------------------------------------------- select Algorithm
//     InitButtonElement(&bubbleSort,
//     (Rectangle){ 1350, 470, 200, 40 },
//     (selectedAlgorithm == BUBBLE) ? WHITE : DARKGRAY,
//     LIGHTGRAY,
//     " Bubble Sort");
//
//     InitButtonElement(&quickSort,
//     (Rectangle){ 1350, 530, 200, 40 },
//     (selectedAlgorithm == QUICK) ? WHITE : DARKGRAY,
//     LIGHTGRAY,
//     " Quick Sort");
//
//     //----------------------------------------------------------- adding/removing items
//     InitButtonElement(&gainItem,
//     (Rectangle){ 20, 760, 150, 40 },
//     DARKGREEN, GREEN,
//     "  Gain Item");
//
//     InitButtonElement(&getAll,
//     (Rectangle){ 20, 800, 150, 40 },
//     GOLD, BEIGE,
//     "GIVE ME ALL!");
//
//     InitButtonElement(&loseItem,
//     (Rectangle){ 20, 840, 150, 40 },
//     MAROON, RED,
//     "  Lose Item");
// }
//
// bool IsHovering(Button button)
// {
//     Vector2 mousePosition = GetMousePosition();
//     return CheckCollisionPointRec(mousePosition, button.rectangle);
// }
//
// void DrawButtonElement(Button button)
// {
//     Color buttonColor = IsHovering(button) ? button.hoverColor : button.defaultColor;
//     DrawRectangleRec(button.rectangle, buttonColor);
//     DrawText(button.text, button.rectangle.x + 10, button.rectangle.y + 10, 20, BLACK);
// }
//
// void DrawAllButtons()
// {
//     DrawButtonElement(byName);
//     DrawButtonElement(byValue);
//     DrawButtonElement(byRarity);
//     DrawButtonElement(byWeight);
//
//     DrawButtonElement(bubbleSort);
//     DrawButtonElement(quickSort);
//
//     // DrawButtonElement(gainItem);
//     // DrawButtonElement(getAll);
//     // DrawButtonElement(loseItem);
// }
//
// Category SelectCategory()
// {
//     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//     {
//         if (IsHovering(byName)) return NAME;
//         if (IsHovering(byValue)) return VALUE;
//         if (IsHovering(byRarity)) return RARITY;
//         if (IsHovering(byWeight)) return WEIGHT;
//     }
//     return -1;
// }
//
// Algorithm SelectAlgorithm()
// {
//     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//     {
//         if (IsHovering(bubbleSort)) return BUBBLE;
//         if (IsHovering(quickSort)) return QUICK;
//     }
//     return -1;
// }
//
//
//
//
// void AddItem(Inventory* inventory, Item** database, int databaseSize)
// {
//     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//     {
//         if (databaseSize <= 0) return;
//
//         int randomIndex = GetRandomValue(0, databaseSize - 1);
//         Item* randomItem = database[randomIndex];
//
//         if (randomItem != NULL)
//         {
//             AddToInventory(inventory, randomItem);
//         }
//     }
// }
//
// void GetAll(Inventory* inventory, Item** database, int databaseSize)
// {
//     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//     {
//         for (int i = 0; i < databaseSize; i++)
//         {
//             if (database[i] != NULL)
//             {
//                 AddToInventory(inventory, database[i]);
//             }
//         }
//     }
// }
//
// void LoseItem(Inventory* inventory)
// {
//     Item* itemList[TABLE_SIZE];
//     int itemCount = 0;
//
//     for (int i = 0; i < TABLE_SIZE; i++)
//     {
//         Node* currentNode = inventory->hashTable.hashTable[i];
//
//         while (currentNode != NULL)
//         {
//             itemList[itemCount++] = currentNode->item;
//             currentNode = currentNode->next;
//         }
//     }
//
//     if (itemCount > 0)
//     {
//         int randomIndex = GetRandomValue(0, itemCount - 1);
//         RemoveFromInventory(inventory, itemList[randomIndex]->name);
//     }
// }
//
// void InitializeMenu(Item** playerInventory, int inventorySize)
// {
//     InitializePanels();
//     InitializeTable(playerInventory, inventorySize);
//     InitnializeButtons();
// }
//
// void DrawMenu()
// {
//     DrawAllPanels();
//     DrawTable(tableHeader, tableContent);
//     DrawAllButtons();
// }
//
// void UpdateMenu(Item** inventory, int size)
// {
//     Category selectedCategory = SelectCategory();
//
//     if (selectedCategory != -1) {
//         SortInventory(inventory, size, selectedCategory);
//     }
//
//     Algorithm selectedAlgorithm = SelectAlgorithm();
//     if (selectedAlgorithm != -1) {
//         selectedAlgorithm = selectedAlgorithm;
//     }
//
//     tableContent.items = inventory;
//     tableContent.numRows = size;
// }