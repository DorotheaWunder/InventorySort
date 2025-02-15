// #ifndef UI_H
// #define UI_H
//
// #include "raylib.h"
// #include "itemdatabase.h"
// #include "hashsystem.h"
// #include "playerinventory.h"
//
// #define SCREEN_WIDTH 1580
// #define SCREEN_HEIGHT 900
//
// typedef struct Panel
// {
//     Rectangle rectangle;
//     Color color;
//     const char* header;
// } Panel;
//
// typedef struct TableHeader
// {
//     Rectangle rectangle;
//     Color color;
//     const char* headers[4];
//     int fontSize;
// } TableHeader;
//
// typedef struct TableContent
// {
//     Rectangle rectangle;
//     Color color;
//     Item** items;
//     int numRows;
//     int fontSize;
// } TableContent;
//
// typedef struct Button
// {
//     Rectangle rectangle;
//     Color defaultColor;
//     Color hoverColor;
//     const char* text;
//     //trigger method
// } Button;
//
//
// void InitPanelElement(Panel* panel, Rectangle rectangle, Color color, const char* header);
// void DrawPanelElement(Panel panel);
//
// void InitHeaderElement(TableHeader* header, Rectangle rectangle, Color color, const char* headers[4], int fontSize);
// void InitContentElement(TableContent* content, Rectangle rectangle, Color color, Item** items, int numRows, int fontSize);
// void PositionTextInCol(const char* text, float x, float y, float fontSize, Color color, float padding);
// void DrawTableHeader(TableHeader header);
// void DrawTableContent(TableContent content);
// void DrawTable(TableHeader header, TableContent content);
//
// void InitButtonElement(Button* button, Rectangle rectangle, Color defColor, Color hovColor, const char* text);
//
// #endif //UI_H
