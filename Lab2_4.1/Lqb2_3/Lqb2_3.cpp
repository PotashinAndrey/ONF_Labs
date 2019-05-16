#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>

using namespace std;

double function(double x, double b) {

	try {
		if (sinh(x - b) == 0) {
			cout << "Division by zero!" << endl;
			throw 1;
		}

		if (cosh(x + b) / sinh(x - b) < 0) {
			cout << "Negative value under the root!" << endl;
			throw 2;
		}

		return sqrt(cosh(x + b) / sinh(x - b));
	}
	catch (int error) {
		cout << "Error catched! Type code : ";

		return error; 
	}
}

int main()
{
	double a, b;

	cin >> a >> b;
	cout << function(a, b);

	return 0;
}
