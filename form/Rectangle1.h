#pragma once
#include "Figure.h"

public ref class Rectangle1 : public Figure
{
public:
	Rectangle1(int x, int y, int w, int h);
	virtual void Show(Graphics^ g) override;
	virtual void Move(Graphics^ g, int dx, int dy) override;
	virtual int get_left_x() override;
	virtual int get_right_x() override;
private:
	Rectangle rect;
};

