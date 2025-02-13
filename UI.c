#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "ui.h"
#include "itemdatabase.h"
#include "algorithm.h"
#include "playerinventory.h"

//---------------------------------------------------------------------------------- Panels
Panel inventoryPanel;
Panel categoryPanel;
Panel algorithmPanel;

void InitPanelElement(Panel* panel, Rectangle rectangle, Color color, const char* header)
{
    panel->rectangle = rectangle;
    panel->color = color;
    panel->header = header;
}

void InitializePanels()
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

void DrawPanelElement(Panel panel)
{
    DrawRectangleRec(panel.rectangle, panel.color);
    DrawText(panel.header, panel.rectangle.x + 10, panel.rectangle.y + 10, 45, WHITE);
}

void DrawAllPanels()
{
    DrawPanelElement(inventoryPanel);
    DrawPanelElement(categoryPanel);
    DrawPanelElement(algorithmPanel);
}

//---------------------------------------------------------------------------------- Table
TableHeader tableHeader;
TableContent tableContent;

void InitHeaderElement(TableHeader* header, Rectangle rectangle, Color color, const char* headers[4], int fontSize)
{
    header->rectangle = rectangle;
    header->color = color;

    for (int i = 0; i < 4; i++)
    {
        header->headers[i] = headers[i];
    }
    header->fontSize = fontSize;
}

void InitContentElement(TableContent* content, Rectangle rectangle, Color color, Item** items, int numRows, int fontSize)
{
    content->rectangle = rectangle;
    content-> color = color;
    content->items = items;
    content->numRows = numRows;
    content->fontSize = fontSize;
}

void InitializeTable()
{
    const char* headers[4] = { "Name", "Value", "Rarity", "Weight" };
    InitializeDatabase(inventory);
    //would this be where I hash?

    InitHeaderElement(&tableHeader,
        (Rectangle){ 30, 100, 1280, 50 },
        GRAY,
        headers,
        30);

    InitContentElement(&tableContent,
        (Rectangle){ 30, 150, 600, 10 },
        LIGHTGRAY,
        inventory,
        INVENTORY_SIZE,
        25);
}

void PositionTextInCol(const char* text, float x, float y, float fontSize, Color color, float padding)
{
    DrawText(text, x + padding, y, fontSize, color);
}

//------------ change to percentage instead of pixel, also padding
void DrawTableHeader(TableHeader header)
{
    DrawRectangleRec(header.rectangle, header.color);

    float xPos = header.rectangle.x;
    float yPos = header.rectangle.y + 10;

    for (int i = 0; i < 4; i++)
    {
        PositionTextInCol(header.headers[i], xPos + i * 300, yPos, header.fontSize, WHITE, 10);
    }
}

void DrawTableContent(TableContent content)
{
    for (int i = 0; i < content.numRows; i++) {
        Item* item = content.items[i];
        float yPos = content.rectangle.y + 30 + i * 30;


        PositionTextInCol(item->name, content.rectangle.x, yPos, content.fontSize, WHITE, 10);
        PositionTextInCol(TextFormat("%d", item->value), content.rectangle.x + 400, yPos, content.fontSize, WHITE, 10);
        PositionTextInCol(TextFormat("%d", item->rarity), content.rectangle.x + 800, yPos, content.fontSize, WHITE, 10);
        PositionTextInCol(TextFormat("%0.1f", item->weight), content.rectangle.x + 1200, yPos, content.fontSize, WHITE, 10);
    }
}

void DrawTable(TableHeader header, TableContent content)
{
    DrawTableHeader(header);
    DrawTableContent(content);
}

//---------------------------------------------------------------------------------- Button
Button byName;
Button byValue;
Button byRarity;
Button byWeight;


Button gainItem;
Button loseItem;

void InitButtonElement(Button* button, Rectangle rectangle, Color defColor, Color hovColor, const char* text)
{
    button->rectangle = rectangle;
    button->defaultColor = defColor;
    button->hoverColor = hovColor;
    button->text = text;
}

bool IsHovering(Button button)
{
    Vector2 mousePosition = GetMousePosition();
    return CheckCollisionPointRec(mousePosition, button.rectangle);
}

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


    //----------------------------------------------------------- adding/removing items

    InitButtonElement(&gainItem,
    (Rectangle){ 20, 780, 150, 40 },
    DARKGREEN, GREEN,
    "  Gain Item");

    InitButtonElement(&loseItem,
    (Rectangle){ 20, 840, 150, 40 },
    MAROON, RED,
    "  Lose Item");
}

void DrawButtonElement(Button button)
{
    Color buttonColor = IsHovering(button) ? button.hoverColor : button.defaultColor;
    DrawRectangleRec(button.rectangle, buttonColor);
    DrawText(button.text, button.rectangle.x + 10, button.rectangle.y + 10, 20, BLACK);
}

void DrawAllButtons()
{
    DrawButtonElement(byName);
    DrawButtonElement(byValue);
    DrawButtonElement(byRarity);
    DrawButtonElement(byWeight);

    DrawButtonElement(gainItem);
    DrawButtonElement(loseItem);
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

//---------------------------------------------------------------------------------- Whole UI

void InitializeMenu()
{
    InitializePanels();
    InitializeTable();
    InitnializeButtons();
}

void DrawMenu()
{
    DrawAllPanels();
    DrawTable(tableHeader, tableContent);
    DrawAllButtons();
}

void UpdateMenu(Item** inventory, int size)
{
    Category selectedCategory = SelectCategory();

    if (selectedCategory != -1) {
        SortInventory(inventory, size, selectedCategory);
    }
}