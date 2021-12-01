#ifndef _BARRIER_LIB_
#define _BARRIER_LIB_

class Barrier
{
private:
	int x, y;
	bool isRight;
	float speed;
public:
	Barrier(int x, int y, bool isRight, float speed);
	void Move(int x, int y);
	virtual void DrawObject() = 0;

	virtual ~Barrier() {};
};

#endif