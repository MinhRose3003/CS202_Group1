#pragma once
#ifndef _BIRD_LIB_
#define _BIRD_LIB_

#include "Animal.h"

class Bird : public Animal
{
private:
	Clock timeAnimation;
	IntRect currenFrame;
public:
	Bird(float x, float y, bool isRight, float speed , int line );

	void InitImage(bool isRight);
	void InitTexture(bool isRight);
	void InitSprite(float x, float y);
	void UpdateAnimation();

	Sprite GetHitbox();
	Image GetImage();
};

#endif
