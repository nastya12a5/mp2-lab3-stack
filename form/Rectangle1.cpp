#include "Rectangle1.h"


Rectangle1::Rectangle1(int x, int y, int w, int h)
{
	rect = Rectangle(x, y, w, h);
}

void Rectangle1::Show(Graphics^ g)
{
	g->FillRectangle(Brushes::Red, rect);
}

void Rectangle1::Move(Graphics^ g, int dx, int dy)
{
	rect.X += dx;
	rect.Y += dy;
	g->FillRectangle(Brushes::White, rect);
	Show(g);
}

int Rectangle1::get_left_x()
{
	return rect.Left;
}

int Rectangle1::get_right_x()
{
	return rect.Right;
}