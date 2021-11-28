#pragma once
#ifndef _Header_h_
#define _Header_h_

#include "Graphics.h"
#include<iostream>
#include <fstream>
#include<vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;



class Barrier
{
private:
	int x, y;
	bool isRight;
	int color;
public:
	Barrier(int x, int y, bool isRight, int color);
	void Move(int x, int y);
	virtual void DrawObject();


	~Barrier();
};


class Vehicle : public Barrier
{
public:
	Vehicle(int x, int y, bool isRight, int color) : Barrier(x, y, isRight, color) {};
	virtual void DrawObject();

	~Vehicle();
};


class Animal : public Barrier
{
public:
	Animal(int x, int y, bool isRight, int color) : Barrier(x, y, isRight, color) {};
	virtual void DrawObject();

	~Animal();
};


class Car : public Vehicle
{
public:
	Car(int x, int y, bool isRight, int color) : Vehicle(x, y, isRight, color) {};
	void DrawObject();


	~Car();
};


class Truck : public Vehicle
{
public:
	Truck(int x, int y, bool isRight, int color) : Vehicle(x, y, isRight, color) {};
	void DrawObject();


	~Truck();
};


class Dinausor : public Animal
{
public:
	Dinausor(int x, int y, bool isRight, int color) : Animal(x, y, isRight, color) {};
	void DrawObject();


	~Dinausor();
};


class Bird : public Animal
{
public:
	Bird(int x, int y, bool isRight, int color) : Animal(x, y, isRight, color) {};
	void DrawObject();


	~Bird();
};

class Player 
{
private:
	RectangleShape shape;

	float moveSpeed;

public:
	Player(float x = 0.f ,float y =0.f);
	~Player();

	//update
	void UpdateInputKeyBoard();
	void UpdateBound(RenderTarget* window);
	void Update(RenderTarget* window);

	//render
	void Render(RenderTarget* window);

};

class Game
{
private:
	RenderWindow* window;
	VideoMode videoMode;
	Event event;

	int maxEnemy;
	int point;
	float timeSpawn;
	float timeSpawnMax;
	
	vector<RectangleShape > enemies;

	Player player;
	vector<Truck*>  truck;
	vector<Car*> car;
	vector <Bird*> bird;
	vector <Dinausor*> dinausor;
	bool isPlaying;
public:
	Game();
	virtual ~Game();

	void InitVariable();
	void InitWindow();
	void InitEnemy();

	//update 
	void Update();
	void PollingEvent();
	void UpdateEnemy();


	//render 
	void Render();
	void RenderEnemies();


	//Function 
	const bool IsRunningGame() const;	
	void SpawnEnemy();
	

	void DrawGame();

	void UpdatePosPlayer(char key);
	void UpdatePosBarrier();
	bool IsPlaying();

	
};



#endif // !_Header_h_