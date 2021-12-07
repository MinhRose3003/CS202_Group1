#include "../include/Game.h"

void Game::InitPlayer()
{
	sp = 2.f;
	player->Init(xp, yp, sp);
}
void Game::UpgradePlayer()
{
	sp += 0.05;
	player->Init(xp, yp, sp, player->GetPoint());
}
void Game::SavePlayer(ostream &fout)
{

}
void Game::UpdatePlayer()
{
	player->Update(window);
}
void Game::RenderPlayer(bool dark)
{
	player->Render(window, dark);
}
