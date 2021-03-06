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

	Clock timeAnimation;

public :
	Coin(float x, float y);
	void InitImage();
	void InitTexture();
	void InitSprite(float x, float y);

	void UpdateCoin();
	void UpdateAnimation();

	void RenderCoin(RenderTarget& window, bool dark = false);

	Sprite GetHitbox();
	Image GetImage();
	~Coin();

	Vector2f GetPosition() { return sprite.getPosition(); }
};


#endif // !_Coin_h_
