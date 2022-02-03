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
    /*player.hSpeed = 275.0f;
    player.jumpSpeed = 250.0f;
    player.gravity = 400;*/
    player.hSpeed = 230.0f;
    player.jumpSpeed = 195.0f; // 150.0f
    player.gravity = 180; // 270 or 170
    player.isAlive = true;
    player.canJump = true;
    player.deathAnimFinished = false;

    /*EnvItem envItems[] = { // Test platformer platforms
        {{ 0, 400, 1000, 200 }, 1, GRAY },
        {{ 300, 300, 400, 10 }, 1, GRAY },
        {{ 250, 200, 100, 10 }, 1, GRAY },
        {{ 650, 350, 100, 10 }, 1, GRAY }
    };*/

    float pipeWidth = 120, pipeHeight = 245, pipeXPosition = 400;
    float topPipeWidth = 160, spaceBetween = 134;
    pipe pipes(560, 0);
    pipes.setPipe();
    // EnvItem testPipe[] = {
    //     pipes.pipeItem[0],
    //     pipes.pipeItem[1]
    // };
    // EnvItem envItems[] = {
    //     // TOP PIPE
    //     {{pipeXPosition, 0, pipeWidth, pipeHeight}, 1, DARKGREEN},
    //     {{pipeXPosition-((topPipeWidth-pipeWidth)/2), pipeHeight, topPipeWidth, (topPipeWidth*0.35f/*75*/)}, 1, GREEN},

    //     // BOTTOM PIPE // TODO: MAKE THIS INTO A FUNCTION AND MAKE IT WORK
    //     //{{pipeXPosition, GetScreenHeight()-pipeHeight-spaceBetween+(topPipeWidth*0.35f), pipeWidth, pipeHeight+spaceBetween}, 1, DARKGREEN},
    //     //{{pipeXPosition-((topPipeWidth-pipeWidth)/2), GetScreenHeight()-pipeHeight-((topPipeWidth*0.65f)), topPipeWidth, (topPipeWidth*0.35f)}, 1, GREEN},
    //     //{{pipeXPosition, pipeHeight, pipeWidth, spaceBetween}, 0, PURPLE},

    //     {{pipeXPosition, GetScreenHeight()-spaceBetween-(topPipeWidth*0.35f), pipeWidth, pipeHeight}, 1, DARKGREEN},
    //     {{pipeXPosition-((topPipeWidth-pipeWidth)/2), GetScreenHeight()-pipeHeight+((topPipeWidth*0.35f/*75*/)/2), topPipeWidth, (topPipeWidth*0.35f/*75*/)}, 1, GREEN},
    //     {{-40, 710, 1360, 20}, 1, (Color){255, 255, 255, 128}}

    // };
    EnvItem deathFloor = {{-40, 710, 1360, 20}, 1, (Color){255, 255, 255, 128}};

    // int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);
    int envItemsLength = sizeof(pipes.pipeItem)/sizeof(pipes.pipeItem[0]);
    
    entity testAnim("./res/img/player/Test_anim-0003.png", 1, 16, 16, 16);

    while (!WindowShouldClose())
    {
        //TODO:
            // Work on a "physics" system or just implement physics.
            // [X] Jump
            // [X] Another platform
        float deltaT = GetFrameTime();
        updatePlayer(&player, pipes.pipeItem, envItemsLength, deltaT);
        updatePlayer(&player, &deathFloor, 1, deltaT);
        if (player.isAlive != false)
        {
            /* code */
            pipes.updatePipes();
        }
        
        
        // pipes.updatePipes(testPipe[1]);
        // testPipe[0].rect.x += 1;
        pipes.setPipe();
        std::cout << "pipes.position : "<< pipes.position.x << " ; " << pipes.position.y << std::endl;
        debugPlayerPhysics(&player);

        BeginDrawing();

        if (player.isAlive == false)
        {
            playDeathAnim(player, 0, 11);
        }
        
        if (IsKeyPressed(KEY_R))
        {
            pipes.resetPipe(560);
            resetPlayer(&player);
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
        //Rectangle platform = {20, 520, 420, 6};

        /*if (CheckCollisionRecs(player.hitbox, platform))
        {
            DrawText("PLAYER IS TOUCHING THE BOX", 10, 130, 28, RED);
            player.isAnimActive = true;
            playAnim(player.frameCounter, player.currentFrame, player.currentLine, player.animFramesPrLine, player.animFrameLines, player.isAnimActive, player.frameRect, player.width, player.height);
        }
        else{
            DrawText("PLAYER IS NOT TOUCHING THE BOX", 10, 130, 28, GREEN);
            player.isAnimActive = false;
        }*/

        for (int i = 0; i < envItemsLength; i++) {DrawRectangleRec(pipes.pipeItem[i].rect, pipes.pipeItem[i].color); std::cout << "pipes.pipeItem[i].rect.x : " << pipes.pipeItem[i].rect.x << std::endl;}
        DrawRectangleRec(deathFloor.rect, deathFloor.color);

        DrawTextureRec(player.tex, player.frameRect, player.position, WHITE);
        DrawTextureRec(testAnim.tex, testAnim.frameRect, testAnim.position, WHITE);
        DrawRectangleLines(player.hitbox.x, player.hitbox.y, player.hitbox.width, player.hitbox.height, RED);
        //DrawRectangleRec(platform, GRAY);
        //player.debugLog();

        DrawFPS(10, 10);
        EndDrawing();
    }

    // pipe pipe(3, 6);
    player.~entity();
    testAnim.~entity();

    CloseWindow();     
}

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

