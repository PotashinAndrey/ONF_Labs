#include "C_Circle_Color.h"
#include "C_Circle.h"
#include <iostream>
#include <math.h>

using namespace std;

void C_Circle_Color::set_color(int r, int g, int b) {
	this->color.r = r;
	this->color.g = g;
	this->color.b = b;
};


C_Circle_Color::Color C_Circle_Color::get_color() {
	return this->color;
};

void C_Circle_Color::alert() {
	cout << "Радиус: " << this->get_radius() << endl;
	cout << "Х и Y координаты: " << this->get_coordinates().x_coord << ", " << this->get_coordinates().y_coord << endl;
	cout << "Цвет(RGB): " << this->color.r << this->color.g << this->color.b << endl;
};

C_Circle_Color::C_Circle_Color()
{
	set_color(0, 0, 0);
}

C_Circle_Color::C_Circle_Color(int x, int y, int rad, int r, int g, int b) : C_Circle(x, y ,rad)
{
	set_color(r, g, b);
}

C_Circle_Color::~C_Circle_Color()
{
}
