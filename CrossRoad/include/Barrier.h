#pragma once
#ifndef _BARRIER_LIB_
#define _BARRIER_LIB_

#include "Support.h"

class Barrier
{
protected:
	Image image;
	Texture texture;
	Sprite sprite;
	float moveSpeed;

public:
	virtual ~Barrier() {}

	virtual void InitImage(bool isRight) = 0;
	virtual void InitTexture(bool isRight) = 0;
	virtual void InitSprite(float x, float y) = 0;
	void InitVariable(bool isRight, float speed);

	void UpdateMovement();
	void Render(RenderTarget &window);

	virtual Sprite GetHitbox() = 0;
	virtual Image GetImage() = 0;
};

#endif