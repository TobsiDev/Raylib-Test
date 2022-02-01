#include "window.h"
void makeWindow(){

    
    InitWindow(1280, 720, "Tobsi's Raylib Project");
    SetTargetFPS(60);

    float testX = 90;
    float testY = 90;

    float playerSpeed = 1.0f;

    Image icon = LoadImage("./res/img/player/Icon-0001.png");
    SetWindowIcon(icon);
    
    // Player texture 
    entity player("./res/img/player/SussyFlap-0001.png", 1, 16, 16, 16);
    player.position = (Vector2){100, 200};
    player.speed = 0;
    player.hSpeed = 275.0f;
    player.jumpSpeed = 250.0f;
    player.gravity = 400;
    player.canJump = false;

    EnvItem envItems[] = {
        {{ 0, 400, 1000, 200 }, 1, GRAY },
        {{ 300, 300, 400, 10 }, 1, GRAY },
        {{ 250, 200, 100, 10 }, 1, GRAY },
        {{ 650, 350, 100, 10 }, 1, GRAY }
    };
    int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);
    
    entity testAnim("./res/img/player/Test_anim-0003.png", 1, 16, 16, 16);

    while (!WindowShouldClose())
    {
        //TODO:
            // Work on a "physics" system or just implement physics.
            // [X] Jump
            // [X] Another platform
        float deltaT = GetFrameTime();
        updatePlayer(&player, envItems, envItemsLength, deltaT);


        BeginDrawing();        
        
        if (IsKeyPressed(KEY_R))
        {
            player.position = (Vector2){100, 200};
        }
        

        if(IsKeyDown(KEY_KP_1)){
            DrawText("Key 1 is down", 10, 70, 28, PURPLE);
            testAnim.isAnimActive = true;
            playAnimLineRe(testAnim, 0, 16);
        }
        else if (IsKeyDown(KEY_KP_2)){
            DrawText("Key 2 is down", 10, 70, 28, PURPLE);
            testAnim.isAnimActive = true;
            playAnimLineRe(testAnim, 1, 16);
        }
        else if (testAnim.isAnimActive == false && (testAnim.frameCounter != 0 || testAnim.currentFrame != 0)){testAnim.frameCounter = 0; testAnim.currentFrame = 0;/*testAnim.frameRect.x = 0; testAnim.frameRect.y = 0;*/}
        else {DrawText("None of the TestKeys are down", 10, 70, 28, PURPLE); testAnim.isAnimActive = false; testAnim.frameRect.x = 0; testAnim.frameRect.y = 0;}        

        ClearBackground((Color){12, 109, 199, 255});
        DrawText("Hey from window", 100, 100, 24, RED);

        //Rectangle rec1 = {0, 0, 32, 32};
        Rectangle platform = {20, 520, 420, 6};

        if (CheckCollisionRecs(player.hitbox, platform))
        {
            DrawText("PLAYER IS TOUCHING THE BOX", 10, 130, 28, RED);
            player.isAnimActive = true;
            playAnim(player.frameCounter, player.currentFrame, player.currentLine, player.animFramesPrLine, player.animFrameLines, player.isAnimActive, player.frameRect, player.width, player.height);
        }
        else{
            DrawText("PLAYER IS NOT TOUCHING THE BOX", 10, 130, 28, GREEN);
            player.isAnimActive = false;
        }

        for (int i = 0; i < envItemsLength; i++) DrawRectangleRec(envItems[i].rect, envItems[i].color);

        DrawTextureRec(player.tex, player.frameRect, player.position, WHITE);
        DrawTextureRec(testAnim.tex, testAnim.frameRect, testAnim.position, WHITE);
        DrawRectangleLines(player.hitbox.x, player.hitbox.y, player.hitbox.width, player.hitbox.height, RED);
        DrawRectangleRec(platform, GRAY);
        //player.debugLog();

        DrawFPS(10, 10);
        EndDrawing();
    }

    player.~entity();
    testAnim.~entity();

    CloseWindow();     
}

