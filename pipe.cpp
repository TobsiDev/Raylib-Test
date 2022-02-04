#include "pipe.h"


pipe::pipe(float x, float y)
{
    position = {x, y};

    // EnvItems Pipes[] = {};
    std::cout << "position: " << position.x << " ; " << position.y << std::endl;
}

pipe::~pipe()
{
}

EnvItem* pipe::getPipe(){
    return pipeItem;
}

void pipe::setPipe(){

    float pipeYPosition = (FullPipeHeight - pipeHeight) * (-1);
    pipeItem[0] = {{position.x, pipeYPosition+plusY, pipeWidth, FullPipeHeight}, 1, DARKGREEN};
    pipeItem[1] = {{position.x-((topPipeWidth-pipeWidth)/2), pipeYPosition+FullPipeHeight+plusY, topPipeWidth, (topPipeWidth*0.35f)}, 1, GREEN};
    float bottomPipeY = pipeYPosition+FullPipeHeight+(topPipeWidth*0.35f)+spaceBetween;
    pipeItem[2] = {{position.x, bottomPipeY+(topPipeWidth*0.35f)+plusY, pipeWidth, FullPipeHeight}, 1, DARKGREEN};
    pipeItem[3] = {{position.x-((topPipeWidth-pipeWidth)/2), bottomPipeY+plusY, topPipeWidth, (topPipeWidth*0.35f)}, 1, GREEN};

    // pipeItem[0] = {{position.x, position.y, pipeWidth, pipeHeight}, 1, DARKGREEN};
    // pipeItem[1] = {{position.x-((topPipeWidth-pipeWidth)/2), pipeHeight, topPipeWidth, (topPipeWidth*0.35f/*75*/)}, 1, GREEN};
    
    // pipeItem[2] = {{position.x, GetScreenHeight()-pipeHeight, pipeWidth, pipeHeight}, 1, DARKGREEN};
    // pipeItem[3] = {{position.x-((topPipeWidth-pipeWidth)/2), GetScreenHeight()-pipeHeight-(topPipeWidth*0.35f/*75*/), topPipeWidth, (topPipeWidth*0.35f/*75*/)}, 1, GREEN};

    // pipeItem[2] = {{position.x+250, position.y, pipeWidth, pipeHeight}, 1, DARKGREEN};
    // pipeItem[3] = {{(position.x+250)-((topPipeWidth-pipeWidth)/2), pipeHeight, topPipeWidth, (topPipeWidth*0.35f/*75*/)}, 1, GREEN};
}

void pipe::updatePipes(){
    position.x += movementSpeed;
}

void pipe::resetPipe(float x){
    position.x = x;
}