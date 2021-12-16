#include "../include/Barrier.h"

void Barrier::InitVariable(bool isRight, float speed , int line ) {
	if (isRight) moveSpeed = speed;
	else moveSpeed = -speed;
	this->line = line;
	this->isRight = isRight;
}

void Barrier::UpdateMovement(bool canMove) {
	if (canMove)
	{
		sprite.move(moveSpeed, 0.f);
		idle = false;
	}
	else
	{
		sprite.move(0.f, 0.f);
		idle = true;
	}
}
void Barrier::Render(RenderTarget &window, bool dark) {
	if (dark)
		sprite.setColor(Color(80, 80, 80));
	else
		sprite.setColor(Color(255, 255, 255));
	window.draw(sprite);
}