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
	if (!isRight)
		currenFrame = IntRect(0, 0, 156, 142);
	else
		currenFrame = IntRect(156 * 4, 0, 156, 142);
	sprite.setTextureRect(currenFrame);
	sprite.setScale(0.4, 0.4);
	sprite.setPosition(x, y - 15);
	sprite.setOrigin(0, 156);
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
		if (!isRight) {
			currenFrame.left -= 156;
			if (currenFrame.left < 0)
			{
				if (currenFrame.top == 0)
					currenFrame.top = 142;
				else
					currenFrame.top = 0;
				currenFrame.left = 156 * 4;
			}
		}
		else {
			currenFrame.left += 156;
			if (currenFrame.left >= 156 * 5) 
			{
				if (currenFrame.top == 0)
					currenFrame.top = 142;
				else
					currenFrame.top = 0;
				currenFrame.left = 0;
			}
		}

		timeAnimation.restart();
		sprite.setTextureRect(currenFrame);
	}
}

