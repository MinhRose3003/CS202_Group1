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
#include "Coin.h"

class Game
{
private:
	// window
	RenderWindow  window;
	VideoMode videoMode;
	Event event;

	//Music 
	Sound sound;
	SoundBuffer  soundBuffer;

	// background
	Texture BackGroundTexture;
	Sprite Background;
	Texture DarkBackGroundTexture;
	Sprite DarkBackground;

	// menu
	Menu* menu;
	
	// default
	int width, height;
	int xp, yp;
	vector<int> line;

	// player
	Player* player;
	float sp;

	// barriers
	float barrierSpeed;
	int lCount, rCount;
	vector<Barrier*> barriers[8];
	vector<int> count;
	vector<int> countMax;

	// Coin 
	vector <Coin *> coinList;

	// textPoint
	Font font;
	Text textPoint;

	int level;
	bool isPlaying;
public:
	Game();
	virtual ~Game();

	// main
	void InitVariable(); // set some constant variable
	void InitWindow(); // create window
	void InitBackGround(); // load background + darken background image
	void InitMusic(); // load and play background sound
	void InitTextPoint(); // create point text box
	void InitMenu(); // create Menu (list of text box)

	void PollingEvent(); // hotkeys / escape while playing
	void Run(); // main
	void Update(); // update animation + position of objects
	void Render(); // draw game
	void RenderMenu(); // draw menu

	void InitLevel(); // init game level settings (reset player + barriers + coin)
	void CheckLevelUp(); // change settings when level up (upgrade player + barriers, reset coin) 
	void CheckColide(); // check colide between player and barriers

	void LoadGame(); // load from text file or bin file or something (miss)

	// player
	void InitPlayer(); // init player position, speed
	void UpgradePlayer(); // init player position, increase speed
	void UpdatePlayer(); // update player animation + position
	void RenderPlayer(); // draw player 

	// barriers
	void InitBarriers(); // init barriers list, counter's range
	void UpgradeBarriers(); // init barriers list, decrease counter's range
	void UpdateBarriers(); // update barriers animation + position
	void RenderBarries(); // draw barriers
	bool visible(Barrier* barrier); // check if barrier is out of window
	Barrier* GetBarrier(float x, float y, bool isRight, float speed); // create new barrier 

	// coin
	void InitCoin(); // create coins at random positions
	void UpdateCoin(); // update coins animation + position
	void RenderCoin(); // draw coins

	// point
	void UpdateTextPoint(); // update text point (+10 if player collects coin)
	void RenderTextPoint(); // draw point text
};

#endif
