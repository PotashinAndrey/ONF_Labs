#include <iostream>
#include <math.h>
#include <random>
#include <ctime>
#include "polynomial.h"


int main() {
	srand((unsigned int)time(NULL));	

	polynomial* a = new polynomial();
	polynomial* b = new polynomial(3);

	cout << *b << endl;
	cout << *a << endl;

	cout << *a + 1 << endl;

	cin >> *a;
	cout << *a << endl;

	cout << *b * *a << endl;

	a = b;

	cout << *a;

	return 0;
}	