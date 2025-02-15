#ifndef UI_H
#define UI_H

#include "hashtable.h"

typedef struct Panel
{
    Rectangle rectangle;
    Color color;
    const char* header;
} Panel;

typedef struct Button
{
    Rectangle rectangle;
    Color defaultColor;
    Color hoverColor;
    const char* text;
    //trigger method
} Button;

typedef  struct Table
{
    Rectangle rectangle;
    int columns;
    int rows;
    const char** columnHeaders;
} Table;



void InitPanelElement(Panel* panel, Rectangle rectangle, Color color, const char* header);
void DrawPanelElement(Panel panel);

void InitButtonElement(Button* button, Rectangle rectangle, Color defColor, Color hovColor, const char* text);

void InitTableElement(Table* table, Rectangle rectangle, int columns, int rows, const char** headers);

#endif //UI_H
