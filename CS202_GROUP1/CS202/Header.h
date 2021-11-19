#pragma once
#ifndef _Header_h_
#define _Header_h_


#include<iostream>
#include <fstream>
using namespace std;



class Barrier
{
private :
	int x, y;
	bool isRight;
	int color;
public :
	Barrier(int x, int y , bool isRight , int color);
	virtual void Move(int x, int y);
	virtual void DrawObject();


	~Barrier();
};


class Vehicle : public Barrier
{
public :
	Vehicle(int x, int y, bool isRight , int color) : Barrier(x, y, isRight ,  color) {};
	virtual void Move(int x, int y);
	virtual void DrawObject();

	~Vehicle();
};


class Animal : public Barrier
{
public :
	Animal(int x, int y, bool isRight, int color) : Barrier(x, y, isRight , color) {};
	virtual void Move(int x, int y);
	void DrawObject();

	~Animal();
};


class Car : public Vehicle
{
public :
	Car(int x, int y, bool isRight , int color) : Vehicle(x, y, isRight , color) {};
	void Move(int x, int y);
	void DrawObject();


	~Car();
};


class Truck : public Vehicle
{
public :
	Truck(int x, int y, bool isRight, int color) : Vehicle(x, y, isRight , color) {};
	void Move(int x, int y);
	void DrawObject();


	~Truck();
};


class Dinausor : public Animal
{
public :
	Dinausor(int x, int y, bool isRight, int color) : Animal(x, y, isRight , color) {};
	void Move(int x, int y);
	void DrawObject();


	~Dinausor();
};


class Bird : public Animal
{
public :
	Bird(int x, int y, bool isRight , int color) : Animal(x, y, isRight , color) {};
	void Move(int x, int y);
	void DrawObject();


	~Bird();
};

class Player
{
private :
	int x, y;
	bool isDead;
public :
	Player(int x, int y, bool isDead = true);
	void Move();
	bool IsImpact(Barrier*& a);
	bool IsDead();
	void DrawPlayer();


	~Player();

};

class Game
{
private :
	Player player;
	Truck* truck;
	Car* car;
	Bird* bird;
	Dinausor* dinausor;
public :
	Game();
	void DrawGame();


	~Game();
};



#endif // !_Header_h_