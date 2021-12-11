#include "include/Traffic.h"


Traffic::Traffic()
{
	traffic.setSize(Vector2f(30.f, 30.f);
	traffic.setFillColor(Color::Cyan);
	traffic.setOutLineColor(Color::Red);
}
void Traffic::Change()
{

}
void Traffic::Render(RenderTarget& window)
{
	window.Draw(traffic);
}
Traffic ::~Traffic()
{

}