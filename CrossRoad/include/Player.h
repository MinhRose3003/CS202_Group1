#pragma once
#ifndef _PLAYER_LIB_
#define _PLAYER_LIB_

#include "Support.h"


enum PLAYER_ANIMATION_STATE
{
	IDLE = 0 ,
	MOVING_LEFT = 1, 
	MOVING_RIGHT = 2, 
	MOVING_UP = 3, 
	MOVING_DOWN = 4
};

class Player
{
private:

	Image image;
	Texture texture;
	Sprite sprite;
	IntRect currentFrame;
	Clock timeAnimation;
	short animationState;

	int width, height;
	float scale;

	float moveSpeed;

	//Point 
	int point;

public:
	Player(float x = 0.f, float y = 0.f, float speed = 2.f);
	~Player();
	void InitImage();
	void InitTexture();
	void InitSprite(float x, float y);
	void InitVariable(float speed, int point, int state = 3);
	void InitAnimation();

	void Init(float x, float y, float speed, int point = 0, int state = 3);
	
	//update
	void UpdateMovement();
	void UpdateAnimation();
	void UpdateBound(RenderTarget & window);
	void Update(RenderTarget &window);

	//render
	void Render(RenderTarget &window, bool dark = false);

	//collision check
	Sprite GetHitbox();
	Sprite GetHitboxFull();
	Image GetImage();

	//Get-Set
	void AddPoint();
	int GetPoint();
	Vector2f GetPosition() { return sprite.getPosition(); }
	float GetSpeed() { return moveSpeed; }
	int GetState() { return (int)animationState; }
};

#endif