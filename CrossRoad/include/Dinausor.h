#ifndef _DINAUSOR_LIB_
#define _DINAUSOR_LIB_

#include "Animal.h"

class Dinausor : public Animal
{
public:
	Dinausor(int x, int y, bool isRight, float speed);
	void DrawObject();


	~Dinausor();
};

#endif
