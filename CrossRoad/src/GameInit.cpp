#include "../include/Game.h"

void Game::InitVariable()
{
	width = 1144;
	height = 840;
	xp = 516;
	yp = 725;
	line = { 180, 235, 300, 360, 430, 490, 565, 615 };
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
}
void Game::InitMusic()
{
	if (!soundBuffer.loadFromFile("Sound/musicGame.wav"))
	{
		cout << "ERROR LOAD MUSIC" << endl;
	}
	sound.setBuffer(soundBuffer);
	sound.setLoop(true);
	//sound.play();
}
void Game::InitTexts()
{
	if (!font.loadFromFile("font/Kenta-qZ3O1.ttf"))
	{
		cout << "Cannot load font from font/Kenta-qZ3O1.ttf\n";
	}

	// Point ...
	textPoint.setCharacterSize(50);
	textPoint.setFont(font);
	textPoint.setFillColor(Color::Black);
	textPoint.setOrigin(textPoint.getLocalBounds().width / 2, textPoint.getLocalBounds().height / 2);
	textPoint.setPosition(100.f, 10.f);

	// PlayerInput ...
	textInput.setCharacterSize(50);
	textInput.setFont(font);
	textInput.setFillColor(Color::White);
	textInput.setOrigin(textInput.getLocalBounds().width / 2, textInput.getLocalBounds().height / 2);
	textInput.setPosition(window.getSize().x / 4, window.getSize().y / 2);
}
void Game::InitMenu()
{
	menu = new Menu(width, height, { "Cross The Road", "Play", "Load", "Exit" });
	pauseMenu = new Menu(width, height, { "Pause", "Resume", "Save", "Load", "Return" });
}

Game::Game()
{
	player = new Player;

	InitVariable();

	InitWindow();

	InitMusic();

	InitBackGround();

	InitTexts();

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