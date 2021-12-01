#include "../include/Player.h"

void Player::InitVariable()
{
	moveSpeed = 2.f;
	animationState = PLAYER_ANIMATION_STATE::IDLE;
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
	currentFrame = IntRect(0, 144, 32, 48);
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
	if (animationState == PLAYER_ANIMATION_STATE::IDLE || animationState == PLAYER_ANIMATION_STATE::MOVING_UP)
	{
		if (timeAnimation.getElapsedTime().asSeconds() >= 0.1f)
		{
			currentFrame.top = 144.f;
			currentFrame.left += 32.f;
			if (currentFrame.left >= 128.f)
			{
				currentFrame.left = 0.f;
			}

			timeAnimation.restart();
			sprite.setTextureRect(currentFrame);
		}
	}
	else if (animationState == PLAYER_ANIMATION_STATE::MOVING_LEFT)
	{
		if (timeAnimation.getElapsedTime().asSeconds() >= 0.1f)
		{
			currentFrame.top = 48.f;
			currentFrame.left += 32.f;
			if (currentFrame.left >= 128.f)
			{
				currentFrame.left = 0.f;
			}

			timeAnimation.restart();
			sprite.setTextureRect(currentFrame);
		}
	}
	else if (animationState == PLAYER_ANIMATION_STATE::MOVING_RIGHT)
	{
		if (timeAnimation.getElapsedTime().asSeconds() >= 0.1f)
		{
			currentFrame.top = 96.f;
			currentFrame.left += 32.f;
			if (currentFrame.left >= 128.f)
			{
				currentFrame.left = 0.f;
			}

			timeAnimation.restart();
			sprite.setTextureRect(currentFrame);
		}
	}
	else if (animationState == PLAYER_ANIMATION_STATE::MOVING_DOWN)
	{
		if (timeAnimation.getElapsedTime().asSeconds() >= 0.1f)
		{
			currentFrame.top = 0.f;
			currentFrame.left += 32.f;
			if (currentFrame.left >= 128.f)
			{
				currentFrame.left = 0.f;
			}

			timeAnimation.restart();
			sprite.setTextureRect(currentFrame);
		}
	}
	
}
void Player::UpdateMovement()
{
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
	{	
		sprite.move(-moveSpeed, 0.f);
		animationState = PLAYER_ANIMATION_STATE::MOVING_LEFT;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
	{
		sprite.move(moveSpeed, 0.f);
		animationState = PLAYER_ANIMATION_STATE::MOVING_RIGHT;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
	{	
		sprite.move(0.f, moveSpeed);
		animationState = PLAYER_ANIMATION_STATE::MOVING_DOWN;
	}
	else if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
	{
		sprite.move(0.f, -moveSpeed);
		animationState = PLAYER_ANIMATION_STATE::MOVING_UP;
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