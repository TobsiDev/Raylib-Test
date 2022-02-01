#pragma once
#include <raylib.h>
#include <raymath.h>

#include <iostream>
#include <string>

#include "entity.h"

#define GRAVITY 400
#define PLAYER_JMP_SPD 250.0f
#define PLAYER_HOR_SPD 275.0f

typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    Color color;
    } EnvItem;

void makeWindow();
void playAnim(int& frameCounter, int& currentFrame, int& currentLine, int& animPrLine, int& animLines, bool& activeactive, Rectangle& frameRec, float& textureWidth, float& textureHeight);
//void playAnimLine(int& frameCounter, int& currentFrame, int lineNumb, int animFramesPrLine, bool& active, Rectangle& frameRec, float& textureWidth, float& textureHeight);
void playAnimLineRe(entity& inst, int lineNumb, int animFramesPrLine);

void updatePlayer(entity* player, EnvItem* enviromentItems, int envItemsLength, float deltaTime);