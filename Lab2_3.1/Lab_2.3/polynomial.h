#pragma once
#include <iostream>

using namespace std;

class polynomial
{
public:
	polynomial();
	polynomial(int);
	polynomial(const polynomial&);
	~polynomial();

	void set_coefficients(double*);
	int get_degree();
	void get_coefficients();

	void random_coef(int);

	polynomial& operator=(const polynomial&);
	polynomial& operator+(double);
	polynomial& operator*(polynomial&);

	friend ostream& operator<<(ostream&, polynomial&);
	friend istream& operator>>(istream&, polynomial&);

private:
	int degree;
	double* x;
	void set_degree(int);
};

