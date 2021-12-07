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
void Game::Update()
{
	UpdateBarriers();
	UpdatePlayer();
	UpdateCoin();
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
void Game::GetCoin()
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
		case Event::KeyReleased:
			switch (event.key.code)
			{
			case Keyboard::Escape:
				Pause();
			}
			break;
		}
	}
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
				switch (event.key.code) 
				{
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
							GetCoin();
						}
						break;
					case 2:
						cout << "This function isn't completed!\n";
						break;
					case 3:
						window.close();
						break;
					}
					break;
				case Keyboard::Escape:
					window.close();
				}
			}
		}

		RenderMenu();
	}
}
void Game::Pause()
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
				switch (event.key.code) 
				{
				case Keyboard::Up:
				case Keyboard::W:
					pauseMenu->MoveUp();
					break;
				case Keyboard::Down:
				case Keyboard::S:
					pauseMenu->MoveDown();
					break;
				case Keyboard::Return:
					switch (pauseMenu->GetItem()) {
					case 1:
						return;
					case 2:
						SaveGame();
						break;
					case 3:
						LoadGame();
						break;
					case 4:
						isPlaying = false;
						return;
					}
					break;
				case Keyboard::Escape:
					return;
				}
			}
		}

		RenderPauseMenu();
	}
}
void Game::SaveGame()
{
	string input = GetFilename();
	ofstream fout("save/" + input, ios::out | ios::binary);
	if (!fout) {
		cout << "Cannot open file save/" + input << '\n';
	}

	fout.write((char*)&level, sizeof(int));

	fout.close();
}
void Game::LoadGame()
{
	string input = GetFilename();
	cout << "LoadGame: This function isn't completed!\n";
	ifstream fin("save/" + input, ios::out | ios::binary);
	if (!fin) {
		cout << "Cannot open file save/" + input << '\n';
	}



	fin.close();
}
string Game::GetFilename()
{
	string input;
	while (window.isOpen())
	{
		textInput.setString("Filename  " + input);
		RenderGetFilename();

		while (window.pollEvent(event))
		{
			switch (this->event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::TextEntered:
				switch (event.text.unicode) {
				case '\b':
					if (input.size() > 0)
						input.erase(input.size() - 1, 1);
					break;
				default:
					if (validFileChar(event.text.unicode))
						input += event.text.unicode;
				}
				break;
			case Event::KeyReleased:
				switch (event.key.code) 
				{
				case Keyboard::Return:
					return input;
					break;
				case Keyboard::Escape:
					return "";
					break;
				}
				break;
			}
		}
	}

	return "";
}

void Game::RenderTexts(bool dark)
{
	textPoint.setString("Point  " + to_string(player->GetPoint()));
	window.draw(textPoint);
}
void Game::RenderMenu()
{
	window.clear();

	Background.setColor(sf::Color(80, 80, 80));
	window.draw(Background);

	menu->Draw(window);

	window.display();
}
void Game::RenderPauseMenu()
{
	window.clear();

	Background.setColor(sf::Color(80, 80, 80));
	window.draw(Background);

	RenderCoin(true);
	RenderBarriers(true);
	RenderPlayer(true);
	RenderTexts(true);
	pauseMenu->Draw(window);

	window.display();
}
void Game::RenderGetFilename()
{
	window.clear();

	Background.setColor(sf::Color(80, 80, 80));
	window.draw(Background);

	window.draw(textInput);

	window.display();
}
void Game::Render()
{
	window.clear();

	Background.setColor(sf::Color(255, 255, 255));
	window.draw(Background);

	RenderCoin();
	RenderBarriers();
	RenderPlayer();
	RenderTexts();

	window.display();
}