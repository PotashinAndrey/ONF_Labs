#pragma once
#include "C_Circle.h"

class C_Circle_Color :
	protected C_Circle
{
public:
	struct Color
	{
		int r;
		int g;
		int b;
	};

	void set_color(int, int, int);
	Color get_color();
	void alert();

	C_Circle_Color();
	C_Circle_Color(int, int, int, int, int, int);
	~C_Circle_Color();

private:
	Color color;
};

