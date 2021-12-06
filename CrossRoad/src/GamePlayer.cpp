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
void Game::UpdatePlayer()
{
	player->Update(window);
}
void Game::RenderPlayer()
{
	player->Render(window);
}
