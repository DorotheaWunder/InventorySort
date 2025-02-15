#include <stdio.h>
#include "raylib.h"
#include "menu.h"
#include "inventory.h"



int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Inventory UI");

    InitializeMenuPanels();
    CreateInventory();

    SetTargetFPS(60);


    while (!WindowShouldClose())
    {

        UpdateMenu(&inventory);


        BeginDrawing();
        ClearBackground(BLACK);

        DrawMenu();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}