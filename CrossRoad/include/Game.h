#ifndef _COREGAME_LIB_
#define _COREGAME_LIB_

#include "Player.h"

class Game
{
private:
	RenderWindow  window;
	VideoMode videoMode;
	Event event;

	int maxEnemy;
	int point;
	float timeSpawn;
	float timeSpawnMax;

	vector<RectangleShape > enemies;

	Player * player;
	/*vector<Truck*>  truck;
	vector<Car*> car;
	vector <Bird*> bird;
	vector <Dinausor*> dinausor;*/
	bool isPlaying;
public:
	Game();
	virtual ~Game();

	void InitVariable();
	void InitWindow();
	void InitEnemy();
	void InitPlayer();

	//update 
	void Update();
	void PollingEvent();
	void UpdateEnemy();
	void UpdatePlayer();


	//render 
	void Render();
	void RenderEnemies();
	void RenderPlayer();


	//Function 
	const bool IsRunningGame() const;
	void SpawnEnemy();


	void DrawGame();

	void UpdatePosPlayer(char key);
	void UpdatePosBarrier();
	bool IsPlaying();


};

#endif
