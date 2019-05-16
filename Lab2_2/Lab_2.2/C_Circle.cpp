#define _USE_MATH_DEFINES

#include "C_Circle.h"
#include <iostream>
#include <math.h>

using namespace std;

void C_Circle::set_coordinates(float x, float y) {
	this->circle.x_coord = x;
	this->circle.y_coord = y;
};

void C_Circle::set_radius(float r) {
	this->radius = r;
};

float C_Circle::get_radius() {
	return this->radius;
};

C_Circle::Coordinates C_Circle::get_coordinates() {
	return this->circle;
};

double C_Circle::circle_length() {
	return M_PI * this->radius * 2;
};

void C_Circle::alert() {
	cout << "Радиус: " << this->get_radius() << endl;
	cout << "Х и Y координаты: " << this->get_coordinates().x_coord << ", " << this->get_coordinates().y_coord << endl;
	cout << "Длинна окружности: " << this->circle_length() << endl;
}

C_Circle::C_Circle()
{
	set_coordinates(4, 4);
	set_radius(2);
}

C_Circle::C_Circle(float x, float y, float r)
{
	set_coordinates(x, y);
	set_radius(r);
}

C_Circle::~C_Circle()
{
}
