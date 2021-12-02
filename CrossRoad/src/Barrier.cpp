#include "../include/Barrier.h"

void Barrier::InitVariable(bool isRight, float speed) {
	if (isRight) moveSpeed = speed;
	else moveSpeed = -speed;
}

void Barrier::UpdateMovement() {
	sprite.move(moveSpeed, 0.f);
}
void Barrier::Render(RenderTarget &window) {
	window.draw(sprite);
}