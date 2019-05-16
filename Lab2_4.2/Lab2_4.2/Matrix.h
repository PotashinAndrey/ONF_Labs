#pragma once

#include <iostream>
#include <math.h>
#include <random>
#include <ctime>	

using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(int);
	Matrix(int, bool);
	Matrix(int, int);
	Matrix(int, int, bool);

	~Matrix();

	void setOrder(int, int);
	int random(int, int);
	void fillMatrix();
	bool getChangeStatus();

protected: 
	bool staticMatrix;
	int lines, colums;
	int** matrix;
};

