#include "../include/Game.h"
using namespace sf;

void Game::InitLevel()
{
	isPlaying = true;
	level = 1;
	InitPlayer();
	InitBarriers();
	InitCoin();

	cout << "Level: " << level << '\n';
}
void Game::CheckLevelUp()
{
	Sprite n_sprite = player->GetHitbox();
	float top = n_sprite.getGlobalBounds().top;
	if (top > 110) return;

	level += 1;
	UpgradePlayer();
	UpgradeBarriers();
	InitCoin();

	cout << "Level: " << level << '\n';
}
void Game::Run()
{
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (this->event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyReleased:
				switch (event.key.code) {
				case Keyboard::Up:
				case Keyboard::W:
					menu->MoveUp();
					break;
				case Keyboard::Down:
				case Keyboard::S:
					menu->MoveDown();
					break;
				case Keyboard::Return:
					switch (menu->GetItem()) {
					case 1:
						InitLevel();
						while (isPlaying) {
							PollingEvent();
							Update();
							Render();
							CheckColide();
							CheckLevelUp();
						}
						break;
					case 2:
						cout << "This function isn't completed!\n";
						break;
					case 3:
						window.close();
						break;
					}
				}
				
			}
		}

		RenderMenu();
	}
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
				isPlaying = false;
			}
			break;
		}
	}
}


void Game::CheckColide()
{
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i) {
			if (PixelPerfectCollision(player->GetHitbox(), barriers[j][i]->GetHitbox(),
										player->GetImage(), barriers[j][i]->GetImage())) {
				cout << "Colide!\n";
				isPlaying = false;
				return;
			}
		}
	}
}

void Game::Update()
{
	UpdateBarriers();
	UpdatePlayer();
	UpdateCoin();
	UpdateTextPoint();
}

void Game::RenderMenu()
{
	window.clear();

	window.draw(DarkBackground);
	menu->Draw(window);

	window.display();
}
void Game::Render()
{
	window.clear();

	window.draw(Background);
	RenderCoin();
	RenderBarries();
	RenderPlayer();
	RenderTextPoint();

	window.display();
}