// Todo. 
    // Make the same function, but you can only go down one line. Example: AnimLine(playerObject, GoDownFromX){}
    // Make a struct or a class to have all the information about an entity. 
void playAnim(int& frameCounter, int& currentFrame, int& currentLine, int& animPrLine, int& animLines, bool& active, Rectangle& frameRec, float& textureWidth, float& textureHeight){
    std::cout << "Bool: " << active << std::endl;
    std::cout << "animLines: " << animLines << std::endl;
    std::cout << "animPrLine: " << animPrLine << std::endl;
    std::cout << "currentLine: " << currentLine << std::endl;
    std::cout << "currentFrame: " << currentFrame << std::endl;
    std::cout << "frameCounter: " << frameCounter << std::endl;
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

/*void playAnimLine(int& frameCounter, int& currentFrame, int lineNumb, int animFramesPrLine, bool& active, Rectangle& frameRec, float& textureWidth, float& textureHeight){
    std::cout << "Bool: " << active << std::endl;
    std::cout << "lineNumb: " << lineNumb << std::endl;
    std::cout << "animFramesPrLine: " << animFramesPrLine << std::endl;
    std::cout << "currentFrame: " << currentFrame << std::endl;
    std::cout << "frameCounter: " << frameCounter << std::endl;
    if (active)
    {
        frameCounter++;
        if (frameCounter > 4)
        {
            currentFrame++;
            if (currentFrame > animFramesPrLine)
            {
                currentFrame = 0;
            }
            frameCounter = 0;
        }
    }
    frameRec.x = lineNumb*textureWidth;
    frameRec.y = currentFrame*textureHeight; 
}*/

void playAnimLineRe(entity& inst, int lineNumb, int animFramesPrLine){
    std::cout << "Bool: " << inst.isAnimActive << std::endl;
    std::cout << "lineNumb: " << lineNumb << std::endl;
    std::cout << "animFramesPrLine: " << animFramesPrLine << std::endl;
    std::cout << "currentFrame: " << inst.currentFrame << std::endl;
    std::cout << "frameCounter: " << inst.frameCounter << std::endl;
    if (inst.isAnimActive)
    {
        inst.frameCounter++;
        if (inst.frameCounter > 4)
        {
            inst.currentFrame++;
            if (inst.currentFrame > animFramesPrLine)
            {
                inst.currentFrame = 0;
            }
            inst.frameCounter = 0;
        }
    }
    inst.frameRect.x = lineNumb*inst.width;
    inst.frameRect.y = inst.currentFrame*inst.height; 
}

void updatePlayer(entity* player, EnvItem* enviromentItems, int envItemsLength, float deltaTime){
    if (IsKeyDown(KEY_LEFT)){player->position.x -= PLAYER_HOR_SPD*deltaTime;}
    if (IsKeyDown(KEY_RIGHT)){player->position.x += PLAYER_HOR_SPD*deltaTime;}
    if (IsKeyDown(KEY_SPACE) && player->canJump)
    {
        player->speed = -player->jumpSpeed;
        player->canJump = false;
    }
    
    int hitObst = 0;
    for (int i = 0; i < envItemsLength; i++)
    {
        EnvItem *ei = enviromentItems + i;
        //Vector2 *p = &(player->hitbox);
        if (CheckCollisionRecs(player->hitbox, ei->rect))
        {
            hitObst = 1;
            std::cout << "HIT OBST!!!!!!!!!!!!!" << std::endl;
            player->speed = 0.0f;
            player->position.y = ei->rect.y-player->frameRect.height; //ei->rect.width-player->height
            player->hitbox.y = ei->rect.y-player->hitbox.height; //ei->rect.y-player->hitbox.height
        }

        if (!hitObst)
        {
            player->position.y += player->speed*deltaTime;
            player->hitbox.y += player->speed*deltaTime;
            player->speed += player->gravity*deltaTime;
            player->canJump = false;
        }else{
            player->canJump = true;
        }
        
        
    }
    player->hitbox.x = player->position.x;
    player->hitbox.y = player->position.y;
}
