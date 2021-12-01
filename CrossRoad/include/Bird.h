#ifndef _BIRD_LIB_
#define _BIRD_LIB_

#include "Bird.h"

class Bird : public Animal
{
public:
	Bird(int x, int y, bool isRight, int color) : Animal(x, y, isRight, color) {};
	void DrawObject();


	~Bird();
};

#endif
