#pragma once
#ifndef traffic_h_
#define traffic_h_

#include "include/Support.h"

class Traffic
{
private:
	RectangleShape traffic;
public:
	Traffic();
	void Change();
	void Render(RenderTarget& window);
	~Traffic();
};

#endif // !traffic_h_
