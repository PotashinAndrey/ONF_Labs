#define _USE_MATH_DEFINES

#include "polynomial.h"
#include <iostream>
#include <math.h>
#include <random>
#include <ctime>	


int polynomial::random(int a, int b) {
	int minimum = min(a, b);
	int maximum = max(a, b);
	return rand() % (maximum - minimum) + minimum;
};

void polynomial::set_degree(int degree) {
	this->degree = degree;
}

int polynomial::get_degree() {
	return this->degree;
}

void polynomial::get_coefficients() {
	for (int i = 0; i < this->degree + 1 ; i++)
	{
		cout << this->x[i] << " ";
	}
}

double* polynomial::create_coef(int degree) {
	double* coef = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
	{
		coef[i] = random(-4, 4);
	}
	if (coef[degree] == 0) { 
		coef[degree]++;
	}
	return coef;
}

void polynomial::set_coefficients(double *coef) {
	for (int i = 0; i < this->degree + 1; i++)
	{
		this->x[i] = coef[i];
	}
}
 
polynomial::polynomial(int degree)
{
	set_degree(degree);
	x = new double[degree + 1];
	set_coefficients(create_coef(degree));
}

polynomial::polynomial() {
	set_degree(0);
	x = new double[1];
	set_coefficients(create_coef(0));
}

polynomial::polynomial(const polynomial& copy) {
	this->degree = copy.degree;
	this->x = new double[this->degree + 1];
	for (int i = 0; i < this->degree + 1; i++)
	{
		this->x[i] = copy.x[i];
	} 
}


polynomial::~polynomial()
{
	delete[]x;
}

istream& operator>>(istream& stream, polynomial& obj)
{
	cout << "polynomial enter" << endl;
	cout << "degree=" << endl;
	stream >> obj.degree;

	delete[]obj.x;
	obj.x = new double[obj.degree + 1];
	for (int i = 0; i <= obj.degree;)
	{
		cout << "x^(" << i << ")*";
		stream >> obj.x[i++];

	}

	cout << endl;

	return stream;
}

ostream& operator<<(ostream& stream, polynomial& obj)
{
	cout << "polynomianl out" << endl;
	for (int i = 0; i <= obj.degree; i++) { 
		stream << "x^(" << i << ")*" << int(obj.x[i]) << endl; 
	}

	return stream;
}

polynomial& polynomial::operator=(const polynomial& Obj)
{
	degree = Obj.degree;
	delete[]x;
	x = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++) { 
		x[i] = Obj.x[i]; 
	}
	return *this;
}

polynomial&  polynomial::operator+(double plus) {
	cout << "polynomial plus" << endl;
	polynomial *temp = new polynomial();
	for (int i = 0; i < this->degree + 1; i++)
	{
		temp->x[i] = this->x[i];
	}
	temp->x[0] += plus;
	return *temp;
}

polynomial& polynomial::operator*(polynomial& obj) {
	cout << "polynomial *" << endl;

	int newDegree = obj.degree + this->degree;

	cout << newDegree << endl;

	double* newX = new double[newDegree + 1];
	for (int i = 0; i < newDegree + 1; i++) {
		newX[i] = 0;
	}

	polynomial* result = new polynomial();
	result->set_degree(newDegree);
	result->set_coefficients(newX);

	for (int i = 0; i < obj.degree + 1; i++)
		for (int j = 0; j < this->degree + 1; j++) {
			result->x[i + j] += obj.x[i] * x[j];
		}
	return *result;
}

