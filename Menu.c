#include <stdio.h>
#include "raylib.h"
#include "ui.h"
#include "hashtable.h"
#include "inventory.h"
#include "algorithm.h"

extern HashTable inventory;

Panel inventoryPanel;
Panel categoryPanel;
Panel algorithmPanel;

void InitializeMenuPanels()
{
    InitPanelElement(&inventoryPanel,
        (Rectangle){ 20, 20, 1300, 740 },
        (Color){ 80, 80, 80, 255 },
        "--- Inventory -------------------------------------------");

    InitPanelElement(&categoryPanel,
        (Rectangle){ 1340, 20, 220, 360 },
        (Color){ 130, 130, 130, 255 },
        "Sort by:");

    InitPanelElement(&algorithmPanel,
        (Rectangle){ 1340, 400, 220, 480 },
        (Color){ 130, 130, 130, 255 },
        "Using:");
}

void DrawAllPanels()
{
    DrawPanelElement(inventoryPanel);
    DrawPanelElement(categoryPanel);
    DrawPanelElement(algorithmPanel);
}

void DrawMenuTable(Table table, HashTable* inventory)
{
    float colWidth = table.rectangle.width / table.columns;
    float rowHeight = 40;

    DrawRectangleRec(table.rectangle, (Color){60, 60, 60, 255});

    for (int i = 0; i < table.columns; i++)
    {
        float xPos = table.rectangle.x + i * colWidth;
        DrawText(table.columnHeaders[i], xPos + 10, table.rectangle.y + 10, 20, WHITE);
    }

    int rowIndex = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* currentNode = inventory->buckets[i];
        while (currentNode)
        {
            float yPos = table.rectangle.y + (rowIndex + 1) * rowHeight;

            DrawText(currentNode->item.name, table.rectangle.x + 10, yPos + 10, 20, WHITE);

            char valueText[10];
            sprintf(valueText, "%d", currentNode->item.value);
            DrawText(valueText, table.rectangle.x + colWidth + 10, yPos + 10, 20, WHITE);

            char rarityText[10];
            sprintf(rarityText, "%d", currentNode->item.rarity);
            DrawText(rarityText, table.rectangle.x + 2 * colWidth + 10, yPos + 10, 20, WHITE);

            char weightText[10];
            sprintf(weightText, "%.2f", currentNode->item.weight);
            DrawText(weightText, table.rectangle.x + 3 * colWidth + 10, yPos + 10, 20, WHITE);

            rowIndex++;
            currentNode = currentNode->nextNode;
        }
    }
}

Button byName;
Button byValue;
Button byRarity;
Button byWeight;

void InitnializeButtons()
{
    //----------------------------------------------------------- sorting category
    InitButtonElement(&byName,
        (Rectangle){ 1350, 100, 200, 40 },
        DARKGRAY, LIGHTGRAY,
        "NAME");

    InitButtonElement(&byValue,
        (Rectangle){ 1350, 160, 200, 40 },
        DARKGRAY, LIGHTGRAY,
        "VALUE");

    InitButtonElement(&byRarity,
        (Rectangle){ 1350, 230, 200, 40},
        DARKGRAY, LIGHTGRAY,
        "RARITY");

    InitButtonElement(&byWeight,
        (Rectangle){ 1350, 300, 200, 40 },
        DARKGRAY, LIGHTGRAY,
        "WEIGHT");
}

bool IsHovering(Button button)
{
    Vector2 mousePosition = GetMousePosition();
    return CheckCollisionPointRec(mousePosition, button.rectangle);
}

void DrawButtonElement(Button button)
{
    Color buttonColor = IsHovering(button) ? button.hoverColor : button.defaultColor;
    DrawRectangleRec(button.rectangle, buttonColor);
    DrawText(button.text, button.rectangle.x + 10, button.rectangle.y + 10, 20, BLACK);
}

void DrawAllButtons()
{
    InitnializeButtons();

    DrawButtonElement(byName);
    DrawButtonElement(byValue);
    DrawButtonElement(byRarity);
    DrawButtonElement(byWeight);
}

Category SelectCategory()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        if (IsHovering(byName)) return NAME;
        if (IsHovering(byValue)) return VALUE;
        if (IsHovering(byRarity)) return RARITY;
        if (IsHovering(byWeight)) return WEIGHT;
    }
    return -1;
}

void DrawMenu()
{
    DrawAllPanels();
    DrawAllButtons();

    Table inventoryTable =
        {
        (Rectangle){ 20, 100, 1300, 780 },
        4,
        TABLE_SIZE,
        (const char*[]){"NAME", "VALUE", "RARITY", "WEIGHT"}
        };

    DrawMenuTable(inventoryTable, &inventory);
}

void UpdateMenu(HashTable* inventory)
{
    Category selectedCategory = SelectCategory();

    if (selectedCategory != -1)
    {
        SortInventory(inventory, selectedCategory);
    }

    DrawMenu();
}