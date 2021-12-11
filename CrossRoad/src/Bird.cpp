#include "../include/Bird.h"

Bird :: Bird (float x, float y, bool isRight, float speed)
{
	InitVariable(isRight, speed);
	InitImage(isRight);
	InitTexture(isRight);
	InitSprite(x, y);
}

void Bird::InitImage(bool isRight)
{
	if (isRight) {
		if (!image.loadFromFile("Sprite/Bird.png"))
		{
			cout << "Cannot find Sprite/Bird.png" << '\n';
		}
	}
	else {
		if (!image.loadFromFile("Sprite/Bird.png"))
		{
			cout << "Cannot find Sprite/Bird.png" << '\n';
		}
	}
}
void Bird::InitTexture(bool isRight)
{
	if (isRight) {
		if (!texture.loadFromFile("Sprite/Bird.png"))
		{
			cout << "Cannot find Sprite/Bird.png" << '\n';
		}
	}
	else {
		if (!texture.loadFromFile("Sprite/Bird.png"))
		{
			cout << "Cannot find Sprite/Bird.png" << '\n';
		}
	}
}
void Bird::InitSprite(float x, float y)
{
	sprite.setTexture(texture);
	IntRect currentFrame = IntRect(0, 0, 120.8f,101);
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