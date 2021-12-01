#include "../include/Dinausor.h"

Dinausor :: Dinausor(float x, float y, bool isRight, float speed)
{
	InitVariable(isRight);
	InitTexture(isRight);
	InitSprite(x,y);
}

void Dinausor::InitTexture(bool isRight)
{

}
void Dinausor::InitSprite(float x, float y)
{

}

bool Dinausor::Intersect(FloatRect person)
{
	return false;
}