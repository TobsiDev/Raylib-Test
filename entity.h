#pragma once
#include <raylib.h>
#include <iostream>

class entity
{
private:
    /* data */
public:
    float OFFSET = -16.0f;
    Image image;
    Texture2D tex;
    Vector2 position = {0.0f, 0.0f};
    Vector2 physicsPosition = {0.0f, 0.0f};
    Rectangle frameRect = {0, 0, width, height};
    Rectangle hitbox = {position.x, position.y, width, height};
    //PhysicsBody physicsBody;
    float width, height;
    int animFramesPrLine, animFrameLines;
    int currentFrame = 0;
    int currentLine = 0;
    int frameCounter = 0;
    bool isAnimActive = false;
    entity(std::string fileLocal, int AnimationFramesPrLine, int AnimationFrameLines, int FrameHeight, int FrameWidth);
    ~entity();

    void debugLog();
    //void updatePlayerPhysics();
};



/*void entity::updatePlayerPhysics(){
    position = physicsBody->position;
    position.x += OFFSET;
    position.y += OFFSET;
    /*
    position.x = ((physicsBody->position.x)+OFFSET);
    position.y = (physicsBody->position.y)+OFFSET;
    */
//}*/
