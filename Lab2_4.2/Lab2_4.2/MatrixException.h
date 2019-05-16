#pragma once

#include <exception>
#include <iostream>

using namespace std;

class MatrixException : public std::exception
{
public:
	MatrixException(char*, char* str);
	~MatrixException();

	char* message;
	char* unit;
	void showMessage();
};

