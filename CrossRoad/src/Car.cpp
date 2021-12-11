#include "../include/Car.h"

Car::Car(float x, float y, bool isRight, float speed) {
	InitVariable(isRight, speed);
	InitImage(isRight);
	InitTexture(isRight);
	InitSprite(x, y);
}
void Car::InitImage(bool isRight)
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
void Car::InitTexture(bool isRight)
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
void Car::InitSprite(float x, float y)
{
	sprite.setTexture(texture);
	IntRect currentFrame = IntRect(0, 0, 77, 42);
	sprite.setTextureRect(currentFrame);
	sprite.setScale(1.2, 1.2);
	sprite.setPosition(x, y);
}

//bool Car::Intersect(FloatRect person)
//{
//	FloatRect rect = sprite.getGlobalBounds();
//	if (rect.intersects(person) && person.width < 1144)
//	{
//		cout << person.top << ' ' << person.left << ' ' << person.width << ' ' << person.height << '\n';
//		cout << rect.top << ' ' << rect.left << ' ' << rect.width << ' ' << rect.height << '\n';
//	}
//	return rect.intersects(person);
//}

Sprite Car::GetHitbox()
{
	return sprite;
}
Image Car::GetImage()
{
	return image;
}

void Car::UpdateAnimation()
{

}