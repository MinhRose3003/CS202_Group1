#ifndef _TRUCK_LIB_
#define _TRUCK_LIB_

#include "Vehical.h"

class Truck : public Vehicle
{
public:
	Truck(float x, float y, bool isRight, float speed);

	void InitTexture(bool isRight);
	void InitSprite(float x, float y);

	bool Intersect(FloatRect person);
};

#endif