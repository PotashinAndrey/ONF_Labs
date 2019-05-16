#include "MatrixException.h"
#include <exception>
#include <iostream>

using namespace std;

void MatrixException::showMessage() {
	cout << "ATENTION, exception catched: " << endl;
	cout << this->message << " from operation : " << this->unit << endl;
}

MatrixException::MatrixException(char* str, char* place)
{
	message = str;
	unit = place;
}


MatrixException::~MatrixException()
{
}
