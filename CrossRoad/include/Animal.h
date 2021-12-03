#pragma once
#ifndef _ANIMAL_LIB_
#define _ANIMAL_LIB_

#include "Barrier.h"

class Animal : public Barrier
{
public:
	virtual ~Animal() {}

	virtual void InitImage(bool isRight) = 0;
	virtual void InitTexture(bool isRight) = 0;
	virtual void InitSprite(float x, float y) = 0;

	virtual Sprite GetHitbox() = 0;
	virtual Image GetImage() = 0;
};

#endif