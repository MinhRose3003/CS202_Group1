#include "../include/Game.h"

using namespace sf;

void Game::InitVariable()
{
	 maxEnemy = 5;
	 point = 0;
	 timeSpawn = 1000.f;
	 timeSpawnMax = 1000.f;
}

void Game::InitWindow()
{
	videoMode.height = 800;
	videoMode.width = 1000;
	window.create(videoMode, "CrossTheRoad", Style::Titlebar | Style::Close);
	window.setFramerateLimit(144);
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

void Game::UpdatePlayer()
{
	player->Update(window);
}

void Game::Update()
{
	PollingEvent();

	UpdateEnemy();

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

void Game::Render()
{
	window.clear();

	RenderEnemies();
	RenderPlayer();

	window.display();
}
