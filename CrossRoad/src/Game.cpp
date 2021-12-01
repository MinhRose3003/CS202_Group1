#include "../include/Game.h"

using namespace sf;

void Game::InitVariable()
{
	 maxEnemy = 5;
	 point = 0;
	 timeSpawn = 1000.f;
	 timeSpawnMax = 200.f;
}

void Game::InitWindow()
{
	videoMode.height = 840;
	videoMode.width = 1144;
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
	IntRect currentFrame = IntRect(0, 0, 1144, 840);
	Background.setTextureRect(currentFrame);
}

void Game::InitPlayer()
{
	this->player = new Player();
}
Game::Game()
{
	InitVariable();
	InitWindow();
	InitPlayer();
}

Game::~Game()
{

	/*truck.clear();
	car.clear();
	bird.clear();
	dinausor.clear();*/
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

void Game::SpawnEnemy()
{
	RectangleShape enemy;
	enemy.setPosition(400.f, 400.f);
	enemy.setSize(Vector2f(100.f, 100.f));
	enemy.setScale(Vector2f(0.5f, 0.5f));
	enemy.setFillColor(Color::Cyan);
	enemy.setOutlineColor(Color::Green);
	enemy.setOutlineThickness(1.f);

	enemies.push_back(enemy);
}

void Game::UpdateEnemy()
{
	if (enemies.size() > maxEnemy) return;
	if (timeSpawn >= timeSpawnMax)
	{
		SpawnEnemy();
		timeSpawn = 0.f;
	}
	else
	{
		timeSpawn += 1.f;
	}

	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].move(10.f, 0.f);
	}
}

void Game::UpdateBarriers()
{
	if (barriers.size() && !(barriers[0]->Intersect(FloatRect(0, 0, 1144, 840))))
	{
		barriers.erase(barriers.begin());
	}
	if (timeSpawn >= timeSpawnMax)
	{
		barriers.push_back(new Car(0, 400, 1, 1.f));
		cout << "Generate a Car " << barriers.size() << '\n';
		timeSpawn = 0;
	}
	else 
	{
		timeSpawn += 1.f;
	}

	for (int i = 0; i < barriers.size(); ++i) 
	{
		barriers[i] -> UpdateMovement();
	}
}

void Game::UpdatePlayer()
{
	player->Update(window);
}

void Game::Update()
{
	PollingEvent();

	//UpdateEnemy();
	UpdateBarriers();

	UpdatePlayer();
}

void Game::RenderPlayer()
{
	player->Render(window);
}
void Game::RenderEnemies()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		window.draw(enemies[i]);
	}
}
void Game::RenderBarries()
{
	for (int i = 0; i < barriers.size(); i++)
	{
		barriers[i]->Render(window);
	}
}

void Game::Render()
{
	window.clear();

	window.draw(Background);

	//RenderEnemies();
	RenderBarries();
	RenderPlayer();

	window.display();
}
