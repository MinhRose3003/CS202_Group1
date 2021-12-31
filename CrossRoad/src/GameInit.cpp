#include "../include/Game.h"

void Game::InitVariable()
{
	width = 1144;
	height = 840;
	xp = 516;
	yp = 725;
	line = { 220, 280, 345, 405, 480, 540, 605, 665 };
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
	if (!soundBuffer.loadFromFile("Sound/SoundGame.wav"))
	{
		cout << "ERROR LOAD MUSIC" << endl;
	}
	sound.setBuffer(soundBuffer);
	sound.setLoop(true);
	sound.setVolume(0);
	//sound.play();
}
void Game::InitSFX()
{
	//COIN_SFX
	if (!soundCoinBuffer.loadFromFile("Sound/SoundCoin.wav"))
	{
		cout << "ERROR LOAD MUSIC" << endl;
	}
	soundCoin.setBuffer(soundCoinBuffer);
	soundCoin.setLoop(false);

	//Collision_SFX
	if (!soundCollisionBuffer.loadFromFile("Sound/SoundCollision.wav"))
	{
		cout << "ERROR LOAD MUSIC" << endl;
	}
	soundCollision.setBuffer(soundCollisionBuffer);
	soundCollision.setLoop(false);

	//Complete_SFX
	if (!soundCompleteBuffer.loadFromFile("Sound/SoundComplete.wav"))
	{
		cout << "ERROR LOAD MUSIC" << endl;
	}
	soundComplete.setBuffer(soundCompleteBuffer);
	soundComplete.setLoop(false);

	//Enter_SFX
	if (!soundEnterBuffer.loadFromFile("Sound/SoundEnter.wav"))
	{
		cout << "ERROR LOAD MUSIC : Enter" << endl;
	}
	soundEnter.setBuffer(soundEnterBuffer);
	soundEnter.setLoop(false);

	//Ambulance_SFX
	if (!soundAmbulanceBuffer.loadFromFile("Sound/SoundAmbulance.wav"))
	{
		cout << "ERROR LOAD MUSIC : Ambulance" << endl;
	}
	soundAmbulance.setBuffer(soundAmbulanceBuffer);
	soundAmbulance.setLoop(false);
}
void Game::InitTexts()
{
	if (!font.loadFromFile("font/Kenta-qZ3O1.ttf"))
	{
		cout << "Cannot load font from font/Kenta-qZ3O1.ttf\n";
	}

	// Point ...
	textPoint.setCharacterSize(30);
	textPoint.setFont(font);
	textPoint.setFillColor(Color::Black);
	textPoint.setOrigin(textPoint.getLocalBounds().width / 2, textPoint.getLocalBounds().height / 2);
	textPoint.setPosition(50.f, 70.f);

	// Level ...
	textLevel.setCharacterSize(30);
	textLevel.setFont(font);
	textLevel.setFillColor(Color::Black);
	textLevel.setOrigin(textLevel.getLocalBounds().width / 2, textLevel.getLocalBounds().height / 2);
	textLevel.setPosition(50.f, 40.f);

	// Difficult ...
	textDifficult.setCharacterSize(30);
	textDifficult.setFont(font);
	textDifficult.setFillColor(Color::Black);
	textDifficult.setOrigin(textLevel.getLocalBounds().width / 2, textLevel.getLocalBounds().height / 2);
	textDifficult.setPosition(900.f, 40.f);


	// PlayerInput ...
	textInput.setCharacterSize(50);
	textInput.setFont(font);
	textInput.setFillColor(Color::White);
	textInput.setOrigin(textInput.getLocalBounds().width / 2, textInput.getLocalBounds().height / 2);
	textInput.setPosition(window.getSize().x / 4, window.getSize().y / 2);
}
void Game::InitMenu()
{
	menu = new Menu(width, height, { "Cross The Road", "Play", "Load", "Settings", "Exit" }, vector<vector<string> > (5));
	pauseMenu = new Menu(width, height, { "Pause", "Resume", "Save", "Load", "Settings", "Return" }, vector<vector<string> >(6));
	loseMenu = new Menu(width, height, { "You Lose", "Retry", "Return" }, vector<vector<string> >(3));
	completeMenu = new Menu(width, height, { "Complete", "Next", "Return" }, vector<vector<string> >(3));
	settingsMenu = new Menu(width, height, { "Settings", "Difficult", "Sound", "Save and Return"}, { {}, {"Normal", "Hard", "Insane"}, {"On", "Off"}, {} });
	
	settingsMenu->LoadOption();
	SetDifficult(settingsMenu->GetOption(1));
	SetSound(settingsMenu->GetOption(2));
}
void Game::InitTraffic()
{
	trafficList.clear();
	for (int i = 0; i < line.size(); i++)
	{
		Traffic traffic(50.f, (float)line[i] - 20);
		trafficList.push_back(traffic);
	}
}

Game::Game()
{
	player = new Player;
	ambulance = new Ambulance(0, 0, 1, 1.4f, -1);
	count.assign(8, 0);
	countMax.assign(8, 0);

	InitVariable();

	InitWindow();

	InitMusic();

	InitSFX();

	InitBackGround();

	InitTraffic();

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