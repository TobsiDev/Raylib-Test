#include <raylib.h>
#include <iostream>

// typedef struct EnvItems {
//     EnvItem pipe*;
// } EnvItems;

typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    Color color;
    } EnvItem;


class pipe
{
private:
    
public:
    Vector2 position = {0.0f, 0.0f};
    // EnvItems Pipes[1];
    EnvItem pipeItem[4];
    float deltaT = GetFrameTime();
    float pipeWidth = 120, pipeHeight = 245, topPipeWidth = 160, movementSpeed = -2.0f, FullPipeHeight = 500, spaceBetween = 250;
    float plusY = -100;

    pipe(float x, float y);
    ~pipe();
    EnvItem* getPipe();
    void setPipe();
    void updatePipes();
    void resetPipe(float x);
    
};
