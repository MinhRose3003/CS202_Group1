#pragma once
#ifndef __MENU_GAME_LIB_
#define __MENU_GAME_LIB_

#include "Support.h"

class Menu
{
private:
	Font font;
	vector<Text> menu;

	int selectedItemIndex;
	vector<int> selectedOption;

	int nItem;
	vector<string> context;
	vector<vector<string> > options;
public:
	Menu() {}
	Menu(int width, int height, vector<string> context, vector<vector<string> > options);
	~Menu();

	void Draw(RenderWindow &window);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	int GetItem() { return selectedItemIndex; }
	int GetOption(int i) { return selectedOption[i]; }

	void SaveOption();
	void LoadOption();
};

#endif
