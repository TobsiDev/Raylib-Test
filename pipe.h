#include <raylib.h>
#include <iostream>

// This is used to make rectangles and hitboxes
typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    Color color;
    } EnvItem;

// This is the pipe class
class pipe
{
private:
    
public:
    Vector2 position = {0.0f, 0.0f}; // The position of the pipe (Top Right corner)
    // EnvItems Pipes[1];
    EnvItem pipeItem[4]; // The array holds the top and bottom pipe
    // EnvItem pipeTrigger[4]; It doesn't like this one. idk why.
    float deltaT = GetFrameTime(); // Delta time
    float pipeWidth = 120, pipeHeight = 245, topPipeWidth = 160, movementSpeed = -2.0f, FullPipeHeight = 500, spaceBetween = 250; // pipe variables
    float plusY = -100; // pipe variable

    // Functions
    pipe(float x, float y);
    ~pipe();
    EnvItem* getPipe();
    void setPipe();
    void updatePipes();
    void resetPipe(float x);
    
};
