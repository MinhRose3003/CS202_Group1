#include "../include/Player.h"

void Player::InitVariable(float speed, int point, int state)
{
	moveSpeed = speed;
	this->point = point;
	animationState = PLAYER_ANIMATION_STATE(state);

	width = 32;
	height = 48;
	scale = 1.0;
}
void Player::InitImage()
{
	if (!image.loadFromFile("Sprite/Player.png"))
	{
		cout << "Cannot open Sprite/Player.png\n";
	}
}
void Player::InitTexture()
{
	if (!texture.loadFromFile("Sprite/Player.png"))
	{
		cout << "Cannot open Sprite/Player.png\n";
	}
}
void Player::InitSprite(float x, float y)
{
	sprite.setTexture(texture);
	currentFrame = IntRect(0, 144, width, height);
	sprite.setTextureRect(currentFrame);
	sprite.setScale(scale, scale);

	sprite.setPosition(x, y);
}

void Player::Init(float x, float y, float speed, int point, int state)
{
	InitVariable(speed, point, state);
	InitSprite(x, y);
	InitAnimation();
}

void Player::InitAnimation()
{

}
Player::Player(float x, float y, float speed)
{
	InitVariable(speed, 0);
	InitImage();
	InitTexture();
	InitSprite(x, y);
	InitAnimation();
}

void Player::UpdateAnimation()
{
	if (animationState == PLAYER_ANIMATION_STATE::MOVING_UP)
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
	else {
		if (timeAnimation.getElapsedTime().asSeconds() >= 0.1f)
		{
			currentFrame.left = 0.f;

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
	else {
		animationState = PLAYER_ANIMATION_STATE::IDLE;
	}
}

void Player::UpdateBound(RenderTarget & window)
{
	FloatRect n_rect = sprite.getGlobalBounds();

	float x = max(0.f, min(window.getSize().x - n_rect.width, n_rect.left));
	float y = max(0.f, min(window.getSize().y - n_rect.height, n_rect.top));

	sprite.setPosition(x, y);
}

void Player :: Update(RenderTarget & window)
{
	UpdateMovement();
	UpdateAnimation();

	UpdateBound(window);
}

void Player::Render(RenderTarget &window, bool dark)
{
	if (dark)
		sprite.setColor(Color(80, 80, 80));
	else
		sprite.setColor(Color(255, 255, 255));
	window.draw(sprite);
}

Sprite Player::GetHitbox()
{
	Sprite n_sprite = sprite;
	IntRect n_frame = currentFrame;
	int hitbox = 20;

	n_frame.top = n_frame.top + n_frame.height - hitbox;
	n_frame.height = hitbox;

	Vector2f p = n_sprite.getPosition();
	p.y = p.y + (height - hitbox) * scale;
	
	n_sprite.setTextureRect(n_frame);
	n_sprite.setPosition(p);

	return n_sprite;
}
Sprite Player::GetHitboxFull()
{
	return sprite;
}
Image Player::GetImage()
{
	return image;
}

void Player::AddPoint()
{
	point += 10;
}

int Player ::GetPoint()
{
	return point;
}
Player :: ~Player()
{
}