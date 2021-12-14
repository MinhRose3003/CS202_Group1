#include "../include/Bird.h"

Bird::Bird(float x, float y, bool isRight, float speed, int line )
{
	InitVariable(isRight, speed, line);
	InitImage(isRight);
	InitTexture(isRight);
	InitSprite(x, y);
}

void Bird::InitImage(bool isRight)
{
	if (isRight) {
		if (!image.loadFromFile("Sprite/Bird-right.png"))
		{
			cout << "Cannot find Sprite/Bird.png" << '\n';
		}
	}
	else {
		if (!image.loadFromFile("Sprite/Bird-left.png"))
		{
			cout << "Cannot find Sprite/Bird.png" << '\n';
		}
	}
}
void Bird::InitTexture(bool isRight)
{
	if (isRight) {
		if (!texture.loadFromFile("Sprite/Bird-right.png"))
		{
			cout << "Cannot find Sprite/Bird.png" << '\n';
		}
	}
	else {
		if (!texture.loadFromFile("Sprite/Bird-left.png"))
		{
			cout << "Cannot find Sprite/Bird.png" << '\n';
		}
	}
}
void Bird::InitSprite(float x, float y)
{
	sprite.setTexture(texture);
	currenFrame = IntRect(0, 0, 120.8, 101);
	sprite.setTextureRect(currenFrame);
	sprite.setScale(0.7, 0.7);
	sprite.setPosition(x, y);
}

Sprite Bird::GetHitbox()
{
	return sprite;
}
Image Bird::GetImage()
{
	return image;
}

void Bird::UpdateAnimation()
{

	if (timeAnimation.getElapsedTime().asSeconds() >= 0.15f)
	{
		currenFrame.top = 0.f;
		currenFrame.left += 120.8;
		if (currenFrame.left >= (483.2f))
		{
			currenFrame.left = 0.f;
		}
	}
	timeAnimation.restart();
	sprite.setTextureRect(currenFrame);
}

