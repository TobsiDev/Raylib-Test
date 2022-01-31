#include "window.h"
void makeWindow(){
    
    InitWindow(1280, 720, "Tobsi's Raylib Project");
    SetTargetFPS(60);
    
    //InitPhysics();
    //SetPhysicsTimeStep(1);
    //SetPhysicsGravity(0, 0.1f);

    float testX = 90;
    float testY = 90;

    float playerSpeed = 1.0f;

    Image icon = LoadImage("./res/img/player/Icon-0001.png");
    SetWindowIcon(icon);
    
    /*PhysicsBody testFloor = CreatePhysicsBodyRectangle((Vector2){150, 120}, 100, 20, 10);
    testFloor->enabled = true;
    testFloor->restitution = 0.1f;
    testFloor->mass = 0.1f;
    
    PhysicsBody testFloor2 = CreatePhysicsBodyRectangle((Vector2){250, 120}, 100, 20, 10);
    testFloor2->enabled = true;
    testFloor2->restitution = 0.5f;
    testFloor2->mass = 0.5f;
    
    PhysicsBody testFloor3 = CreatePhysicsBodyRectangle((Vector2){350, 120}, 100, 20, 10);
    testFloor3->enabled = true;
    testFloor3->restitution = 1;
    testFloor3->mass = 1;

    PhysicsBody testFloor4 = CreatePhysicsBodyRectangle((Vector2){450, 120}, 100, 20, 10);
    testFloor4->enabled = true;
    //testFloor4->mass = 1;
    testFloor4->restitution = 10;
    testFloor4->mass = 10;*/

    // Player texture 
    entity player("./res/img/player/SussyFlap-0001.png", 1, 16, 16, 16);
    entity testAnim("./res/img/player/Test_anim-0003.png", 1, 16, 16, 16);
    //testAnim.physicsBody->enabled = false;

/*
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
    bool playerAnimActive = false;*/

    while (!WindowShouldClose())
    {
        //UpdatePhysics();
        

        //TODO:
            // Work on a "physics" system or just implement physics.
            // [ ] Jump
            // [ ] Another platform

        BeginDrawing();
        //player.updatePlayerPhysics(); //
        
        if (IsKeyDown(KEY_LEFT_SHIFT))
        {
            playerSpeed = 2.5f;
        }
        else{
            playerSpeed = 1.0f;
        }
        

        if (IsKeyDown(KEY_LEFT)){player.position.x -= playerSpeed;}
        if (IsKeyDown(KEY_RIGHT)){player.position.x += playerSpeed;}
        if (IsKeyDown(KEY_UP)){player.position.y -= playerSpeed;}
        if (IsKeyDown(KEY_DOWN)){player.position.y += playerSpeed;}
        player.hitbox.x = player.position.x;
        player.hitbox.y = player.position.y;

        if(IsKeyDown(KEY_KP_1)){
            DrawText("Key 1 is down", 10, 70, 28, PURPLE);
            testAnim.isAnimActive = true;
            playAnimLineRe(testAnim, 0, 16);
            //playAnimLine(testAnim.frameCounter, testAnim.currentFrame, 0, 16, testAnim.isAnimActive, testAnim.frameRect, testAnim.width, testAnim.height);
        }
        else if (IsKeyDown(KEY_KP_2)){
            DrawText("Key 2 is down", 10, 70, 28, PURPLE);
            testAnim.isAnimActive = true;
            playAnimLineRe(testAnim, 1, 16);
            //playAnimLine(testAnim.frameCounter, testAnim.currentFrame, 1, 16, testAnim.isAnimActive, testAnim.frameRect, testAnim.width, testAnim.height);
        }
        else if (testAnim.isAnimActive == false && (testAnim.frameCounter != 0 || testAnim.currentFrame != 0)){testAnim.frameCounter = 0; testAnim.currentFrame = 0;/*testAnim.frameRect.x = 0; testAnim.frameRect.y = 0;*/}
        else {DrawText("None of the TestKeys are down", 10, 70, 28, PURPLE); testAnim.isAnimActive = false; testAnim.frameRect.x = 0; testAnim.frameRect.y = 0;}
        
        //std::cout << "Vector (x;y): " << "(" << playerPosition.x << "; " << playerPosition.y << ")" << std::endl;
        

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
        
        //testFloor->isGrounded = true;
        //testFloor->velocity.y = -VELOCITY*4;

        // Draws physics boxes
        /*int physicBodiesCount = GetPhysicsBodiesCount();
        for (size_t i = 0; i < physicBodiesCount; i++)
        {
            PhysicsBody body = GetPhysicsBody(i);
            int vertexCount = GetPhysicsShapeVerticesCount(i);
            for (size_t j = 0; j < vertexCount; j++)
            {
                Vector2 vertexA = GetPhysicsShapeVertex(body, j);
                int jj = (((j + 1) < vertexCount) ? (j + 1) : 0);
                Vector2 vertexB = GetPhysicsShapeVertex(body, jj);

                DrawLine(vertexA.x, vertexA.y, vertexB.x, vertexB.y, LIME);
            }
            
        }*/
        
        
        DrawTextureRec(player.tex, player.frameRect, player.position, WHITE);
        DrawTextureRec(testAnim.tex, testAnim.frameRect, testAnim.position, WHITE);
        DrawRectangleRec(platform, GRAY);
        //CheckCollisionRecs() // https://github.com/raysan5/raylib/blob/master/examples/core/core_2d_camera_platformer.c 

        //player.debugLog();

        DrawFPS(10, 10);
        EndDrawing();
    }

    //UnloadTexture(playerTextu);
    //player.~entity();
    //testAnim.~entity();

    /*DestroyPhysicsBody(testFloor);
    DestroyPhysicsBody(testFloor2);
    DestroyPhysicsBody(testFloor3);
    DestroyPhysicsBody(testFloor4);*/

    //ClosePhysics();

    CloseWindow();     
}

// Todo. 
    // Make the same function, but you can only go down one line. Example: AnimLine(playerObject, GoDownFromX){}
    // Make a struct or a class to have all the information about an entity. 
void playAnim(int& frameCounter, int& currentFrame, int& currentLine, int& animPrLine, int& animLines, bool& active, Rectangle& frameRec, float& textureWidth, float& textureHeight){
    //animLines--;
    //animPrLine--;
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