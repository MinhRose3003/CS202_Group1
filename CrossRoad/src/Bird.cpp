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

}
void Bird::InitTexture(bool isRight)
{

}
void Bird::InitSprite(float x, float y)
{

}

Sprite Bird::GetHitbox()
{
	return sprite;
}
Image Bird::GetImage()
{
	return image;
}