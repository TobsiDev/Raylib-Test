#pragma once
#include "raylib.h"
#include "raymath.h"

#include <iostream>
#include <string>

void makeWindow();
void playAnim(int& frameCounter, int& currentFrame, int& currentLine, int& animPrLine, int& animLines, bool& activeactive, Rectangle& frameRec, float& textureWidth, float& textureHeight);

//void pixels(Vector2 pos, Color col, int width, int height);
