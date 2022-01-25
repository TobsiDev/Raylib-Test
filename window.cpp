#include "window.h"
void makeWindow(){
    
    InitWindow(1280, 720, "Tobsi's Raylib Project");
    SetTargetFPS(60);
    
    float testX = 90;
    float testY = 90;

    float playerSpeed = 1.0f;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        
        if (IsKeyDown(KEY_LEFT_SHIFT))
        {
            playerSpeed = 2.5f;
        }
        else{
            playerSpeed = 1.0f;
        }
        

        if (IsKeyDown(KEY_LEFT)){testX -= playerSpeed;}
        if (IsKeyDown(KEY_RIGHT)){testX += playerSpeed;}
        if (IsKeyDown(KEY_UP)){testY -= playerSpeed;}
        if (IsKeyDown(KEY_DOWN)){testY += playerSpeed;}
        

        ClearBackground((Color){12, 109, 199, 255});
        DrawFPS(10, 10);
        DrawText("Hey from window", 100, 100, 24, RED);

        Rectangle rec1 = {testX, testY, 22, 32};
        Rectangle platform = {20, 520, 420, 6};

        if (CheckCollisionRecs(rec1, platform))
        {
            DrawText("PLAYER IS TOUCHING THE BOX", 10, 130, 28, RED);
        }
        else{
            DrawText("PLAYER IS NOT TOUCHING THE BOX", 10, 130, 28, GREEN);
        }
        
        
        DrawRectangleRec(rec1, ORANGE); 
        DrawRectangleRec(platform, GRAY);
        //rec1 = DrawRectangle(testX, testY, 22, 32, ORANGE);
        //DrawRectangle
        //CheckCollisionRecs() // https://github.com/raysan5/raylib/blob/master/examples/core/core_2d_camera_platformer.c 

        //pixels((Vector2){testX, testY}, ORANGE, 24, 32);
        //DrawPixelV((Vector2){testX, testY}, ORANGE);

        EndDrawing();
    }

    CloseWindow(); 
    
}

/*void pixels(Vector2 pos, Color col, int width, int height){
    for (size_t h = 0; h <= height; h++)
    {
        for (size_t w = 0; w <= width; w++)
        {
            DrawPixelV((Vector2){pos.x+w, pos.y+h}, col);
        }
        
    }
    
}*/