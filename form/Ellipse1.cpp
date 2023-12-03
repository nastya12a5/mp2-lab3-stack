#include "Ellipse1.h"

Ellipse1::Ellipse1(int x, int y, int w, int h)
{
	rect = Rectangle(x, y, w, h);
}

void Ellipse1::Show(Graphics^ g)
{
	g->FillEllipse(Brushes::Green, rect);
}

void Ellipse1::Move(Graphics^ g, int dx, int dy)
{
	rect.X += dx;
	rect.Y += dy;
	g->FillEllipse(Brushes::White, rect);
	Show(g);
}

int Ellipse1::get_left_x()
{
	return rect.Left;
}

int Ellipse1::get_right_x()
{
	return rect.Right;
}
