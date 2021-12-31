#pragma once
#ifndef _AMBULANCE_LIB_
#define _AMBULANCE_LIB_

#include "Vehical.h"

class Ambulance : public Vehicle
{
public:
	Ambulance(float x, float y, bool isRight, float speed , int line );

	void InitImage(bool isRight);
	void InitTexture(bool isRight);
	void InitSprite(float x, float y);
	void UpdateAnimation();
	Sprite GetHitbox();
	Image GetImage();
};

#endif