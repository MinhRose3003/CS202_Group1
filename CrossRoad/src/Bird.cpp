#include "../include/Bird.h"

Bird :: Bird (float x, float y, bool isRight, float speed)
{
	InitVariable(isRight);
	InitTexture(isRight);
	InitSprite(x, y);
}
void Bird::InitTexture(bool isRight)
{

}
void Bird::InitSprite(float x, float y)
{

}

bool Bird::Intersect(FloatRect person)
{
	return false;
}