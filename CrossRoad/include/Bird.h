#pragma once
#ifndef _BIRD_LIB_
#define _BIRD_LIB_

#include "Animal.h"

class Bird : public Animal
{
public:
	Bird(float x, float y, bool isRight, float speed);

	void InitImage(bool isRight);
	void InitTexture(bool isRight);
	void InitSprite(float x, float y);

	Sprite GetHitbox();
	Image GetImage();
};

#endif
