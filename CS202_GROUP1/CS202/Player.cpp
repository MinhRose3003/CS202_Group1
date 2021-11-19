#include "Header.h"



Player::Player(int x, int y)
{
	this->x = x;
	this->y = y;
	isDead = true;
}
 void Player::Move(char key)
{
	 if (key == 72) // up
	 {

	 }
	 else if (key == 80) // down
	 {

	 }
	 else if (key == 75) // left 
	 {

	 }
	 else if (key == 77) // right 
	 {

	 }
}
 bool Player::IsImpact(Barrier*& a)
{

}
bool Player::IsDead()
{

}
void Player::DrawPlayer()
{

}

Player :: ~Player() {}