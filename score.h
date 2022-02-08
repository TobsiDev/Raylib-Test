#pragma once
#include <raylib.h>
//#include <raymath.h>

class score
{
private:
    /* data */
public:
    int playerScore;

    score();
    ~score();
    void initScore();
    void updateScore();
};