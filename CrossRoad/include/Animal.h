#ifndef _ANIMAL_LIB_
#define _ANIMAL_LIB_

#include "Barrier.h"

class Animal : public Barrier
{
public:
	Animal(int x, int y, bool isRight, float speed);
	virtual void DrawObject() = 0;

	virtual ~Animal() {};
};

#endif