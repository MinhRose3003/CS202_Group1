#include "../include/Truck.h"

Truck :: Truck(float x, float y, bool isRight, float speed , int line )
{
	InitVariable(isRight, speed , line);
	InitImage(isRight);
	InitTexture(isRight);
	InitSprite(x, y);
}

void Truck::InitImage(bool isRight)
{
	if (isRight) {
		if (!image.loadFromFile("Sprite/truck-right.png"))
		{
			cout << "Cannot find Sprite/truck-right.png" << '\n';
		}
	}
	else {
		if (!image.loadFromFile("Sprite/truck-left.png"))
		{
			cout << "Cannot find Sprite/truck-left.png" << '\n';
		}
	}
}
void Truck::InitTexture(bool isRight)
{
	if (isRight) {
		if (!texture.loadFromFile("Sprite/truck-right.png"))
		{
			cout << "Cannot find Sprite/truck-right.png" << '\n';
		}
	}
	else {
		if (!texture.loadFromFile("Sprite/truck-left.png"))
		{
			cout << "Cannot find Sprite/truck-left.png" << '\n';
		}
	}
}
void Truck::InitSprite(float x, float y)
{
	sprite.setTexture(texture);
	IntRect currentFrame = IntRect(0, 0, 494, 306);
	sprite.setTextureRect(currentFrame);
	sprite.setPosition(x, y);
	sprite.setScale(0.25f, 0.25f);
	sprite.setOrigin(0, 306);
}

//bool Truck::Intersect(FloatRect person)
//{
//	FloatRect rect = sprite.getGlobalBounds();
//	return rect.intersects(person);
//}
Sprite Truck::GetHitbox()
{
	return sprite;
}
Image Truck::GetImage()
{
	return image;
}
void Truck::UpdateAnimation()
{

}