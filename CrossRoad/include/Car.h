#ifndef _CAR_LIB_
#define _CAR_LIB_

#include "Vehical.h"

class Car : public Vehicle
{
public:
	Car(float x, float y, bool isRight, float speed);

	void InitTexture(bool isRight);
	void InitSprite(float x, float y);

	bool Intersect(FloatRect person);
};

#endif