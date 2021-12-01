#ifndef _ANIMAL_LIB_
#define _ANIMAL_LIB_

#include "Barrier.h"

class Animal : public Barrier
{
public:
	Animal(int x, int y, bool isRight, int color) : Barrier(x, y, isRight, color) {};
	virtual void DrawObject() = 0;

	~Animal();
};

#endif