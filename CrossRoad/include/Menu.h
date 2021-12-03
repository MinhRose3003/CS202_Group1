#pragma once
#ifndef __MENU_GAME_LIB_
#define __MENU_GAME_LIB_

#include "Support.h"

class Menu
{
private:
	int selectedItemIndex;
	Font font;
	vector<Text> menu;

	int nItem;
	vector<string> context;
public:
	Menu() {}
	Menu(int width, int height);
	~Menu();

	void Draw(RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetItem() { return selectedItemIndex; }
};

#endif
