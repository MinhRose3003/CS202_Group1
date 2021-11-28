#include "Header.h"

using namespace sf;

void Game::InitVariable()
{
	window = nullptr;


	 maxEnemy = 5;
	 point = 0;
	 timeSpawn = 1000.f;
	 timeSpawnMax = 1000.f;
}

void Game:: InitWindow()
{
	videoMode.height = 800;
	videoMode.width = 1000;

	window = new RenderWindow(videoMode, "CS202_Group01", Style::Titlebar | Style::Close);
	
	window->setFramerateLimit(60);
}


Game:: Game()
{
	InitVariable();
	InitWindow();

	
}

Game ::~Game()
{
	delete []window;


	/*truck.clear();
	car.clear();
	bird.clear();
	dinausor.clear();*/
}

const bool Game :: IsRunningGame() const 
{
	return window->isOpen();
}

void Game::PollingEvent()
{
	while (window->pollEvent(event))
	{
		switch (this->event.type)
		{
		case Event::Closed:
			window->close();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
			{
				window->close();
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

void Game::RenderEnemies()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		window->draw(enemies[i]);
	}
}

void Game :: Update()
{
	PollingEvent();

	UpdateEnemy();

	player.Update(window);
}

void Game ::Render()
{
	window->clear();

	RenderEnemies();

	player.Render(window);

	window->display();
}
