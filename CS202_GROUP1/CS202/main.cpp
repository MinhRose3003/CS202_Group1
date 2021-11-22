#include "Header.h"




int main()
{
	Game game;
	game.DrawGame();
	while (game.IsPlaying())
	{
		if (_kbhit())
		{
			char choice = _getch();
			if (choice == 27)
			{
				 // exit game
			}
			else if (choice == 'P')
			{
				// pause game
			}
			else
			{
				game.UpdatePosPlayer(choice);
			}
		}
	}
	_getch();
	return  0;
}