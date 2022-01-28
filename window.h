#pragma once
#include "raylib.h"
#include "raymath.h"

#include <iostream>
#include <string>

#include "Instance.h"

void makeWindow();
void playAnim(int& frameCounter, int& currentFrame, int& currentLine, int& animPrLine, int& animLines, bool& activeactive, Rectangle& frameRec, float& textureWidth, float& textureHeight);
//void playAnimLine(int& frameCounter, int& currentFrame, int lineNumb, int animFramesPrLine, bool& active, Rectangle& frameRec, float& textureWidth, float& textureHeight);
void playAnimLineRe(Instance& inst, int lineNumb, int animFramesPrLine);

//void pixels(Vector2 pos, Color col, int width, int height);
