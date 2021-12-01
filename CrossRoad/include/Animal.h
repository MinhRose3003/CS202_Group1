#ifndef _ANIMAL_LIB_
#define _ANIMAL_LIB_

#include "Barrier.h"

class Animal : public Barrier
{
public:
	virtual ~Animal() {}

	virtual void InitTexture(bool isRight) = 0;
	virtual void InitSprite(float x, float y) = 0;

	virtual bool Intersect(FloatRect person) = 0;
};

#endif