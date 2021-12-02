#include "include/Game.h"


int main()
{
    srand(static_cast<unsigned>(time(NULL))); 

	for (int loop = 0; loop < 5; ++loop) {
		Game game;

		while (game.IsRunningGame())
		{
			game.Update();

			game.Render();

			game.CheckColide();
		}
	}

    
    return 0;
}