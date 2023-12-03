#pragma once
using namespace System::Drawing;

#define _USE_MATH_DEFINES

#include <iostream>


using namespace System::Drawing;
#pragma once

using namespace std;
class Figure {
protected:
	int x, y;
public:
	Figure(int _x, int _y) {
		x = _x; y = _y;
	}
	virtual void Show(Graphics^ gr) = 0;
	virtual void Hide(Graphics^ gr) = 0;
	virtual void Move(Graphics^ gr, int dx, int dy) {
		Hide(gr);
		x += dx; y += dy;
		Show(gr);
	}
	virtual int get_right_x(Graphics^ gr) = 0;
	 virtual int get_left_x(Graphics^ gr) = 0;
	 virtual int get_up_y(Graphics^ gr) = 0;
	virtual int get_down_y(Graphics^ gr) = 0;

};
class Rectangle1 :public Figure {
protected:
	int w, h;
public:
	Rectangle1(int _w, int _h, int _x, int _y) : Figure(_x, _y) {
		w = _w;
		h = _h;
	}
	 int get_right_x(Graphics^ gr) { return x + w; }
	 int get_left_x(Graphics^ gr) { return x; }
	 int get_up_y(Graphics^ gr) { return y; }
	 int get_down_y(Graphics^ gr) { return y + h; }
	void Show(Graphics^ gr) {
		gr->DrawRectangle(Pens::Black, x, y, w, h);
	}
	void Hide(Graphics^ gr) {
		gr->DrawRectangle(Pens::White, x, y, w, h);
	}
	void set_w(int _w) {
		w = _w;
	}
	void set_b(int _h) {
		h = _h;
	}



};

class Ellipse1 :public Figure {
protected:
	int r1, r2;
public:
	Ellipse1(int _r1, int _r2, int _x, int _y) : Figure(_x, _y) {
		r1 = _r1;
		r2 = _r2;
	}

	 int get_right_x(Graphics^ gr) { return x + r2; }
	virtual int get_left_x(Graphics^ gr) { return x - r2; }
	virtual int get_up_y(Graphics^ gr) { return y + r1; }
	virtual int get_down_y(Graphics^ gr) { return y - r1; }

	void Show(Graphics^ gr) {
		gr->DrawEllipse(Pens::Black, x - r2, y - r1, 2 * r2, 2 * r1);
	}
	void Hide(Graphics^ gr) {
		gr->DrawEllipse(Pens::White, x - r2, y - r1, 2 * r2, 2 * r1);
	}
};
