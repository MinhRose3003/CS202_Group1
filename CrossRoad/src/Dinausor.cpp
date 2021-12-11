#include "../include/Dinausor.h"

Dinausor :: Dinausor(float x, float y, bool isRight, float speed )
{
	InitVariable(isRight, speed);
	InitImage(isRight);
	InitTexture(isRight);
	InitSprite(x,y);
}

void Dinausor::InitImage(bool isRight)
{
	if (isRight) {
		if (!image.loadFromFile("Sprite/Dinausor.png"))
		{
			cout << "Cannot find Sprite/Dinausor.png" << '\n';
		}
	}
	else {
		if (!image.loadFromFile("Sprite/Dinausor.png"))
		{
			cout << "Cannot find Sprite/Dinausor.png" << '\n';
		}
	}
}
void Dinausor::InitTexture(bool isRight)
{
	if (isRight) {
		if (!texture.loadFromFile("Sprite/Dinausor.png"))
		{
			cout << "Cannot find Sprite/Dinausor.png" << '\n';
		}
	}
	else {
		if (!texture.loadFromFile("Sprite/Dinausor.png"))
		{
			cout << "Cannot find Sprite/Dinausor.png" << '\n';
		}
	}
}
void Dinausor::InitSprite(float x, float y)
{
	sprite.setTexture(texture);
	IntRect currentFrame = IntRect(0, 0, 178, 100);
	sprite.setTextureRect(currentFrame);
	sprite.setScale(1.2, 1.2);
	sprite.setPosition(x, y);
}

Sprite Dinausor::GetHitbox()
{
	return sprite;
}
Image Dinausor::GetImage()
{
	return image;
}
void Dinausor::UpdateAnimation()
{
	if (timeAnimation.getElapsedTime().asSeconds() >= 0.2f)
	{
		currenFrame.top = 0.f;
		currenFrame.left += 179;
		if (currenFrame.left >= 895)
		{
			currenFrame.left = 0.f;
		}
		timeAnimation.restart();
		sprite.setTextureRect(currenFrame);
	}
}