#include "../include/Traffic.h"


void Traffic :: InitTraffic()
{
	if (!redTexture.loadFromFile("Sprite/RedTraffic"))
	{
		cout << "ERROR LOAD TRAFFIC" << endl;
	}
	if (!greenTexture.loadFromFile("Sprite/GreenTraffic"))
	{
		cout << "ERROR LOAD TRAFFIC " << endl;
	}
	redSprite.setTexture(redTexture);
	IntRect currentFrame = IntRect(0, 0, 0, 0);
	redSprite.setTextureRect(currentFrame);

	greenSprite.setTexture(greenTexture);
	IntRect tmp = IntRect(0, 0, 0, 0);
	greenSprite.setTextureRect(tmp);
}
Traffic::Traffic(float x , float y)
{
	this->x = x;
	this ->y = y;

	int a = rand() % (6 - 4 + 1) + 4;
	timeCanMove = (float)a;
	
	canMove = true;

	InitTraffic();
	clock.restart();
}
void Traffic::RenderTraffic(RenderTarget& window, bool dark)
{
	if (dark)
	{
		redSprite.setColor(Color(80, 80, 80));
		greenSprite.setColor(Color(80, 80, 80));
	}
	else
	{
		redSprite.setColor(Color(255, 255, 255));
		greenSprite.setColor(Color(255, 255, 255));
	}
	window.draw(redSprite);
	window.draw(greenSprite);
}
bool Traffic::CanMove()
{
	return canMove;
}
void Traffic::UpdateTraffic()
{
	if (canMove)
	{
		if (clock.getElapsedTime().asSeconds() >= timeCanMove)
		{
			redSprite.setColor(Color(255, 255, 255));
			greenSprite.setColor(Color(80, 80, 80));
			clock.restart();
			canMove = !canMove;
		}
	}
	else
	{
		if (clock.getElapsedTime().asSeconds() >= 3.f)
		{
			greenSprite.setColor(Color(255, 255, 255));
			redSprite.setColor(Color(80, 80, 80));
			clock.restart();
			canMove = !canMove;
		}
	}
}

Traffic ::~Traffic()
{

}