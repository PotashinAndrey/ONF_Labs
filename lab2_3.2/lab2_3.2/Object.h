#pragma once

#include <math.h>
#include <SFML\Graphics.hpp>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;
using namespace sf;

class Object
{
public:
	struct coord
	{
		double x;
		double y;
	};

	Object();
	Object(double, double, double);
	~Object();

	void setNewSize(double);
	double getSize();
	Vector2f getCoord();

	void render(RenderWindow*);
	void figureToSmall();
	void figureToNormal();
	void figureToLarge();
	Vector2f left_finish();
	Vector2f right_finish();

	void line(RenderWindow*, Vector2f, Vector2f);

	Object operator+(const Object&);

private:
	double radius;
	Vector2f coord;
	CircleShape circle;
};

