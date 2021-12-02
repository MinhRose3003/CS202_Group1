#include "../include/Game.h"

using namespace sf;

void Game::InitVariable()
{
	isPlaying = true;

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

	if (!DarkBackGroundTexture.loadFromFile("Sprite/background-darken.png"))
	{
		cout << "Cannot open Sprite/background-darken.png\n";
	}

	DarkBackground.setTexture(DarkBackGroundTexture);
	IntRect DarkcurrentFrame = IntRect(0, 0, width, height);
	DarkBackground.setTextureRect(currentFrame);
}

void Game::InitPlayer()
{
	this->player = new Player((float)xp, (float)yp);
}

void Game::InitGame()
{
	if (player) delete player;
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i) {
			delete barriers[j][i];
		}
		barriers[j].clear();
	}

	InitVariable();
	InitPlayer();
}

void Game::InitMenu()
{
	menu = new Menu(width, height);
}

Game::Game()
{
	InitVariable();
	InitWindow();
	InitMenu();

	player = nullptr;
}

Game::~Game()
{
	delete menu;
	if (player) delete player;
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i) {
			delete barriers[j][i];
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
						InitGame();
						while (isPlaying) {
							Update();
							Render();
							CheckColide();
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

		window.clear();
		
		window.draw(DarkBackground);
		menu->Draw(window);

		window.display();
	}
}

const bool Game::IsRunningGame() const 
{
	return window.isOpen() && isPlaying;
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

void Game::UpdateBarriers()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	for (int j = 0; j < 8; ++j) {
		if (barriers[j].size() && !visible(barriers[j][0])) 
		{
			// cout << "Remove car\n";
			barriers[j].erase(barriers[j].begin());
		}
		if (count[j] >= countMax[j])
		{
			if (j&1)
				barriers[j].push_back(GetBarrier((float)width, (float)line[j], 0, 1.f));
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

bool Game::PixelPerfectCollision(const sf::Sprite& a, const sf::Sprite& b,
	const sf::Image& imgA, const sf::Image& imgB) {
	sf::IntRect boundsA(FToIRect(a.getGlobalBounds()));
	sf::IntRect boundsB(FToIRect(b.getGlobalBounds()));
	sf::IntRect intersection;

	if (boundsA.intersects(boundsB, intersection)) {
		const sf::Transform& inverseA(a.getInverseTransform());
		const sf::Transform& inverseB(b.getInverseTransform());

		const sf::Vector2u& sizeA(imgA.getSize());
		const sf::Vector2u& sizeB(imgB.getSize());

		const sf::Uint8* pixA = imgA.getPixelsPtr();
		const sf::Uint8* pixB = imgB.getPixelsPtr();

		sf::Vector2f vecA, vecB;
		int xMax = intersection.left + intersection.width;
		int yMax = intersection.top + intersection.height;

		for (int x = intersection.left; x < xMax; x++)
			for (int y = intersection.top; y < yMax; y++) {
				vecA = inverseA.transformPoint(x, y);
				vecB = inverseB.transformPoint(x, y);

				int idxA = ((int)vecA.x + ((int)vecA.y)*sizeA.x) * 4 + 3;
				int idxB = ((int)vecB.x + ((int)vecB.y)*sizeB.x) * 4 + 3;

				if (vecA.x > 0 && vecA.y > 0 &&
					vecB.x > 0 && vecB.y > 0 &&
					vecA.x < sizeA.x && vecA.y < sizeA.y &&
					vecB.x < sizeB.x && vecB.y < sizeB.y &&
					pixA[idxA] > 0 &&
					pixB[idxB] > 0) {
					return true;
				}
			}
	}

	return false;
}

bool Game::visible(Barrier* barrier)
{
	Sprite n_sprite = barrier->GetHitbox();
	FloatRect n_rect = n_sprite.getGlobalBounds();
	return n_rect.intersects(FloatRect(0, 0, (float)width, (float)height));
}