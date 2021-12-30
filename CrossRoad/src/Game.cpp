#include "../include/Game.h"
using namespace sf;

void Game::InitLevel()
{
	isPlaying = true;
	isCollided = false;
	level = 1;
	InitPlayer();
	InitBarriers();
	InitCoin();

	//cout << "Level: " << level << '\n';
}
void Game::CheckLevelUp()
{
	Sprite n_sprite = player->GetHitbox();
	float top = n_sprite.getGlobalBounds().top;
	if (top > 110) return;

	soundComplete.play();
	Complete();
	if (!isPlaying) return;

	level += 1;
	UpgradePlayer();
	UpgradeBarriers();
	InitCoin();

	SaveGame(true);
	//cout << "Level: " << level << '\n';
}
void Game::Update()
{
	UpdateBarriers();
	UpdatePlayer();
	UpdateCoin();
	UpdateTraffic();
}
void Game::CheckColide()
{
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i) {
			if (PixelPerfectCollision(player->GetHitbox(), barriers[j][i]->GetHitbox(),
				player->GetImage(), barriers[j][i]->GetImage())) {
				//cout << "Colide!\n";
				soundCollision.play();				
				isPlaying = false;
				isCollided = true;
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
			this->soundCoin.play();
			coinList.erase(coinList.begin() + i);
			break;
		}
	}

}
void Game::SetDifficult(int x)
{
	difficult = x + 1;
}
void Game::SetSound(int x)
{
	if (x == 0) {
		sound.setVolume(50); 
		soundCoin.setVolume(50); 
		soundCollision.setVolume(100); 
		soundComplete.setVolume(100); 
		soundEnter.setVolume(100);
	}
	else {
		sound.setVolume(0);
		soundCoin.setVolume(0);
		soundCollision.setVolume(0);
		soundComplete.setVolume(0);
		soundEnter.setVolume(0);
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
					soundEnter.play();
					switch (menu->GetItem()) {
					case 1:
						InitLevel();
						SaveGame(true);
						while (isPlaying) {
							PollingEvent();
							Update();
							Render();
							CheckColide();
							CheckLevelUp();
							GetCoin();
							if (isCollided)
								Lose();
						}
						break;
					case 2:
						LoadGame();
						SaveGame(true);
						Pause();
						while (isPlaying) {
							PollingEvent();
							Update();
							Render();
							CheckColide();
							CheckLevelUp();
							GetCoin();
							if (isCollided)
								Lose();
						}
						break;
					case 3:
						Settings();
						break;
					case 4:
						window.close();
						break;
					}
					break;
				/*case Keyboard::Escape:
					window.close();*/
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
					soundEnter.play();
					switch (pauseMenu->GetItem()) {
					case 1:
						return;
					case 2:
						SaveGame();
						break;
					case 3:
						LoadGame();
						SaveGame(true);
						break;
					case 4:
						Settings();
						break;
					case 5:
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
void Game::Lose()
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
					loseMenu->MoveUp();
					break;
				case Keyboard::Down:
				case Keyboard::S:
					loseMenu->MoveDown();
					break;
				case Keyboard::Return:
					soundEnter.play();
					switch (loseMenu->GetItem()) {
					case 1:
						LoadGame(true);
						return;
					case 2:
						return;
					}
					break;
				/*case Keyboard::Escape:
					return;*/
				}
			}
		}

		RenderLoseMenu();
	}
}
void Game::Complete()
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
					completeMenu->MoveUp();
					break;
				case Keyboard::Down:
				case Keyboard::S:
					completeMenu->MoveDown();
					break;
				case Keyboard::Return:
					soundEnter.play();
					switch (completeMenu->GetItem()) {
					case 1:
						return;
					case 2:
						isPlaying = false;
						return;
					}
					break;
					/*case Keyboard::Escape:
						return;*/
				}
			}
		}

		RenderCompleteMenu();
	}
}
void Game::Settings()
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
					settingsMenu->MoveUp();
					break;
				case Keyboard::Down:
				case Keyboard::S:
					settingsMenu->MoveDown();
					break;
				case Keyboard::Left:
				case Keyboard::A:
					settingsMenu->MoveLeft();
					break;
				case Keyboard::Right:
				case Keyboard::D:
					settingsMenu->MoveRight();
					break;
				case Keyboard::Return:
					soundEnter.play();
					switch (settingsMenu->GetItem()) {
					case 1:
					case 2:
						break;
					case 3:
						SetDifficult(settingsMenu->GetOption(1));
						SetSound(settingsMenu->GetOption(2));
						settingsMenu->SaveOption();
						return;
					}
					break;
					/*case Keyboard::Escape:
						return;*/
				}
			}
		}

		RenderSettingsMenu();
	}
}
void Game::SaveGame(bool autosave)
{
	string input;
	if (!autosave)
		input = GetFilename();
	else
		input = "autosave.bin";
	ofstream fout("save/" + input, ios::out | ios::binary);
	if (!fout) {
		cout << "Cannot open file save/" + input << '\n';
		return;
	}

	fout.write((char*)&level, sizeof(int));
	SavePlayer(fout);
	SaveBarriers(fout);
	SaveCoin(fout);

	fout.close();
}
void Game::LoadGame(bool autosave)
{
	string input;
	if (!autosave)
		input = GetFilename();
	else
		input = "autosave.bin";
	ifstream fin("save/" + input, ios::out | ios::binary);
	if (!fin) {
		cout << "Cannot open file save/" + input << '\n';
		return;
	}

	isPlaying = true;
	isCollided = false;

	fin.read((char*)&level, sizeof(int));
	LoadPlayer(fin);
	LoadBarriers(fin);
	LoadCoin(fin);

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

	textLevel.setString("Level  " + to_string(level));
	window.draw(textLevel);

	vector<string> dif = { "Normal", "Hard", "Insane" };
	textDifficult.setString("Difficult  " + dif[difficult - 1]);
	window.draw(textDifficult);
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
	RenderTraffic(true);
	pauseMenu->Draw(window);

	window.display();
}
void Game::RenderLoseMenu()
{
	window.clear();

	Background.setColor(sf::Color(80, 80, 80));
	window.draw(Background);

	RenderCoin(true);
	RenderBarriers(true);
	RenderPlayer(true);
	RenderTexts(true);
	RenderTraffic(true);
	loseMenu->Draw(window);

	window.display();
}
void Game::RenderCompleteMenu()
{
	window.clear();

	Background.setColor(sf::Color(80, 80, 80));
	window.draw(Background);

	RenderCoin(true);
	RenderBarriers(true);
	RenderPlayer(true);
	RenderTexts(true);
	RenderTraffic(true);
	completeMenu->Draw(window);

	window.display();
}
void Game::RenderSettingsMenu()
{
	window.clear();

	Background.setColor(sf::Color(80, 80, 80));
	window.draw(Background);

	settingsMenu->Draw(window);

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
	RenderTraffic();

	window.display();
}