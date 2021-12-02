#pragma once
#ifndef _COREGAME_LIB_
#define _COREGAME_LIB_

#include "Menu.h"
#include "Player.h"
#include "Barrier.h"
#include "Car.h"
#include "Truck.h"
#include "Bird.h"
#include "Dinausor.h"

class Game
{
private:
	// window
	RenderWindow  window;
	VideoMode videoMode;
	Event event;

	// menu
	Menu *menu;

	// background
	Texture BackGroundTexture;
	Sprite Background;
	Texture DarkBackGroundTexture;
	Sprite DarkBackground;

	//config
	int width, height;
	int xp, yp;
	vector<int> line;

	// player + barriers
	Player * player;
	vector<Barrier*> barriers[8];
	vector<int> count;
	vector<int> countMax;
	bool isPlaying;
public:
	Game();
	virtual ~Game();

	void InitVariable();
	void InitWindow();
	void InitPlayer();
	void InitBackGround();
	void InitMenu();
	void InitGame();
	void LoadGame();

	void Run();

	//update 
	void Update();
	void PollingEvent();
	void UpdatePlayer();
	void UpdateBarriers();
	void CheckColide();

	//render 
	void Render();
	void RenderPlayer();
	void RenderBarries();

	//Function 
	const bool IsRunningGame() const;
	bool visible(Barrier* barrier);
	Barrier* GetBarrier(float x, float y, bool isRight, float speed);
	bool PixelPerfectCollision(const sf::Sprite& a, const sf::Sprite& b,
								const sf::Image& imgA, const sf::Image& imgB);

};

#endif
