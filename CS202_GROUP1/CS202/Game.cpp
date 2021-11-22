#include "Header.h"




Game::Game() 
{
	Player a(10, 10);
	player = a;
	isPlaying = true;
}

void Game::DrawGame()
{
	player.DrawPlayer();
}
void Game::UpdatePosPlayer(char key)
{
	player.Move(key);
}

bool Game::IsPlaying()
{
	return isPlaying;
}

Game ::~Game()
{
	 truck.clear();
	 car.clear();
	 bird.clear();
	 dinausor.clear();
}