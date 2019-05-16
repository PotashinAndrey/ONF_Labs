#include "MatrixOperation.h"
#include "MatrixException.h"
#include <iostream>
#include <math.h>
#include <random>
#include <ctime>	

using namespace std;

MatrixOperation::MatrixOperation() {}
MatrixOperation::MatrixOperation(int n) : Matrix(n) {}
MatrixOperation::MatrixOperation(int n, bool change) : Matrix(n, change) {}
MatrixOperation::MatrixOperation(int n, int m) : Matrix(n, m) {}
MatrixOperation::MatrixOperation(int n, int m, bool change) : Matrix(n, m, change) {}
MatrixOperation::MatrixOperation(const MatrixOperation& mat) {
	this->staticMatrix = mat.staticMatrix;
	this->setOrder(mat.lines, mat.colums);

	matrix = new int* [lines];
	for (int i = 0; i < lines; i++) {
		matrix[i] = new int[colums];
	}
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < colums; j++)
			matrix[i][j] = mat.matrix[i][j];
	}
}
MatrixOperation::~MatrixOperation() {}



ostream& operator<<(ostream& stream, MatrixOperation& matrix) {
	cout << "Matrix out: " << endl;

	cout.setf(ios::showpos);

	for (int i = 0; i < matrix.lines; i++)
	{
		for (int j = 0; j < matrix.colums; j++)
		{
			stream << " " << matrix.matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout.unsetf(ios::showpos);

	cout << endl;

	return stream;
}

istream& operator>>(istream& stream, MatrixOperation &matrix) {
	cout << "Matrix enter: " << endl;

	if (matrix.getChangeStatus()) { 
		throw MatrixException((char*)"This matrix can't be changed! ", (char*)"operator >>, string 57.");
	}

	for (int i = 0; i < matrix.lines; i++)
	{
		delete[]matrix.matrix[i];
	}
	delete[]matrix.matrix;

	int m, n;

	cout << "Enter number of lines: " << endl;
	cin >> m;
	cout << "Enter number of colums: " << endl;
	cin >> n;
	matrix.setOrder(m, n);

	matrix.matrix = new int* [matrix.lines];
	for (int i = 0; i < matrix.lines; i++)
	{
		matrix.matrix[i] = new int[matrix.colums];
	}
	matrix.fillMatrix();

	for (int i = 0; i < matrix.lines; i++)
	{
		for (int j = 0; j < matrix.colums; j++)
		{
			stream >> matrix.matrix[i][j];
		}
		cout << endl;
	}
	
	cout << endl;
	
	return stream;
}

 MatrixOperation MatrixOperation::operator+(const MatrixOperation& matr) {
	if (this->colums != matr.colums || this->lines != matr.lines)
	{
		throw MatrixException((char*)"invalid matrix dimension", (char*)"operator +, string 97.");
	}
	MatrixOperation* result = new MatrixOperation(matr.lines, matr.colums, matr.staticMatrix);

	for (int i = 0; i < result->lines; i++)
	{
		for (int j = 0; j < result->colums; j++)
		{
			result->matrix[i][j] = matr.matrix[i][j] + this->matrix[i][j];
		}
		cout << endl;
	}

	return *result;
}

MatrixOperation MatrixOperation::operator-(const MatrixOperation& matr) {
	if (this->colums != matr.colums || this->lines != matr.lines)
	{
		throw MatrixException((char*)"invalid matrix dimension", (char*)"operator -, string 116.");
	}

	MatrixOperation* result = new MatrixOperation(matr.lines, matr.colums, matr.staticMatrix);

	for (int i = 0; i < result->lines; i++)
	{
		for (int j = 0; j < result->colums; j++)
		{
			result->matrix[i][j] = matr.matrix[i][j] - this->matrix[i][j];
		}
		cout << endl;
	}

	return *result;
}
MatrixOperation& MatrixOperation::operator=(const MatrixOperation& matr) {
	if (this->getChangeStatus()) {
		throw MatrixException((char*)"This matrix can't be changed! ", (char*)"operator =, string 134.");
	}

	for (int i = 0; i < this->lines; i++)
	{
		delete[]this->matrix[i];
	}
	delete[]this->matrix;

	this->staticMatrix = matr.staticMatrix;
	this->setOrder(matr.lines, matr.colums);

	this->matrix = new int* [this->lines];
	for (int i = 0; i < this->lines; i++)
	{
		this->matrix[i] = new int[this->colums];
	}

	for (int i = 0; i < this->lines; i++)
	{
		for (int j = 0; j < this->colums; j++)
		{
			this->matrix[i][j] = matr.matrix[i][j];
		}
	}

	return *this;
}

MatrixOperation MatrixOperation::operator*(const MatrixOperation& matrix) {
	cout << " Operator '*' called" << endl;

	if (this->colums != matrix.lines)
	{
		throw MatrixException((char*)"Òot suitable dimensions of matrices, multiplication is impossible! ", (char*)"operator *, string 164.");

	}

	MatrixOperation* result = new MatrixOperation(this->lines, matrix.colums, false);

	for (int i = 0; i < result->lines; i++)
	{
		for (int j = 0; j < result->colums; j++)
		{	
			result->matrix[i][j] = 0;
			for (int k = 0; k < this->colums; k++) {
				result->matrix[i][j] += this->matrix[i][k] * matrix.matrix[k][j];
			}
		}
	}

	return *result;
} 


MatrixOperation MatrixOperation::transposition() {
	MatrixOperation* result = new MatrixOperation(this->colums, this->lines, false);
	for (int i = 0; i < result->lines; i++)
	{
		for (int j = 0; j < result->colums; j++)
		{
			result->matrix[i][j] = this->matrix[j][i];
		}
	}

	return *result;
}
