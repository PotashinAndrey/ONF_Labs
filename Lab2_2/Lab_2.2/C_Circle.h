#pragma once

class C_Circle
{
public:
	struct Coordinates {
		float x_coord;
		float y_coord;
	};
	void set_coordinates(float, float);
	void set_radius(float);
	float get_radius();
	Coordinates get_coordinates();

	double circle_length();
	void alert();

	C_Circle();
	C_Circle(float, float, float);
	virtual ~C_Circle();

protected:
	float radius;
	Coordinates circle;
};
