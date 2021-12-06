#pragma once
#ifndef _Support_h_
#define _Support_h_

#define NOMINMAX

//#include "Graphics.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;

inline sf::IntRect FToIRect(const sf::FloatRect& f) {
	return sf::IntRect((int)f.left, (int)f.top, (int)f.width, (int)f.height);
}


#endif // !_Support_h_