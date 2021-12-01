#ifndef _VEHICAL_LIB_
#define _VEHICAL_LIB_

#include "Barrier.h"

class Vehicle : public Barrier
{
public:
	virtual ~Vehicle() {}

	virtual void InitTexture(bool isRight) = 0;
	virtual void InitSprite(float x, float y) = 0;

	virtual bool Intersect(FloatRect person) = 0;
};

#endif