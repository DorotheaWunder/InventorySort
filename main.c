#include <stdio.h>
#include "raylib.h"
#include "ui.h"
#include "itemdatabase.h"
#include "algorithm.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Inventory UI");

    InitializeDatabase(inventory);

    Item* playerInventory[INVENTORY_SIZE];
    InitializeMenu(playerInventory, INVENTORY_SIZE);

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