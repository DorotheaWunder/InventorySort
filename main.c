#include <stdio.h>
#include "raylib.h"
#include "ui.h"
#include "itemdatabase.h"
#include "algorithm.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Inventory UI");

    InitializeMenu();

    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
        UpdateMenu(inventory, INVENTORY_SIZE);


        BeginDrawing();
        ClearBackground(BLACK);


        DrawMenu();




        EndDrawing();
    }

    CloseWindow();

    return 0;
}