#ifndef _TRUCK_LIB_
#define _TRUCK_LIB_

#include "Vehical.h"

class Truck : public Vehicle
{
public:
	Truck(int x, int y, bool isRight, int color) : Vehicle(x, y, isRight, color) {};
	void DrawObject();


	~Truck();
};

#endif