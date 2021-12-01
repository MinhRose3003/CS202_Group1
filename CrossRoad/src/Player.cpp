#include "../include/Player.h"

void Player::InitVariable()
{
	moveSpeed = 1.f;
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
	currentFrame = IntRect(0, 0, 32, 32);
	sprite.setTextureRect(currentFrame);

	cout << "test";
}


Player::Player(float x, float y)
{
	InitVariable();
	InitTexture();
	InitSprite();
}


void Player::UpdateMovement()
{
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
	{
		sprite.move(-moveSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
	{
		sprite.move(moveSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
	{
		sprite.move(0.f, moveSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
	{
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

	//UpdateBound(window);
}

void Player::Render(RenderTarget &window)
{
	window.draw(sprite);
}

Player :: ~Player()
{
}