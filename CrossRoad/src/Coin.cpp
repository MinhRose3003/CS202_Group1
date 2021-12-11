#include "../include/Coin.h"


void Coin::InitImage()
{
	if (!image.loadFromFile("Sprite/Coin2.png"))
	{
		cout << "ERROR LOAD COIN " << endl;
	}
}
void Coin::InitTexture()
{
	if (!texture.loadFromFile("Sprite/Coin2.png"))
	{
		cout << "ERROR LOAD COIN " << endl;
	}
}
void Coin::InitSprite(float x , float y)
{
	sprite.setTexture(texture);
	currenFrame = IntRect(0, 0, 860/6, 167);
	sprite.setTextureRect(currenFrame);
	sprite.setPosition(x, y);
	sprite.setScale(0.3f, 0.3f);
}

Coin::Coin(float x, float y)
{
	InitImage();
	InitTexture();
	InitSprite(x,y);
}

Coin :: ~Coin()
{

}

void Coin::UpdateAnimation()
{
	if (timeAnimation.getElapsedTime().asSeconds() >= 0.2f)
	{
		currenFrame.top = 0.f;
		currenFrame.left += 143.334f;
		if (currenFrame.left >= 2150/3)
		{
			currenFrame.left = 0.f;
		}
		timeAnimation.restart();
		sprite.setTextureRect(currenFrame);
	}
}

void Coin::UpdateCoin()
{
	UpdateAnimation();
}
void Coin::RenderCoin(RenderTarget & window, bool dark)
{
	if (dark)
		sprite.setColor(Color(80, 80, 80));
	else
		sprite.setColor(Color(255, 255, 255));
	window.draw(sprite);
}

Sprite Coin ::GetHitbox()
{
	return sprite;
}
Image Coin::GetImage()
{
	return image;
}