void playDeathAnim(entity& inst, int lineNumb, int animFramesPrLine){
    //std::cout << "Bool: " << inst.isAnimActive << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "lineNumb: " << lineNumb << std::endl;
    std::cout << "animFramesPrLine: " << animFramesPrLine << std::endl;
    std::cout << "currentFrame: " << inst.currentFrame << std::endl;
    std::cout << "frameCounter: " << inst.frameCounter << std::endl;
    if (inst.deathAnimFinished != true && inst.currentFrame < animFramesPrLine)
    {
        inst.frameCounter++;
        if (inst.frameCounter > 4 && inst.deathAnimFinished != true)
        {
            inst.currentFrame++;
            if (inst.currentFrame > animFramesPrLine)
            {
                inst.currentFrame = 0;
                inst.deathAnimFinished = true;
            }
            inst.frameCounter = 0;
        }
    }
    inst.frameRect.x = lineNumb*inst.width;
    inst.frameRect.y = inst.currentFrame*inst.height; 
}

void updatePlayer(entity* player, EnvItem* enviromentItems, int envItemsLength, float deltaTime){
    if (IsKeyDown(KEY_LEFT)){player->position.x -= player->hSpeed*deltaTime;}
    if (IsKeyDown(KEY_RIGHT)){player->position.x += player->hSpeed*deltaTime;}
    /*if (IsKeyDown(KEY_SPACE) && player->canJump) // Platformer jump
    {
        player->speed = -player->jumpSpeed;
        player->canJump = false;
    }*/
    if (IsKeyPressed(KEY_SPACE) && player->canJump && player->isAlive)
    {
        player->speed = -player->jumpSpeed;
        //player->canJump = false;
    }
    
    int hitObst = 0;
    for (int i = 0; i < envItemsLength; i++)
    {
        EnvItem *ei = enviromentItems + i;
        /*if (CheckCollisionRecs(player->hitbox, ei->rect)) // Platformer controls
        {
            hitObst = 1;
            //std::cout << "HIT OBST!!!!!!!!!!!!!" << std::endl;
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
        }*/
        if (CheckCollisionRecs(player->hitbox, ei->rect))
        {
            //hitObst = 1;
            //std::cout << "HIT OBST!!!!!!!!!!!!!" << std::endl;
            player->speed = 0.0f;
            //player->position.y = ei->rect.y-player->frameRect.height; //ei->rect.width-player->height
            //player->hitbox.y = ei->rect.y-player->hitbox.height; //ei->rect.y-player->hitbox.height
            player->isAlive = false;
            player->canJump = false;
            player->gravity = 0;
            player->speed = 0;
            player->hSpeed = 0;
            player->jumpSpeed = 0;
        }

        if (!hitObst)
        {
            player->position.y += player->speed*deltaTime;
            player->hitbox.y += player->speed*deltaTime;
            player->speed += player->gravity*deltaTime;
            //player->canJump = false;
        }else{
            player->canJump = true;
        }
        
        
    }
    player->hitbox.x = player->position.x;
    player->hitbox.y = player->position.y;
}

