#pragma once
#ifndef _DINAUSOR_LIB_
#define _DINAUSOR_LIB_

#include "Animal.h"

class Dinausor : public Animal
{
public:
	Dinausor(float x, float y, bool isRight, float speed , bool hasAnimation);

	void InitImage(bool isRight);
	void InitTexture(bool isRight);
	void InitSprite(float x, float y);

	Sprite GetHitbox();
	Image GetImage();
};

#endif
