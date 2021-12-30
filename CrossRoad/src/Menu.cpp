#include "../include/Menu.h"

Menu::Menu(int width, int height, vector<string> context, vector<vector<string> > options)
{
	if (!font.loadFromFile("font/Kenta-qZ3O1.ttf"))
	{
		cout << "Cannot load font from font/Kenta-qZ3O1.ttf\n";
	}

	this->context = context;
	this->options = options;
	nItem = context.size();
	menu.resize(nItem);
	selectedOption.assign(nItem, 0);

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

void Menu::SaveOption()
{
	ofstream fout("settings/settings.bin", ios::out | ios::binary);
	if (!fout) {
		cout << "Cannot open settings.bin" << endl;
	}
	for (int i = 0; i < selectedOption.size(); ++i) 
		fout.write((char*)&selectedOption[i], sizeof(int));
	fout.close();
}
void Menu::LoadOption()
{
	ifstream fin("settings/settings.bin", ios::out | ios::binary);
	if (!fin) {
		cout << "Cannot open settings.bin" << endl;
	}
	for (int i = 0; i < selectedOption.size(); ++i)
		fin.read((char*)&selectedOption[i], sizeof(int));
	fin.close();

	for (int i = 0; i < selectedOption.size(); ++i) {
		int j = selectedOption[i];
		if (j < options[i].size()) {
			menu[i].setString(context[i] + "    " + options[i][j]);
			menu[i].setOrigin(menu[i].getLocalBounds().width / 2, menu[i].getLocalBounds().height / 2);
		}
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
void Menu::MoveLeft()
{
	if (selectedOption[selectedItemIndex] - 1 >= 0) {
		int i = selectedItemIndex;
		int j = --selectedOption[i];
		menu[i].setString(context[i] + "    " + options[i][j]);
		menu[i].setOrigin(menu[i].getLocalBounds().width / 2, menu[i].getLocalBounds().height / 2);
	}
}
void Menu::MoveRight()
{
	if (selectedOption[selectedItemIndex] + 1 < options[selectedItemIndex].size()) {
		int i = selectedItemIndex;
		int j = ++selectedOption[i];
		menu[i].setString(context[i] + "    " + options[i][j]);
		menu[i].setOrigin(menu[i].getLocalBounds().width / 2, menu[i].getLocalBounds().height / 2);
	}
}