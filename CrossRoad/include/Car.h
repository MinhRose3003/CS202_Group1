#ifndef _CAR_LIB_
#define _CAR_LIB_

#include "Vehical.h"

class Car : public Vehicle
{
public:
	Car(int x, int y, bool isRight, float speed);
	void DrawObject();

	~Car();
};

#endif
