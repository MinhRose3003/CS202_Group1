#include "../include/Game.h"

using namespace sf;

void Game::InitVariable()
{
	 maxEnemy = 5;
	 point = 0;
	 timeSpawn = 1000.f;
	 timeSpawnMax = 50.f;

	 width = 1144;
	 height = 840;
	 xp = 516; 
	 yp = 725;
	 line = {180, 235, 300, 360, 430, 490, 565, 615};

	 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	 count.assign(8, 0);
	 countMax.assign(8, 0);
	 for (int i = 0; i < 8; ++i) {
		 countMax[i] = uniform_int_distribution<int>(200, 500)(rng);
	 }
}

void Game::InitWindow()
{
	videoMode.height = height;
	videoMode.width = width;
	window.create(videoMode, "CrossTheRoad", Style::Titlebar | Style::Close);
	window.setFramerateLimit(144);
	InitBackGround();
}

void Game::InitBackGround()
{
	if (!BackGroundTexture.loadFromFile("Sprite/background.png"))
	{
		cout << "Cannot open Sprite/background.png\n";
	}

	Background.setTexture(BackGroundTexture);
	IntRect currentFrame = IntRect(0, 0, width, height);
	Background.setTextureRect(currentFrame);
}

void Game::InitPlayer()
{
	this->player = new Player((float)xp, (float)yp);
}
Game::Game()
{
	InitVariable();
	InitWindow();
	InitPlayer();
}

Game::~Game()
{
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i) {
			delete barriers[j][i];
		}
	}
}

const bool Game::IsRunningGame() const 
{
	return window.isOpen();
}

void Game::PollingEvent()
{
	while (window.pollEvent(event))
	{
		switch (this->event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
			{
				window.close();
			}
			break;
		}
	}
}




void Game::UpdateBarriers()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	for (int j = 0; j < 8; ++j) {
		if (barriers[j].size() && !(barriers[j][0]->Intersect(FloatRect(0, 0, (float)width, (float)height)))) 
		{
			barriers[j].erase(barriers[j].begin());
		}
		if (count[j] >= countMax[j])
		{
			if (j&1)
				barriers[j].push_back(GetBarrier(width, (float)line[j], 0, 1.f));
			else
				barriers[j].push_back(GetBarrier(0, (float)line[j], 1, 1.f));
			count[j] = 0;
			countMax[j] = uniform_int_distribution<int>(500, 1000)(rng);
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

void Game::UpdatePlayer()
{
	player->Update(window);
}

void Game::Update()
{
	PollingEvent();

	UpdateBarriers();

	UpdatePlayer();
}

void Game::RenderPlayer()
{
	player->Render(window);
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

void Game::Render()
{
	window.clear();

	window.draw(Background);

	RenderBarries();
	RenderPlayer();

	window.display();
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