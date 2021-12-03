#include "../include/Coin.h"

void Coin::InitVarible(float x, float y)
{
	this->x = x;
	this->y = y;
}
void Coin::InitImage()
{
	if (!image.loadFromFile("Sprite/Coin/png"))
	{
		cout << "ERROR LOAD COIN ";
	}
}
void Coin::InitTexture()
{
	if (!texture.loadFromFile("Sprite/Coin/png"))
	{
		cout << "ERROR LOAD COIN ";
	}
}
void Coin::InitSprite()
{
	sprite.setTexture(texture);
	currenFrame = IntRect(0, 0, 46.667f, 56.f);
	sprite.setTextureRect(currenFrame);
	sprite.setPosition(x, y);
}
Coin::Coin(float x, float y)
{
	InitVarible(x, y);
	InitImage();
	InitTexture();
	InitSprite();
}

Coin :: ~Coin()
{

}

void Coin::UpdateAnimation()
{
	Clock timeAnimation;
	if (timeAnimation.getElapsedTime().asSeconds() >= 0.1f)
	{
		currenFrame.top = 0.f;
		currenFrame.left += 46.667f;
		if (currenFrame.left >= 280.f)
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
void Coin::RenderCoin(RenderTarget & window)
{
	window.draw(sprite);
}