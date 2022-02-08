#include "score.h"
#include <string>

score::score(){
    playerScore = 0;
}

score::~score(){

}

void score::initScore(){
    
}

void score::updateScore(){
    playerScore += 1;
    std::string str {"Score: " + std::to_string(playerScore)};
    int textSize = (MeasureText(str.c_str(), 24))/2;

    DrawText(str.c_str(), (GetScreenWidth()/2)-textSize, 0, 24, WHITE);
    
}