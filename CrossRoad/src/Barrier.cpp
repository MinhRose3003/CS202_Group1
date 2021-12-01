#include "../include/Barrier.h"

void Barrier::InitVariable(bool isRight) {
	if (isRight) moveSpeed = 1.f;
	else moveSpeed = -1.f;
}

void Barrier::UpdateMovement() {
	sprite.move(moveSpeed, 0.f);
}
void Barrier::Render(RenderTarget &window) {
	window.draw(sprite);
}