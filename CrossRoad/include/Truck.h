#pragma once
#ifndef _TRUCK_LIB_
#define _TRUCK_LIB_

#include "Vehical.h"

class Truck : public Vehicle
{
public:
	Truck(float x, float y, bool isRight, float speed , int line );

	void InitImage(bool isRight);
	void InitTexture(bool isRight);
	void InitSprite(float x, float y);
	void UpdateAnimation();
	Sprite GetHitbox();
	Image GetImage();
};

#endif