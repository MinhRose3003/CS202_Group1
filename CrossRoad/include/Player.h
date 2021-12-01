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

	Texture texture;
	Sprite sprite;
	IntRect currentFrame;
	Clock timeAnimation;
	short animationState;

	float moveSpeed;

public:
	Player(float x = 0.f, float y = 0.f);
	~Player();
	void InitTexture();
	void InitSprite(float x, float y);
	void InitVariable();
	void InitAnimation();
	

	//update
	void UpdateMovement();
	void UpdateAnimation();
	void UpdateBound(RenderTarget & window);
	void Update(RenderTarget &window);

	//render
	void Render(RenderTarget &window);

};

#endif