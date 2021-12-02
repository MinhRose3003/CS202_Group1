#include "../include/Dinausor.h"

Dinausor :: Dinausor(float x, float y, bool isRight, float speed)
{
	InitVariable(isRight, speed);
	InitImage(isRight);
	InitTexture(isRight);
	InitSprite(x,y);
}

void Dinausor::InitImage(bool isRight)
{

}
void Dinausor::InitTexture(bool isRight)
{

}
void Dinausor::InitSprite(float x, float y)
{

}

Sprite Dinausor::GetHitbox()
{
	return sprite;
}
Image Dinausor::GetImage()
{
	return image;
}