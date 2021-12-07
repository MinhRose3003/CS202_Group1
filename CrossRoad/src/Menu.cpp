#include "../include/Menu.h"

Menu::Menu(int width, int height, vector<string> context)
{
	if (!font.loadFromFile("font/Kenta-qZ3O1.ttf"))
	{
		cout << "Cannot load font from font/Kenta-qZ3O1.ttf\n";
	}

	this->context = context;
	nItem = context.size();
	menu.resize(nItem);

	menu[0].setCharacterSize(50);

	for (int i = 0; i < nItem; ++i) {
		menu[i].setFont(font);
		menu[i].setFillColor(Color::White);
		menu[i].setString(context[i]);
		menu[i].setOrigin(menu[i].getLocalBounds().width / 2, menu[i].getLocalBounds().height / 2);
		menu[i].setPosition(width / 2, height / (nItem + 1) * (i + 1));
	}

	selectedItemIndex = 1;
	menu[1].setFillColor(Color::Yellow);
}

Menu::~Menu()
{

}

void Menu::Draw(RenderWindow & window)
{
	for (int i = 0; i < nItem; ++i) {
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 > 0) {
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex -= 1;
		menu[selectedItemIndex].setFillColor(Color::Yellow);
	}
}
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < nItem) {
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex += 1;
		menu[selectedItemIndex].setFillColor(Color::Yellow);
	}
}