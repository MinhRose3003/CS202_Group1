#ifndef _BARRIER_LIB_
#define _BARRIER_LIB_

class Barrier
{
private:
	int x, y;
	bool isRight;
	int color;
public:
	Barrier(int x, int y, bool isRight, int color);
	void Move(int x, int y);
	virtual void DrawObject() = 0;

	~Barrier();
};

#endif