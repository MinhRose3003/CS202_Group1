#include "../include/Game.h"

void Game::InitBarriers() 
{
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i) {
			delete barriers[j][i];
		}
		barriers[j].clear();
	}

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	barrierSpeed = 1.f;
	lCount = 400; // level-up
	rCount = 800; // level-up

	count.assign(8, 0);
	countMax.assign(8, 0);
	for (int i = 0; i < 8; ++i) {
		countMax[i] = uniform_int_distribution<int>(1, 1000)(rng);
	}
}
void Game::UpgradeBarriers()
{
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i) {
			delete barriers[j][i];
		}
		barriers[j].clear();
	}

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	barrierSpeed += 0.5;
	lCount = max(100, lCount - 30);
	rCount = max(200, rCount - 50);

	count.assign(8, 0);
	countMax.assign(8, 0);
	for (int i = 0; i < 8; ++i) {
		countMax[i] = uniform_int_distribution<int>(1, 1000)(rng);
	}
}
void Game::UpdateBarriers()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	for (int j = 0; j < 8; ++j) {
		if (barriers[j].size() && !visible(barriers[j][0]))
		{
			// cout << "Remove car\n";
			barriers[j].erase(barriers[j].begin());
		}
		if (count[j] >= countMax[j])
		{
			if (j & 1)
				barriers[j].push_back(GetBarrier((float)width, (float)line[j], 0, barrierSpeed));
			else
				barriers[j].push_back(GetBarrier(-64, (float)line[j], 1, barrierSpeed));
			count[j] = 0;
			countMax[j] = uniform_int_distribution<int>(lCount, rCount)(rng);
		}
		else
		{
			count[j] += 1;
		}
	}

	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i)
		{
			barriers[j][i]->UpdateMovement();
		}
	}

}
void Game::RenderBarries()
{
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); i++)
		{
			barriers[j][i]->Render(window);
		}
	}
}
Barrier* Game::GetBarrier(float x, float y, bool isRight, float speed)
{
	int random = rand() % (2 - 1 + 1) + 1;
	if (random == 1)
	{
		return new Car(x, y, isRight, speed);
	}
	else if (random == 2)
	{
		return new Truck(x, y, isRight, speed);
	}
	/*else if (random == 3)
	{
		return new Bird(x, y, isRight, speed);
	}
	else
	{
		return new Dinausor(x, y, isRight, speed);
	}*/
}

bool Game::visible(Barrier* barrier)
{
	Sprite n_sprite = barrier->GetHitbox();
	FloatRect n_rect = n_sprite.getGlobalBounds();
	return n_rect.intersects(FloatRect(0, 0, (float)width, (float)height));
}