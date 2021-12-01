#include "include/Game.h"


int main()
{
    srand(static_cast<unsigned>(time(NULL))); 
    Game game;

    while (game.IsRunningGame())
    {
        game.Update();



        game.Render();
    }
  

    
    return 0;
}