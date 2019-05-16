#include "Object.h"
#include <math.h>
#include <SFML\Graphics.hpp>
#include <iostream>
#include <random>
#include <ctime>


using namespace std;
using namespace sf;

Object::Object()
{
	radius = 30;
	circle.setOrigin(radius, radius);
	coord = Vector2f(180, 120);
	circle.setPosition(coord);
	circle.setFillColor(Color(255, 255, 255));
}

Object::Object(double x, double y, double rad)
{
	radius = rad;
	circle.setOrigin(radius, radius);
	coord = Vector2f(x, y);
	circle.setPosition(coord);
	circle.setFillColor(Color(255, 255, 255));
}

Object::~Object()
{
}

void Object::setNewSize(double rad) {
	this->radius = rad;
}

double Object::getSize() {
	return this->radius;
}

Vector2f Object::getCoord() {
	return this->coord;
}

void Object::figureToSmall() {
	this->circle.setPosition(this->coord.x + this->radius * 0.3, this->coord.y - this->radius * 1);
	this->circle.setRadius(this->radius * 0.7);
}

void Object::figureToNormal() {
	this->circle.setPosition(this->coord);
	this->circle.setRadius(this->radius);
}

void Object::figureToLarge() {
	this->circle.setPosition(this->coord.x - this->radius * 0.3, this->coord.y + this->radius * 1.5);
	this->circle.setRadius(this->radius * 1.3);
}

Vector2f Object::left_finish() {
	return this->coord - Vector2f(this->radius * 1.5, -this->radius);
}

Vector2f Object::right_finish() {
	return this->coord + Vector2f(this->radius * 1.5, this->radius);
}

void Object::line(RenderWindow* window, Vector2f start, Vector2f finish) {
	sf::Vertex line[] = {
	sf::Vertex(start),
	sf::Vertex(finish)
	};
	line[0].color = Color(255, 255, 255);
	line[1].color = Color(255, 255, 255);
	window->draw(line, 2, sf::Lines);

}

void Object::render(RenderWindow* window) {
	this->figureToNormal();
	window->draw(this->circle);
	this->figureToSmall();
	window->draw(this->circle);
	this->figureToNormal();
	this->figureToLarge();
	window->draw(this->circle);
	this->figureToNormal();

	line(window, this->coord - Vector2f(this->radius, 0), this->left_finish());
	line(window, this->coord + Vector2f(this->radius, 0), this->right_finish());
}

Object Object::operator+(const Object& obj) {
	Object object;
	object.radius = int(sqrt(this->radius * obj.radius));
	object.coord.x = int(sqrt(this->coord.x * obj.coord.x));
	object.coord.y = int(sqrt(this->coord.y * obj.coord.y));

	return object;
}

