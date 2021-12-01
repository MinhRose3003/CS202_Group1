#ifndef _CAR_LIB_
#define _CAR_LIB_

#include "Vehical.h"

class Car : public Vehicle
{
public:
	Car(int x, int y, bool isRight, int color) : Vehicle(x, y, isRight, color) {};
	void DrawObject();


	~Car();
};

#endif
