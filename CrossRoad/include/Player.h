#ifndef _PLAYER_LIB_
#define _PLAYER_LIB_

#include "Support.h"

class Player
{
private:

	Texture texture;
	Sprite sprite;
	float moveSpeed;

public:
	Player(float x = 0.f, float y = 0.f);
	~Player();
	void InitTexture();
	void InitSprite();
	void InitVariable();

	//Animation 
	IntRect currentFrame;

	//update
	void UpdateMovement();
	void UpdateBound(RenderTarget & window);
	void Update(RenderTarget &window);

	//render
	void Render(RenderTarget &window);

};

#endif