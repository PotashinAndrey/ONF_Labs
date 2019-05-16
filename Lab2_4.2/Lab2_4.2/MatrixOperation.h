#pragma once

#include "MatrixException.h"
#include "Matrix.h"
#include <iostream>
#include <math.h>
#include <random>
#include <ctime>	

class MatrixOperation :
	protected Matrix
{
public:
	MatrixOperation operator+(const MatrixOperation&);
	MatrixOperation operator-(const MatrixOperation&);
	MatrixOperation operator*(const MatrixOperation&);

	MatrixOperation& operator=(const MatrixOperation&);

	MatrixOperation transposition();

	friend ostream& operator<<(ostream&, MatrixOperation&);
	friend istream& operator>>(istream&, MatrixOperation&);

	MatrixOperation();
	MatrixOperation(int);
	MatrixOperation(int, bool);
	MatrixOperation(int, int);
	MatrixOperation(int, int, bool);
	MatrixOperation(const MatrixOperation&);

	~MatrixOperation();
};

