#ifndef _DINAUSOR_LIB_
#define _DINAUSOR_LIB_

#include "Animal.h"

class Dinausor : public Animal
{
public:
	void InitTexture(bool isRight);
	void InitSprite(float x, float y);

	bool Intersect(FloatRect person);
};

#endif
