#include "pipe.h"

// (Constructor) Initializes the pipe location
pipe::pipe(float x, float y)
{
    position = {x, y};

    // DEBUG MESSAGE
    std::cout << "position: " << position.x << " ; " << position.y << std::endl;
}

// Destructor
pipe::~pipe()
{
}

// Might have to delete this one (Don't think I use it)
EnvItem* pipe::getPipe(){
    return pipeItem;
}

// Sets the rectangles locations on the "map", so it looks like pipes (Might replace the rectangles with real sprites in the future)
void pipe::setPipe(){

    float pipeYPosition = (FullPipeHeight - pipeHeight) * (-1);

    // Top pipe
    pipeItem[0] = {{position.x, pipeYPosition+plusY, pipeWidth, FullPipeHeight}, 1, DARKGREEN};
    pipeItem[1] = {{position.x-((topPipeWidth-pipeWidth)/2), pipeYPosition+FullPipeHeight+plusY, topPipeWidth, (topPipeWidth*0.35f)}, 1, GREEN};
    float bottomPipeY = pipeYPosition+FullPipeHeight+(topPipeWidth*0.35f)+spaceBetween;

    // Bottom pipe
    pipeItem[2] = {{position.x, bottomPipeY+(topPipeWidth*0.35f)+plusY, pipeWidth, FullPipeHeight}, 1, DARKGREEN};
    pipeItem[3] = {{position.x-((topPipeWidth-pipeWidth)/2), bottomPipeY+plusY, topPipeWidth, (topPipeWidth*0.35f)}, 1, GREEN};
}

// Makes the pipes move towards the player
void pipe::updatePipes(){
    position.x += movementSpeed;
}

// Resets the pipes position
void pipe::resetPipe(float x){
    position.x = x;
}