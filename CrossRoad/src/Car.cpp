#include "../include/Car.h"

Car::Car(float x, float y, bool isRight, float speed) {
	InitVariable(isRight);
	InitTexture(isRight);
	InitSprite(x, y);
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
	//sprite.setScale(0.5, 0.5);
	sprite.setPosition(x, y);
}

bool Car::Intersect(FloatRect person)
{
	FloatRect rect = sprite.getGlobalBounds();
	return rect.intersects(person);
}