#pragma once
#ifndef _DINAUSOR_LIB_
#define _DINAUSOR_LIB_

#include "Animal.h"

class Dinausor : public Animal
{
private : 
	Clock timeAnimation;
	IntRect currenFrame;
public:
	Dinausor(float x, float y, bool isRight, float speed , int line );

	void InitImage(bool isRight);
	void InitTexture(bool isRight);
	void InitSprite(float x, float y);
	void UpdateAnimation();
	Sprite GetHitbox();
	Image GetImage();
};

#endif
