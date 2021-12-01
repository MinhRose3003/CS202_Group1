#ifndef _VEHICAL_LIB_
#define _VEHICAL_LIB_

#include "Barrier.h"

class Vehicle : public Barrier
{
public:
	Vehicle(int x, int y, bool isRight, int color) : Barrier(x, y, isRight, color) {};
	virtual void DrawObject();

	~Vehicle();
};

#endif