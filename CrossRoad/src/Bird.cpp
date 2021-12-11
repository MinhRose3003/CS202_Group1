#include "../include/Bird.h"

Bird :: Bird (float x, float y, bool isRight, float speed , bool hasAnimation)
{
	InitVariable(isRight, speed, hasAnimation);
	InitImage(isRight);
	InitTexture(isRight);
	InitSprite(x, y);
}

void Bird::InitImage(bool isRight)
{
	if (isRight) {
		if (!image.loadFromFile("Sprite/car-right.png"))
		{
			cout << "Cannot find Sprite/car-right.png" << '\n';
		}
	}
	else {
		if (!image.loadFromFile("Sprite/car-left.png"))
		{
			cout << "Cannot find Sprite/car-left.png" << '\n';
		}
	}
}
void Bird::InitTexture(bool isRight)
{
	if (isRight) {
		if (!texture.loadFromFile("Sprite/car-right.png"))
		{
			cout << "Cannot find Sprite/car-right.png" << '\n';
		}
	}
	else {
		if (!texture.loadFromFile("Sprite/car-left.png"))
		{
			cout << "Cannot find Sprite/car-left.png" << '\n';
		}
	}
}
void Bird::InitSprite(float x, float y)
{
	sprite.setTexture(texture);
	IntRect currentFrame = IntRect(0, 0, 77, 42);
	sprite.setTextureRect(currentFrame);
	sprite.setScale(1.2, 1.2);
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