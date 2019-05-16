#define _USE_MATH_DEFINES

#include <math.h>
#include "Matrix.h"
#include "MatrixOperation.h"
#include "MatrixException.h"
#include <iostream>
#include <random>
#include <ctime>

int main()
{
	srand((unsigned int)time(NULL));

	MatrixOperation* matr = new MatrixOperation();
	MatrixOperation* matrForChange = new MatrixOperation(3, 2, false);
	MatrixOperation* matrNotForChange = new MatrixOperation(4, 2, true);


	cout << "Matrix generation unit:" << endl;
	cout << *matr;
	cout << *matrForChange;
	cout << "________________________________________________________" << endl;


	cout << "Matrix enter unit:" << endl;
	cin >> *matrForChange;
	cout << *matrForChange;
	cout << "________________________________________________________" << endl;


	cout << "Matrix operation unit:" << endl;
	*matrForChange = *matr;
	cout << "operator '=' :" << *matrForChange;

	MatrixOperation a = *matrForChange + *matrForChange;
	cout << "operator '+' :" << a;
	MatrixOperation d = *matrForChange - *matrForChange;
	cout << "operator '-' :" << d;
	MatrixOperation* matrForMult = new MatrixOperation(2, 3, true);
	cout << *matrForMult;
	cout << *matrNotForChange;
	MatrixOperation f = *matrNotForChange * *matrForMult;
	cout << "operator '*' :" << f;
	cout << "________________________________________________________" << endl;


	cout << "Matrix transparate unit:" << endl;
	MatrixOperation* matrForTransparate = new MatrixOperation(6, 3, false);
	cout << *matrForTransparate;
	MatrixOperation c = matrForTransparate->transposition();
	cout << c;
	cout << "________________________________________________________" << endl;


	cout << "Matrix exeption unit:" << endl;
	MatrixOperation b;
	try {
		b = *matrForChange + *matrNotForChange;
	}
	catch (MatrixException & ex) {
		ex.showMessage();
	}

	try {
		b = *matrForChange - *matrNotForChange;
	}
	catch (MatrixException & ex) {
		ex.showMessage();
	}

	try {
		*matrNotForChange = *matrForMult;
	}
	catch (MatrixException & ex) {
		ex.showMessage();
	}

	try {
		cin >> *matrNotForChange;
	}
	catch (MatrixException & ex) {
		ex.showMessage();
	}

	try {
		*matr** matrNotForChange;
	}
	catch (MatrixException & ex) {
		ex.showMessage();
	}

	return 0;
}


