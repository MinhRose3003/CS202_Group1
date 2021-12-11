#include "../include/Game.h"

void Game::InitBarriers()
{
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i) {
			delete barriers[j][i];
		}
		barriers[j].clear();
	}

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	barrierSpeed = 1.f;
	lCount = 700;
	rCount = 1000;

	count.assign(8, 0);
	for (int i = 0; i < 8; ++i) {
		countMax[i] = uniform_int_distribution<int>(1, 500)(rng);
	}
}
void Game::UpgradeBarriers()
{
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i) {
			delete barriers[j][i];
		}
		barriers[j].clear();
	}

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	barrierSpeed += 0.2;
	lCount = max(50, lCount - 50);
	rCount = max(100, rCount - 50);

	count.assign(8, 0);
	for (int i = 0; i < 8; ++i) {
		countMax[i] = uniform_int_distribution<int>(1, 500)(rng);
	}
}
void Game::SaveBarriers(ostream& fout)
{
	for (int j = 0; j < 8; ++j) {
		int n = barriers[j].size();
		fout.write((char*)&n, sizeof(int));
		for (int i = 0; i < n; ++i) {
			int type = TypeOfBarrier(barriers[j][i]);
			Vector2f p = barriers[j][i]->GetPosition();
			bool isRight = barriers[j][i]->GetIsRight();
			float speed = abs(barriers[j][i]->GetSpeed());

			fout.write((char*)&type, sizeof(int));
			fout.write((char*)&p.x, sizeof(float));
			fout.write((char*)&p.y, sizeof(float));
			fout.write((char*)&isRight, sizeof(bool));
			fout.write((char*)&speed, sizeof(float));
		}
	}

	fout.write((char*)&barrierSpeed, sizeof(float));
	fout.write((char*)&lCount, sizeof(int));
	fout.write((char*)&rCount, sizeof(int));

	for (int i = 0; i < 8; ++i) {
		fout.write((char*)&count[i], sizeof(int));
	}
	for (int i = 0; i < 8; ++i) {
		fout.write((char*)&countMax[i], sizeof(int));
	}
}
void Game::LoadBarriers(istream& fin)
{
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i) {
			delete barriers[j][i];
		}
		barriers[j].clear();
	}

	for (int j = 0; j < 8; ++j) {
		int n;
		fin.read((char*)&n, sizeof(int));
		for (int i = 0; i < n; ++i) {
			int type;
			float x, y;
			bool isRight;
			float speed;

			fin.read((char*)&type, sizeof(int));
			fin.read((char*)&x, sizeof(float));
			fin.read((char*)&y, sizeof(float));
			fin.read((char*)&isRight, sizeof(bool));
			fin.read((char*)&speed, sizeof(float));

			barriers[j].push_back(GetBarrier(type, x, y, isRight, speed));
		}
	}

	fin.read((char*)&barrierSpeed, sizeof(float));
	fin.read((char*)&lCount, sizeof(int));
	fin.read((char*)&rCount, sizeof(int));

	for (int i = 0; i < 8; ++i) {
		fin.read((char*)&count[i], sizeof(int));
	}
	for (int i = 0; i < 8; ++i) {
		fin.read((char*)&countMax[i], sizeof(int));
	}
}
void Game::UpdateBarriers()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	for (int j = 0; j < 8; ++j) {
		if (barriers[j].size() && !visible(barriers[j][0]))
		{
			// cout << "Remove car\n";
			barriers[j].erase(barriers[j].begin());
		}
		if (count[j] >= countMax[j])
		{
			if (j & 1)
				barriers[j].push_back(GetBarrier((float)width, (float)line[j], 0, barrierSpeed));
			else
				barriers[j].push_back(GetBarrier(-64, (float)line[j], 1, barrierSpeed));
			count[j] = 0;
			countMax[j] = uniform_int_distribution<int>(lCount, rCount)(rng);
		}
		else
		{
			count[j] += 1;
		}
	}

	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); ++i)
		{
			barriers[j][i]->UpdateMovement();
			barriers[j][i]->UpdateAnimation();
		}
	}

}
void Game::RenderBarriers(bool dark)
{
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < barriers[j].size(); i++)
		{
			barriers[j][i]->Render(window, dark);
		}
	}
}
int Game::TypeOfBarrier(Barrier* barrier)
{
	if (dynamic_cast<Car*>(barrier))
		return 1;
	if (dynamic_cast<Truck*>(barrier))
		return 2;
	if (dynamic_cast<Bird*>(barrier))
		return 3;
	if (dynamic_cast<Dinausor*>(barrier))
		return 4;
	cout << "cannot identify\n";
	return 1; // default
}
Barrier* Game::GetBarrier(int type, float x, float y, bool isRight, float speed)
{
	if (type == 1)
	{
		return new Car(x, y, isRight, speed);
	}
	else if (type == 2)
	{
		return new Truck(x, y, isRight, speed);
	}
	else if (type == 3)
	{
		return new Bird(x, y, isRight, speed);
	}
	else if (type == 4)
	{
		return new Dinausor(x, y, isRight, speed);
	}
	return new Car(x, y, isRight, speed); // default
}
Barrier* Game::GetBarrier(float x, float y, bool isRight, float speed)
{
	int random = rand() % (4 - 1 + 1) + 1;
	return GetBarrier(random, x, y, isRight, speed);
}

bool Game::visible(Barrier* barrier)
{
	Sprite n_sprite = barrier->GetHitbox();
	FloatRect n_rect = n_sprite.getGlobalBounds();
	return n_rect.intersects(FloatRect(0, 0, (float)width, (float)height));
}