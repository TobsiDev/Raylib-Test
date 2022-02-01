### TODO

- [X] Implement flappy sus movement
- [X] Pipe collision
  - [X] Bottom = death
- [X] Play player death animation when touching the pipes
- [ ] Camera follow player (Or just move the pipes) 

        ```c++

        EnvItem envItems[2] = GetNewPipe(); 

        EnvItem GetNewPipe(){
          GENERATE A TOP AND A BOTTOM PIPE HERE;
          return(pipe); // because it's in an array, I need to remove the older "pipes" form the array. 
        }

        void movePipes(EnvItem pipe){
          const float pipeSpeed = 5;
          pipe.position.x -= 5;
        }

        ```