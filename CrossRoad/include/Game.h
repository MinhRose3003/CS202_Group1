#ifndef _COREGAME_LIB_
#define _COREGAME_LIB_

#include "Player.h"
#include "Barrier.h"
#include "Car.h"
#include "Truck.h"
#include "Bird.h"
#include "Dinausor.h"

class Game
{
private:
	RenderWindow  window;
	VideoMode videoMode;
	Event event;

	Texture BackGroundTexture;
	Sprite Background;

	int maxEnemy;
	int point;
	float timeSpawn;
	float timeSpawnMax;

	std::vector<RectangleShape> enemies;

	Player * player;
	std::vector<Barrier*> barriers;
	bool isPlaying;
public:
	Game();
	virtual ~Game();

	void InitVariable();
	void InitWindow();
	//void InitEnemy();
	void InitPlayer();
	void InitBackGround();

	//update 
	void Update();
	void PollingEvent();
	void UpdateEnemy();
	void UpdatePlayer();
	void UpdateBarriers();

	//render 
	void Render();
	void RenderEnemies();
	void RenderPlayer();
	void RenderBarries();

	//Function 
	const bool IsRunningGame() const;
	void SpawnEnemy();


	void DrawGame();

	void UpdatePosPlayer(char key);
	void UpdatePosBarrier();
	bool IsPlaying();


};

#endif
