#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "ui.h"
#include "hashtable.h"

void InitPanelElement(Panel* panel, Rectangle rectangle, Color color, const char* header)
{
    panel->rectangle = rectangle;
    panel->color = color;
    panel->header = header;
}

void DrawPanelElement(Panel panel)
{
    DrawRectangleRec(panel.rectangle, panel.color);
    DrawText(panel.header, panel.rectangle.x + 10, panel.rectangle.y + 10, 45, WHITE);
}

void InitButtonElement(Button* button, Rectangle rectangle, Color defColor, Color hovColor, const char* text)
{
    button->rectangle = rectangle;
    button->defaultColor = defColor;
    button->hoverColor = hovColor;
    button->text = text;
}

void InitTableElement(Table* table, Rectangle rectangle, int columns, int rows, const char** headers)
{
    table->rectangle = rectangle;
    table->columns = columns;
    table->rows = rows;
    table->columnHeaders = headers;
}