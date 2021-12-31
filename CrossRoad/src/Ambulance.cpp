#include "../include/Ambulance.h"

Ambulance::Ambulance(float x, float y, bool isRight, float speed , int line )
{
	InitVariable(isRight, speed , line);
	InitImage(isRight);
	InitTexture(isRight);
	InitSprite(x, y);
}

void Ambulance::InitImage(bool isRight)
{
	if (!image.loadFromFile("Sprite/ambulance.jpg"))
	{
		cout << "Cannot find Sprite/ambulance.jpg" << '\n';
	}
}
void Ambulance::InitTexture(bool isRight)
{
	if (!texture.loadFromFile("Sprite/ambulance.jpg"))
	{
		cout << "Cannot find Sprite/ambulance.jpg" << '\n';
	}
}
void Ambulance::InitSprite(float x, float y)
{
	sprite.setTexture(texture);
	IntRect currentFrame = IntRect(68, 52, 460, 240);
	sprite.setTextureRect(currentFrame);
	sprite.setPosition(x, y);
	sprite.setScale(0.25f, 0.25f);
	//sprite.setOrigin(0, 240);
}

//bool Truck::Intersect(FloatRect person)
//{
//	FloatRect rect = sprite.getGlobalBounds();
//	return rect.intersects(person);
//}
Sprite Ambulance::GetHitbox()
{
	return sprite;
}
Image Ambulance::GetImage()
{
	return image;
}
void Ambulance::UpdateAnimation()
{

}