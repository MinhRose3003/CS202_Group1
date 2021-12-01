#ifndef _DINAUSOR_LIB_
#define _DINAUSOR_LIB_

#include "Animal.h"

class Dinausor : public Animal
{
public:
	Dinausor(int x, int y, bool isRight, int color) : Animal(x, y, isRight, color) {};
	void DrawObject();


	~Dinausor();
};

#endif