void resetPlayer(entity* player){
            player->position = (Vector2){100, 200};
            player->hitbox.x = 100;
            player->hitbox.y = 200;
            player->speed = 0;
            player->isAlive = true;
            player->canJump = true;
            player->gravity = 180;
            player->speed = 0;
            player->hSpeed = 230.0f;
            player->jumpSpeed = 195.0f;

            // Animation reset
            player->currentFrame = 0;
            player->currentLine = 0;
            player->frameCounter = 0;
            player->deathAnimFinished = false;
            player->frameRect.x = player->width;
            player->frameRect.y = player->height;
}

void debugPlayerPhysics(entity* player){
    if (IsKeyPressed(KEY_Q))
        {
            player->hSpeed -= 5;
            std::string str = {"player-hSpeed: " + std::to_string(player->hSpeed)};
            DrawText(str.c_str(), 960, 20, 24, PURPLE);
        }else if (IsKeyPressed(KEY_W))
        {
            player->hSpeed += 5;
            std::string str = {"player-hSpeed: " + std::to_string(player->hSpeed)};
            DrawText(str.c_str(), 960, 20, 24, PURPLE);
        }
        else
        {
            std::string str = {"player-hSpeed: " + std::to_string(player->hSpeed)};
            DrawText(str.c_str(), 960, 20, 24, PURPLE);
        }

        if (IsKeyPressed(KEY_A))
        {
            player->jumpSpeed -= 5;
            std::string str = {"player-jumpSpeed: " + std::to_string(player->jumpSpeed)};
            DrawText(str.c_str(), 960, 45, 24, PURPLE);
        }else if (IsKeyPressed(KEY_S))
        {
            player->jumpSpeed += 5;
            std::string str = {"player-jumpSpeed: " + std::to_string(player->jumpSpeed)};
            DrawText(str.c_str(), 960, 45, 24, PURPLE);
        }
        else
        {
            std::string str = {"player-jumpSpeed: " + std::to_string(player->jumpSpeed)};
            DrawText(str.c_str(), 960, 45, 24, PURPLE);
        }
        
        if (IsKeyPressed(KEY_Z))
        {
            player->gravity -= 5;
            std::string str = {"player-gravity: " + std::to_string(player->gravity)};
            DrawText(str.c_str(), 960, 70, 24, PURPLE);
        }else if (IsKeyPressed(KEY_X))
        {
            player->gravity += 5;
            std::string str = {"player-gravity: " + std::to_string(player->gravity)};
            DrawText(str.c_str(), 960, 70, 24, PURPLE);
        }
        else
        {
            std::string str = {"player-gravity: " + std::to_string(player->gravity)};
            DrawText(str.c_str(), 960, 70, 24, PURPLE);
        }

        std::string canJump = {"player canJump: " + std::to_string(player->canJump)};
        DrawText(canJump.c_str(), 960, 95, 24, PURPLE);

        std::string alive = {"player alive: " + std::to_string(player->isAlive)};
        DrawText(alive.c_str(), 960, 120, 24, PURPLE);

}