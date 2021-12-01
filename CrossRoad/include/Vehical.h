#ifndef _VEHICAL_LIB_
#define _VEHICAL_LIB_

#include "Barrier.h"

class Vehicle : public Barrier
{
public:
	Vehicle(int x, int y, bool isRight, float speed);
	virtual void DrawObject() = 0;

	virtual ~Vehicle() {};
};

#endif