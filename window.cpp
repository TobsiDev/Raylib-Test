#include "window.h"
#include "pipes.h"
void makeWindow(){
    
    InitWindow(1280, 720, "Tobsi's Raylib Project");
    SetTargetFPS(60);
    
    float testX = 90;
    float testY = 90;

    float playerSpeed = 1.0f;

    Image icon = LoadImage("./res/img/player/Icon-0001.png");
    SetWindowIcon(icon);
    
    // Player texture 
    //Image playerText = LoadImage("./res/img/player/Test_anim-0002.png");
    //Texture2D playerTextu = LoadTextureFromImage(playerText); // Frames = 4x4 (4 frames on each axis)

    Image playerText = LoadImage("./res/img/player/SussyFlap-0001.png");
    Texture2D playerTextu = LoadTextureFromImage(playerText); // Frames = 4x4 (4 frames on each axis)

    int playerAnimPrLine = 1;   // Animation frames pr line     (from 0 and up. 0 is included)
    int playerAnimLines = 5;    // Animation lines              (from 0 and up. 0 is included)
    
    float playerTWidth = 16;    //(float)(playerTextu.width/playerAnimPrLine);
    float playerTHeight = 16;   //(float)(playerTextu.height/playerAnimLines);
    int playerCurrentFrame = 0;
    int playerCurrentLine = 0;
    int playerFrameCounter = 0;
    Vector2 playerPosition = {0.0f, 0.0f};
    Rectangle playerFrameRect = {0, 0, playerTWidth, playerTWidth};
    Rectangle playerHitbox = {playerPosition.x, playerPosition.y, playerTWidth, playerTHeight};
    bool playerAnimActive = false;

    pipes pipe1(1, "Commander");
    pipes pipe2(2, "Chad");
    pipes pipe3(3, "Jimbo");
//    pipe1.ID = 1;
//    pipe1.str = "Commander";
/*
    pipes pipe2();
    pipe1.ID = 2;
    pipe1.str = "Chad";

    pipes pipe3();
    pipe1.ID = 3;
    pipe1.str = "Jimbo";
*/
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
        

        if (IsKeyDown(KEY_LEFT)){playerPosition.x -= playerSpeed;}
        if (IsKeyDown(KEY_RIGHT)){playerPosition.x += playerSpeed;}
        if (IsKeyDown(KEY_UP)){playerPosition.y -= playerSpeed;}
        if (IsKeyDown(KEY_DOWN)){playerPosition.y += playerSpeed;}
        playerHitbox.x = playerPosition.x;
        playerHitbox.y = playerPosition.y;

        //std::cout << "Vector (x;y): " << "(" << playerPosition.x << "; " << playerPosition.y << ")" << std::endl;
        

        ClearBackground((Color){12, 109, 199, 255});
        DrawText("Hey from window", 100, 100, 24, RED);

        //Rectangle rec1 = {0, 0, 32, 32};
        Rectangle platform = {20, 520, 420, 6};

        if (CheckCollisionRecs(playerHitbox, platform))
        {
            DrawText("PLAYER IS TOUCHING THE BOX", 10, 130, 28, RED);
            playerAnimActive = true;
            playAnim(playerFrameCounter, playerCurrentFrame, playerCurrentLine, playerAnimPrLine, playerAnimLines, playerAnimActive, playerFrameRect, playerTWidth, playerTHeight);
        }
        else{
            DrawText("PLAYER IS NOT TOUCHING THE BOX", 10, 130, 28, GREEN);
            playerAnimActive = false;
        }
        
        
        DrawTextureRec(playerTextu, playerFrameRect, playerPosition, WHITE); 
        DrawRectangleRec(platform, GRAY);
        //CheckCollisionRecs() // https://github.com/raysan5/raylib/blob/master/examples/core/core_2d_camera_platformer.c 

        pipe1.pipesInit();
        pipe2.pipesInit();
        pipe3.pipesInit();

        DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadTexture(playerTextu);
    CloseWindow(); 

    pipe1.~pipes();
    pipe2.~pipes();
    pipe3.~pipes();
    
}

// Todo. 
    // Make the same function, but you can only go down one line. Eksample: AnimLine(playerObject, GoDownFromX){}
    // Make a struct or a class to have all the information about an entity. 
void playAnim(int& frameCounter, int& currentFrame, int& currentLine, int& animPrLine, int& animLines, bool& active, Rectangle& frameRec, float& textureWidth, float& textureHeight){
    /*std::cout << "Bool: " << active << std::endl;
    std::cout << "animLines: " << animLines << std::endl;
    std::cout << "animPrLine: " << animPrLine << std::endl;
    std::cout << "currentLine: " << currentLine << std::endl;
    std::cout << "currentFrame: " << currentFrame << std::endl;
    std::cout << "frameCounter: " << frameCounter << std::endl;*/
    if (active)
    {
        frameCounter++;
        if (frameCounter > 4)
        {
            currentFrame++;
            if (currentFrame > animPrLine)
            {
                currentFrame = 0;
                currentLine++;
                if (currentLine > animLines)
                {
                    currentLine = 0;
                }
            }
            frameCounter = 0;
        }
    }
    frameRec.x = currentFrame*textureWidth;
    frameRec.y = currentLine*textureHeight; 
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