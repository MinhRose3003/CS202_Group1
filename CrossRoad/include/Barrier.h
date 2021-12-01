#ifndef _BARRIER_LIB_
#define _BARRIER_LIB_

#include "Support.h"

class Barrier
{
protected:
	Texture texture;
	Sprite sprite;
	float moveSpeed;

public:
	virtual ~Barrier() {}

	virtual void InitTexture(bool isRight) = 0;
	virtual void InitSprite(float x, float y) = 0;
	void InitVariable(bool isRight);

	void UpdateMovement();
	void Render(RenderTarget &window);

	virtual bool Intersect(FloatRect person) = 0;
};

#endif