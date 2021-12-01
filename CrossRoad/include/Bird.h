#ifndef _BIRD_LIB_
#define _BIRD_LIB_

#include "Bird.h"

class Bird : public Animal
{
public:
	Bird(int x, int y, bool isRight, float speed);
	void DrawObject();

	~Bird();
};

#endif
