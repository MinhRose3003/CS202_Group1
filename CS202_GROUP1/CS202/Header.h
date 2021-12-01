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



//class Barrier
//{
//private:
//	int x, y;
//	float speed;
//	bool isRight;
//
//public:
//	Barrier(int x, int y, bool isRight, float speed );
//	~Barrier();
//	virtual void Update(RenderTarget* window);
//	virtual void Render(RenderTarget* window);
//};
//
//
//class Vehicle : public Barrier
//{
//
//public:
//	Vehicle(int x, int y, bool isRight, float speed);
//	~Vehicle();
//	virtual void Update(RenderTarget* window);
//	virtual void Render(RenderTarget* window);
//};
//
//
//class Animal : public Barrier
//{
//public:
//	Animal(int x, int y, bool isRight, float speed);
//	~Animal();
//	virtual void Update(RenderTarget* window);
//	virtual void Render(RenderTarget* window);
//};
//
//
//class Car : public Vehicle
//{
//private :
//	RectangleShape shape;
//public:
//	Car(int x, int y, bool isRight , float speed) : Vehicle(x, y, isRight , speed) {};
//	~Car();
//	 void Update(RenderTarget* window);
//	 void Render(RenderTarget* window);
//};
//
//
//class Truck : public Vehicle
//{
//private:
//	RectangleShape shape;
//public:
//	Truck(int x, int y, bool isRight , float speed ) : Vehicle(x, y, isRight , speed) {};
//	~Truck();
//	 void Update(RenderTarget* window);
//	 void Render(RenderTarget* window);
//};
//
//
//class Dinausor : public Animal
//{
//private:
//	RectangleShape shape;
//public:
//	Dinausor(int x, int y, bool isRight , float speed) : Animal(x, y, isRight, speed) {};
//	~Dinausor();
//	 void Update(RenderTarget* window);
//	 void Render(RenderTarget* window);
//};
//
//
//class Bird : public Animal
//{
//private:
//	RectangleShape shape;
//public:
//	Bird(int x, int y, bool isRight , float speed) : Animal(x, y, isRight , speed) {};
//	~Bird();
//	 void Update(RenderTarget* window);
//	 void Render(RenderTarget* window);
//};

class Player 
{
private:

	Texture texture;
	Sprite sprite;
	IntRect currentFrame;
	Clock animationTimer;
	bool moving;
	float moveSpeed;

public:
	Player(float x = 0.f ,float y =0.f);
	~Player();
	void InitTexture();
	void InitSprite();
	void InitVariable();
	void InitAnimation();

	//Animation 
	

	//update
	void UpdateMovement();
	void UpdateAnimation();
	void UpdateBound(RenderTarget & window);
	void Update(RenderTarget &window);

	//render
	void Render(RenderTarget &window);

};

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



#endif // !_Header_h_