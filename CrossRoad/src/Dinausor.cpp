#include "../include/Dinausor.h"

Dinausor::Dinausor(float x, float y, bool isRight, float speed, int line)
{
	InitVariable(isRight, speed, line);
	InitImage(isRight);
	InitTexture(isRight);
	InitSprite(x, y);
}

void Dinausor::InitImage(bool isRight)
{
	if (isRight) {
		if (!image.loadFromFile("Sprite/dinosaur-right.png"))
		{
			cout << "Cannot find Sprite/dinosaur.png" << '\n';
		}
	}
	else {
		if (!image.loadFromFile("Sprite/dinosaur-left.png"))
		{
			cout << "Cannot find Sprite/dinosaur.png" << '\n';
		}
	}
}
void Dinausor::InitTexture(bool isRight)
{
	if (isRight) {
		if (!texture.loadFromFile("Sprite/dinosaur-right.png"))
		{
			cout << "Cannot find Sprite/dinosaur.png" << '\n';
		}
	}
	else {
		if (!texture.loadFromFile("Sprite/dinosaur-left.png"))
		{
			cout << "Cannot find Sprite/dinosaur.png" << '\n';
		}
	}
}
void Dinausor::InitSprite(float x, float y)
{
	sprite.setTexture(texture);
	currenFrame = IntRect(0, 0, 179, 100);
	sprite.setTextureRect(currenFrame);
	sprite.setScale(0.7, 0.7);
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
	if (timeAnimation.getElapsedTime().asSeconds() >= 0.15f)
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