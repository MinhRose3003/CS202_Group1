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
#include "Traffic.h"

class Game
{
private:
	// window
	RenderWindow  window;
	VideoMode videoMode;
	Event event;

	//Music 
	Sound sound, soundCoin, soundCollision, soundComplete, soundEnter;
	SoundBuffer  soundBuffer, soundCoinBuffer, soundCollisionBuffer, soundCompleteBuffer, soundEnterBuffer;

	// background
	Texture BackGroundTexture;
	Sprite Background;

	// menu
	Menu *menu, *pauseMenu, *loseMenu, *completeMenu;
	
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

	//Traffic 
	vector<Traffic> trafficList;

	// Coin 
	vector <Coin *> coinList;

	// text
	Font font;
	Text textPoint, textInput, textLevel;

	int level;
	bool isPlaying; // check game is running, false if "Return" in menu
	bool isCollided; // check lose game
public:
	Game();
	virtual ~Game();

	// init
	void InitVariable(); // set some constant variable
	void InitWindow(); // create window
	void InitBackGround(); // load background + darken background image
	void InitMusic(); // load and play background sound
	void InitSFX();
	void InitTexts(); // create texts box
	void InitMenu(); // create Menu (list of text box)
	
	// game function
	void InitLevel(); // init game level settings (reset player + barriers + coin)
	void CheckLevelUp(); // change settings when level up (upgrade player + barriers, reset coin) 
	void Update(); // update animation + position of objects
	void CheckColide(); // check colide between player and barriers
	void GetCoin(); // +10 if player collects coin
	// UI 
	void PollingEvent(); // hotkeys / escape while playing
	void Run(); // main
	void Pause(); // pause menu
	void Lose(); // lose menu
	void Complete(); // complete menu
	string GetFilename();
	void SaveGame(bool autosave = false); // save to text file or bin file or something
	void LoadGame(bool autosave = false); // load from text file or bin file or something (miss)
	// render
	void Render(); // draw game
	void RenderMenu(); // draw menu
	void RenderPauseMenu(); // draw pause menu
	void RenderLoseMenu(); // draw lose menu
	void RenderCompleteMenu(); // draw complete menu
	void RenderGetFilename(); // draw get filename screen
	void RenderTexts(bool dark = false); // draw texts

	// player
	void InitPlayer(); // init player position, speed
	void UpgradePlayer(); // init player position, increase speed
	void UpdatePlayer(); // update player animation + position
	void RenderPlayer(bool dark = false); // draw player 
	void SavePlayer(ostream &fout);
	void LoadPlayer(istream &fin);

	// barriers
	void InitBarriers(); // init barriers list, counter's range
	void UpgradeBarriers(); // init barriers list, decrease counter's range
	void UpdateBarriers(); // update barriers animation + position
	void RenderBarriers(bool dark = false); // draw barriers
	bool visible(Barrier* barrier); // check if barrier is out of window
	int TypeOfBarrier(Barrier* barrier);
	Barrier* GetBarrier(float x, float y, bool isRight, float speed , int line ); // create new barrier 
	Barrier* GetBarrier(int type, float x, float y, bool isRight, float speed, int line); // create new barrier 
	void SaveBarriers(ostream &fout);
	void LoadBarriers(istream &fin);

	// coin
	void InitCoin(); // create coins at random positions
	void UpdateCoin(); // update coins animation + position
	void RenderCoin(bool dark = false); // draw coins
	void SaveCoin(ostream &fout);
	void LoadCoin(istream &fin);

	//Traffic 
	void InitTraffic();
	void UpdateTraffic();
	void RenderTraffic(bool dark = false); // draw Traffic light 
};

#endif
