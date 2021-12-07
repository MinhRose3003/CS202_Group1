#include "../include/Game.h"

void Game::InitCoin()
{
	for (int i = 0; i < coinList.size(); ++i) {
		delete coinList[i];
	}
	coinList.clear();

	for (int i = 0; i < 10; i++)
	{
		int rX = rand() % ((width - 50) - 50 + 1) + 50;
		int rY = rand() % ((height - 50) - 50 + 1) + 50;
		float tmp1 = (float)rX;
		float tmp2 = (float)rY;
		Coin *coin = new Coin(tmp1, tmp2);
		coinList.push_back(coin);
	}
}
void Game::RenderCoin(bool dark)
{
	for (int i = 0; i < coinList.size(); i++)
	{
		coinList[i]->RenderCoin(window, dark);
	}
}

void Game::UpdateCoin()
{
	for (int i = 0; i < coinList.size(); i++)
	{
		coinList[i]->UpdateCoin();
	}
}