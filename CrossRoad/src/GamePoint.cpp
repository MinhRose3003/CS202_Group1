#include "../include/Game.h"

void Game::UpdateTextPoint()
{
	for (int i = 0; i < coinList.size(); i++)
	{
		if (PixelPerfectCollision(player->GetHitboxFull(), coinList[i]->GetHitbox(),
			player->GetImage(), coinList[i]->GetImage()))
		{
			player->AddPoint();
			coinList.erase(coinList.begin() + i);
			break;
		}
	}
	textPoint.setString("Point  " + to_string(player->GetPoint()));
}
void Game::RenderTextPoint(bool dark)
{
	window.draw(textPoint);
}