#include "Header.h"


Player::Player()
{
	x = 0;
	y = 0;
	isDead = false;
}

Player::Player(int x, int y)
{
	this->x = x;
	this->y = y;
	isDead = true;
}

Player& Player ::operator = (Player& a)
{
	if(this != &a)
	{ 
		x = a.x;
		y = a.y;
		isDead = a.isDead;
	}
	return *this;
}
 void Player::Move(char key)
{
	 if (key == 'w') // up
	 {
		
		 ClearPlayer();
		 y = y - 1;
		 DrawPlayer();
	 }
	 else if (key == 's') // down
	 {
		 ClearPlayer();
		 y = y + 1;
		 DrawPlayer();
	 }
	 else if (key == 'a') // left 
	 {
		 ClearPlayer();
		 x = x - 1;
		 DrawPlayer();
	 }
	 else if (key == 'd') // right 
	 {
		 ClearPlayer();
		 x = x + 1;
		 DrawPlayer();
	 }
}
 bool Player::IsImpact(Barrier*& a)
{
	 return true;
}
bool Player::IsDead()
{
	return isDead;
}
void Player::DrawPlayer()
{
	gotoXY(x, y);
	cout << char(208);
	gotoXY(x, y-1);
	cout << char(206);
	gotoXY(x, y - 2);
	cout << char(232);
	gotoXY(x - 1, y - 1);
	cout << char(205);
	gotoXY(x + 1, y - 1);
	cout << char(205);
}

void Player::ClearPlayer()
{
	gotoXY(x, y);
	cout << " ";
	gotoXY(x, y - 1);
	cout << " ";
	gotoXY(x, y - 2);
	cout << " ";
	gotoXY(x - 1, y - 1);
	cout << " ";
	gotoXY(x + 1, y - 1);
	cout << " ";
}

Player :: ~Player() {}