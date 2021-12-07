#include "../include/Barrier.h"

void Barrier::InitVariable(bool isRight, float speed) {
	if (isRight) moveSpeed = speed;
	else moveSpeed = -speed;
}

void Barrier::UpdateMovement() {
	sprite.move(moveSpeed, 0.f);
}
void Barrier::Render(RenderTarget &window, bool dark) {
	if (dark)
		sprite.setColor(Color(80, 80, 80));
	else
		sprite.setColor(Color(255, 255, 255));
	window.draw(sprite);
}