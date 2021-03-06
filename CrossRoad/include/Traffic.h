#pragma once
#ifndef traffic_h_
#define traffic_h_

#include "../include/Support.h"

class Traffic
{
private:
	Texture greenTexture;
	Texture redTexture;

	Sprite sprite;
	float x, y;

	Clock clock;
	float timeCanMove;

	bool canMove;
	bool start;

	IntRect currentFrame;

public:
	Traffic(float x , float  y );
	void InitTraffic(float x , float y);
	void RenderTraffic(RenderTarget& window, bool dark);
	bool CanMove();
	void UpdateTraffic();
	~Traffic();
};

#endif // !traffic_h_
