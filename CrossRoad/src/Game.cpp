#include "../include/Game.h"
using namespace sf;

void Game::InitVariable()
{
	width = 1144;
	height = 840;
	xp = 516; 
	yp = 725;
	line = {180, 235, 300, 360, 430, 490, 565, 615};
}
void Game::InitWindow()
{
	videoMode.height = height;
	videoMode.width = width;
	window.create(videoMode, "CrossTheRoad", Style::Titlebar | Style::Close);
	window.setFramerateLimit(144);

	Image icon;
	if (!icon.loadFromFile("Sprite/icon.png"))
	{
		cout << "Cannot load Sprite/icon.png\n";
	}
	window.setIcon(32, 32, icon.getPixelsPtr());
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

	if (!DarkBackGroundTexture.loadFromFile("Sprite/background-darken.png"))
	{
		cout << "Cannot open Sprite/background-darken.png\n";
	}

	DarkBackground.setTexture(DarkBackGroundTexture);
	IntRect DarkcurrentFrame = IntRect(0, 0, width, height);
	DarkBackground.setTextureRect(currentFrame);
}
void Game::InitMusic()
{
	if (!soundBuffer.loadFromFile("Sound/musicGame.wav"))
	{
		cout << "ERROR LOAD MUSIC" << endl;
	}
	sound.setBuffer(soundBuffer);
	sound.setLoop(true);
	sound.play();
}
void Game::InitTextPoint()
{
	if (!font.loadFromFile("font/Kenta-qZ3O1.ttf"))
	{
		cout << "Cannot load font from font/Kenta-qZ3O1.ttf\n";
	}

	textPoint.setCharacterSize(50);
	textPoint.setFont(font);
	textPoint.setFillColor(Color::Black);
	textPoint.setOrigin(textPoint.getLocalBounds().width / 2, textPoint.getLocalBounds().height / 2);
	textPoint.setPosition(100.f, 10.f);
}
void Game::InitMenu()
{
	menu = new Menu(width, height);
}

Game::Game()
{
	player = new Player;

	InitVariable();

	InitWindow();

	InitMusic();

	InitBackGround();
	
	InitTextPoint();

	InitMenu();
}

Game::~Game()
{
	delete menu;
	delete player;
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i) {
			delete barriers[j][i];
		}
	}
	for (int i = 0; i < coinList.size(); ++i) {
		delete coinList[i];
	}
}

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

