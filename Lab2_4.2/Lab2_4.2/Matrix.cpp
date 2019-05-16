#include "Matrix.h"
#include <iostream>
#include <math.h>
#include <random>
#include <ctime>	

using namespace std;

int Matrix::random(int a, int b) {
	int minimum = min(a, b);
	int maximum = max(a, b);
	return rand() % (maximum - minimum) + minimum;
};

void Matrix::setOrder(int m, int n) {
	this->lines = m;
	this->colums = n;
}

void Matrix::fillMatrix() {
	for (int i = 0; i < this->lines; i++)
	{
		for (int j = 0; j < this->colums; j++)
		{
			this->matrix[i][j] = random(-9, 9);
		}
	}
}

bool Matrix::getChangeStatus() {
	return this->staticMatrix;
}

Matrix::Matrix()
{
	//cout << " costruct " << this << endl;

	this->staticMatrix = true;
	this->setOrder(3, 3);
	matrix = new int* [this->lines];
	for (int i = 0; i < this->lines; i++)
	{
		matrix[i] = new int[this->colums];
	}
	this->fillMatrix();
}

Matrix::Matrix(int n)
{
	//cout << " costruct n" << this << endl;

	this->staticMatrix = true;
	this->setOrder(n, n);
	matrix = new int* [this->lines];
	for (int i = 0; i < this->lines; i++)
	{
		matrix[i] = new int[this->colums];
	}
	this->fillMatrix();
}

Matrix::Matrix(int n, bool change)
{
	//cout << " costruct n change" << this << endl;

	this->staticMatrix = change;
	this->setOrder(n, n);
	matrix = new int*[this->lines];
	for (int i = 0; i < this->lines; i++)
	{
		matrix[i] = new int[this->colums];
	}
	this->fillMatrix();
}

Matrix::Matrix(int m, int n)
{
	//cout << " costruct n m" << this << endl;

	this->staticMatrix = true;
	this->setOrder(m, n);
	matrix = new int* [this->lines];
	for (int i = 0; i < this->lines; i++)
	{
		matrix[i] = new int[this->colums];
	}
	this->fillMatrix();
}

Matrix::Matrix(int m, int n, bool change)
{
	//cout << " costruct n m change" << this << endl;

	this->staticMatrix = change;
	this->setOrder(m, n);
	matrix = new int* [this->lines];
	for (int i = 0; i < this->lines; i++)
	{
		matrix[i] = new int[this->colums];
	}
	this->fillMatrix();
}

Matrix::~Matrix()
{
	//cout << " destruct called!" << this << endl;

	for (int i = 0; i < this->lines; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}
