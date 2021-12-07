#include "../include/Game.h"

void Game::InitPlayer()
{
	sp = 2.f;
	player->Init(xp, yp, sp);
}
void Game::UpgradePlayer()
{
	sp += 0.1;
	player->Init(xp, yp, sp, player->GetPoint());
}
void Game::SavePlayer(ostream &fout)
{
	Vector2f p = player->GetPosition();
	int point = player->GetPoint();
	int state = player->GetState();

	fout.write((char*)&p.x, sizeof(float));
	fout.write((char*)&p.y, sizeof(float));
	fout.write((char*)&sp, sizeof(float));
	fout.write((char*)&point, sizeof(int));
	fout.write((char*)&state, sizeof(int));
}
void Game::LoadPlayer(istream &fin)
{
	float x, y;
	int point, state;

	fin.read((char*)&x, sizeof(float));
	fin.read((char*)&y, sizeof(float));
	fin.read((char*)&sp, sizeof(float));
	fin.read((char*)&point, sizeof(int));
	fin.read((char*)&state, sizeof(int));

	player->Init(x, y, sp, point, state);
}
void Game::UpdatePlayer()
{
	player->Update(window);
}
void Game::RenderPlayer(bool dark)
{
	player->Render(window, dark);
}
