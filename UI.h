#ifndef UI_H
#define UI_H

#include "raylib.h"
#include "itemdatabase.h"

#define SCREEN_WIDTH 1580
#define SCREEN_HEIGHT 900

typedef struct Panel
{
    Rectangle rectangle;
    Color color;
    const char* header;
} Panel;

typedef struct TableHeader
{
    Rectangle rectangle;
    Color color;
    const char* headers[4];
    int fontSize;
} TableHeader;

typedef struct TableContent
{
    Rectangle rectangle;
    Color color;
    Item** items;
    int numRows;
    int fontSize;
} TableContent;

typedef struct Button
{
    Rectangle rectangle;
    Color defaultColor;
    Color hoverColor;
    const char* text;
    //trigger method
} Button;


void InitPanelElement(Panel* panel, Rectangle rectangle, Color color, const char* header);
void InitializePanels();
void DrawPanelElement(Panel panel);
void DrawAllPanels();

void InitHeaderElement(TableHeader* header, Rectangle rectangle, Color color, const char* headers[4], int fontSize);
void InitContentElement(TableContent* content, Rectangle rectangle, Color color, Item** items, int numRows, int fontSize);
void PositionTextInCol(const char* text, float x, float y, float fontSize, Color color, float padding);
void InitializeTable();
void DrawTableHeader(TableHeader header);
void DrawTableContent(TableContent content);
void DrawTable(TableHeader header, TableContent content);

void InitButtonElement(Button* button, Rectangle rectangle, Color defColor, Color hovColor, const char* text);
void DrawButtonElement(Button button);
void DrawAllButtons();

void InitializeMenu();
void DrawMenu();
void UpdateMenu(Item** inventory, int size);

#endif //UI_H
