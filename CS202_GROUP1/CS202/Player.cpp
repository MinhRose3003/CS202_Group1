#include "Header.h"


Player::Player(float x, float y)
{

	moveSpeed = 10.f;
	shape.setPosition(x,y);

	shape.setSize(Vector2f(50.f, 50.f));
	shape.setFillColor(Color::Red);
	

}


void Player::UpdateInputKeyBoard()
{
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
	{
		shape.move(-moveSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
	{
		shape.move(moveSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
	{
		shape.move(0, moveSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
	{
		shape.move(0, -moveSpeed);
	}
}

void Player::UpdateBound(RenderTarget * window)
{
	FloatRect playerBound = shape.getGlobalBounds();
	if (playerBound.left <= 0.f)
	{
		shape.setPosition(0.f, playerBound.top);
	}
	 if (playerBound.left + playerBound.width >= window->getSize().x)
	{
		 shape.setPosition(window->getSize().x - playerBound.width, playerBound.top);
	}
	 if (playerBound.top <= 0.f)
	{
		 shape.setPosition(playerBound.left, 0.f);
	}
	 if (playerBound.top + playerBound.height >= window->getSize().y)
	 {
		 shape.setPosition(playerBound.left, window->getSize().y - playerBound.height);
	}
}

void Player :: Update(RenderTarget * window)
{
	UpdateInputKeyBoard();

	UpdateBound(window);
}

void Player::Render(RenderTarget * window)
{
	window->draw(shape);
}

Player :: ~Player() {}