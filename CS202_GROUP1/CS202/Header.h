#pragma once
#ifndef _Header_h_
#define _Header_h_


#include<iostream>
#include <fstream>
#include<vector>
using namespace std;



class Barrier
{
private :
	int x, y;
	bool isRight;
	int color;
public :
	Barrier(int x, int y , bool isRight , int color);
	 void Move(int x, int y);
	virtual void DrawObject();


	~Barrier();
};


class Vehicle : public Barrier
{
public :
	Vehicle(int x, int y, bool isRight , int color) : Barrier(x, y, isRight ,  color) {};	
	virtual void DrawObject();

	~Vehicle();
};


class Animal : public Barrier
{
public :
	Animal(int x, int y, bool isRight, int color) : Barrier(x, y, isRight , color) {};
	virtual void DrawObject();

	~Animal();
};


class Car : public Vehicle
{
public :
	Car(int x, int y, bool isRight , int color) : Vehicle(x, y, isRight , color) {};
	void DrawObject();


	~Car();
};


class Truck : public Vehicle
{
public :
	Truck(int x, int y, bool isRight, int color) : Vehicle(x, y, isRight , color) {};
	void DrawObject();


	~Truck();
};


class Dinausor : public Animal
{
public :
	Dinausor(int x, int y, bool isRight, int color) : Animal(x, y, isRight , color) {};
	void DrawObject();


	~Dinausor();
};


class Bird : public Animal
{
public :
	Bird(int x, int y, bool isRight , int color) : Animal(x, y, isRight , color) {};
	void DrawObject();


	~Bird();
};

class Player
{
private :
	int x, y;
	bool isDead;
public :
	Player(int x, int y);
	void Move(char key);
	bool IsImpact(Barrier*& a);
	bool IsDead();
	void DrawPlayer();


	~Player();

};

class Game
{
private :
	Player player;
	vector<Truck*>  truck;
	vector<Car*> car;
	vector <Bird *> bird;
	vector <Dinausor*> dinausor;
public :
	Game();
	void DrawGame();
	void UpdatePosPlayer(char key );
	void UpdatePosBarrier();

	~Game();
};



#endif // !_Header_h_