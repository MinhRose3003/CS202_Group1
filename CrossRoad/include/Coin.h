#pragma once 
#ifndef _Coin_h_
#define _Coin_h_

#include "Support.h"

class Coin
{
private:
	Image image;
	Texture texture;
	Sprite sprite;

	IntRect currenFrame;
	float x, y;
public :
	Coin(float x, float y);
	void InitVarible(float x, float y);
	void InitImage();
	void InitTexture();
	void InitSprite();

	void UpdateCoin();
	void UpdateAnimation();

	void RenderCoin(RenderTarget& window);
	~Coin();
};


#endif // !_Coin_h_
