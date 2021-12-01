#include "Header.h"



void Player::InitVariable()
{
	moveSpeed = 1.f;
	animationTimer.restart();
	moving = false;
}
void Player::InitTexture()
{
	if (!texture.loadFromFile("Sprite/Player.png"))
	{
		cout << "Minh";
	}
}
void Player::InitSprite()
{
	sprite.setTexture(texture);
	currentFrame = IntRect(0, 0, 32, 32	);
	sprite.setTextureRect(currentFrame);
	sprite.setScale(5.f, 5.f);
}

void Player::InitAnimation()
{

}


Player::Player(float x, float y)
{
	InitVariable();
	InitTexture();
	InitSprite();
	InitAnimation();
}

void Player::UpdateAnimation()
{
	if (moving == false)
	{
		currentFrame.left += 32.f;
		if (currentFrame.left >= 160.f)
		{

		}
	}
}

void Player::UpdateMovement()
{
	moving = false;
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
	{
		moving = true;
		sprite.move(-moveSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
	{
		moving = true;
		sprite.move(moveSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
	{
		moving = true;
		sprite.move(0.f, moveSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
	{
		moving = true;
		sprite.move(0.f, -moveSpeed);
	}
}

//void Player::UpdateBound(RenderTarget & window)
//{
//	FloatRect playerBound = shape.getGlobalBounds();
//	if (playerBound.left <= 0.f)
//	{
//		shape.setPosition(0.f, playerBound.top);
//	}
//	 if (playerBound.left + playerBound.width >= window->getSize().x)
//	{
//		 shape.setPosition(window->getSize().x - playerBound.width, playerBound.top);
//	}
//	 if (playerBound.top <= 0.f)
//	{
//		 shape.setPosition(playerBound.left, 0.f);
//	}
//	 if (playerBound.top + playerBound.height >= window->getSize().y)
//	 {
//		 shape.setPosition(playerBound.left, window->getSize().y - playerBound.height);
//	}
//}

void Player :: Update(RenderTarget & window)
{
	UpdateMovement();
	UpdateAnimation();

	//UpdateBound(window);
}

void Player::Render(RenderTarget &window)
{
	window.draw(sprite);
}

Player :: ~Player()
{
}