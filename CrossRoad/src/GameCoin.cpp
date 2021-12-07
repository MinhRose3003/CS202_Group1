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
		int rY = rand() % 8;
		float tmp1 = (float)rX;
		float tmp2 = (float)line[rY];
		Coin *coin = new Coin(tmp1, tmp2);
		coinList.push_back(coin);
	}
}
void Game::SaveCoin(ostream &fout)
{
	int n = coinList.size();
	fout.write((char*)&n, sizeof(int));
	for (int i = 0; i < n; ++i) {
		Vector2f p = coinList[i]->GetPosition();
		fout.write((char*)&p.x, sizeof(float));
		fout.write((char*)&p.y, sizeof(float));
	}
}
void Game::LoadCoin(istream &fin)
{
	for (int i = 0; i < coinList.size(); ++i) {
		delete coinList[i];
	}
	coinList.clear();

	int n;
	fin.read((char*)&n, sizeof(int));
	for (int i = 0; i < n; ++i) {
		float x, y;
		fin.read((char*)&x, sizeof(float));
		fin.read((char*)&y, sizeof(float));
		coinList.push_back(new Coin(x, y));
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