#include "../include/Traffic.h"


void Traffic :: InitTraffic(float x , float y)
{
	if (!redTexture.loadFromFile("Sprite/red.png"))
	{
		cout << "ERROR LOAD TRAFFIC" << endl;
	}
	if (!greenTexture.loadFromFile("Sprite/green.png"))
	{
		cout << "ERROR LOAD TRAFFIC " << endl;
	}

	sprite.setTexture(greenTexture);
	currentFrame = IntRect(0, 0, 454, 459);
	sprite.setTextureRect(currentFrame);
	sprite.setPosition(x, y);
	sprite.setScale(0.28 / 5, 0.28 / 5);
	sprite.setOrigin(0, 459);
}
Traffic::Traffic(float x , float y)
{
	this->x = x;
	this->y = y;

	int a = rand() % (6 - 4 + 1) + 4;
	timeCanMove = (float)a;
	
	canMove = true;
	start = true;

	InitTraffic(x,y);
	clock.restart();
}
void Traffic::RenderTraffic(RenderTarget& window, bool dark)
{
	if (dark )
	{		
		sprite.setColor(Color(80, 80, 80));
	}
	else
	{
		sprite.setColor(Color(255, 255, 255));
	}
	window.draw(sprite);
}
bool Traffic::CanMove()
{
	return canMove;
}
void Traffic::UpdateTraffic()
{
	if (start)
	{
		sprite.setTexture(greenTexture);
		currentFrame = IntRect(0, 0, 454, 459);
		sprite.setTextureRect(currentFrame);
		sprite.setPosition(x, y);
		sprite.setScale(0.28 / 5, 0.28 / 5);
		start = !start;
	}
	if (canMove)
	{
		if (clock.getElapsedTime().asSeconds() >= timeCanMove)
		{
			sprite.setTexture(redTexture);
			currentFrame = IntRect(0, 0, 407, 403);
			sprite.setTextureRect(currentFrame);
			sprite.setPosition(x, y);
			sprite.setScale(0.3/5, 0.3/5);
			clock.restart();
			canMove = !canMove;
		}
	}
	else
	{
		if (clock.getElapsedTime().asSeconds() >= 3.f)
		{
			sprite.setTexture(greenTexture);
			currentFrame = IntRect(0, 0, 454, 459);
			sprite.setTextureRect(currentFrame);
			sprite.setPosition(x, y);
			sprite.setScale(0.28/5, 0.28/5);
			clock.restart();
			canMove = !canMove;
		}
	}
}

Traffic ::~Traffic() {}