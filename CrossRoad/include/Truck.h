#ifndef _TRUCK_LIB_
#define _TRUCK_LIB_

#include "Vehical.h"

class Truck : public Vehicle
{
public:
	Truck(int x, int y, bool isRight, float speed);
	void DrawObject();

	~Truck();
};

#endif