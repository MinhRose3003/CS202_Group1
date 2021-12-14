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
	bool isRight;
	int line;
public:
	virtual ~Barrier() {}

	virtual void InitImage(bool isRight) = 0;
	virtual void InitTexture(bool isRight) = 0;
	virtual void InitSprite(float x, float y) = 0;
	void InitVariable(bool isRight, float speed , int line  );

	void UpdateMovement(bool canMove);
	virtual void UpdateAnimation() = 0;
	void Render(RenderTarget &window, bool dark = false);

	virtual Sprite GetHitbox() = 0;
	virtual Image GetImage() = 0;

	Vector2f GetPosition() { return sprite.getPosition(); }
	bool GetIsRight() { return isRight; }
	float GetSpeed() { return moveSpeed; }
};

#endif