#ifndef _BIRD_LIB_
#define _BIRD_LIB_

#include "Animal.h"

class Bird : public Animal
{
public:
	void InitTexture(bool isRight);
	void InitSprite(float x, float y);

	bool Intersect(FloatRect person);
};

#endif