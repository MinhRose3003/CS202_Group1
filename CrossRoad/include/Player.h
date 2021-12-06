#pragma once
#ifndef _PLAYER_LIB_
#define _PLAYER_LIB_

#include "Support.h"


enum PLAYER_ANIMATION_STATE
{
	IDLE = 0 ,
	MOVING_LEFT , 
	MOVING_RIGHT , 
	MOVING_UP , 
	MOVING_DOWN
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
	void InitVariable(float speed, int point);
	void InitAnimation();

	void Init(float x, float y, float speed, int point = 0);
	
	//update
	void UpdateMovement();
	void UpdateAnimation();
	void UpdateBound(RenderTarget & window);
	void Update(RenderTarget &window);

	//render
	void Render(RenderTarget &window);

	//collision check
	Sprite GetHitbox();
	Sprite GetHitboxFull();
	Image GetImage();

	//Get-Set
	void AddPoint();
	int GetPoint();
};

#endif