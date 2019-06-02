#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>

using namespace std;

double function(double x, double b) {
	if (sinh(x - b) == 0) {
		throw 1;
	}

	if (cosh(x + b) / sinh(x - b) < 0) {
		throw 2;
	}
	return sqrt(cosh(x + b) / sinh(x - b));
}

int main()
{
	double a, b;

	cin >> a >> b;
	try {
		cout << function(a, b);
	}
	catch (int er) {
		switch (er)
		{
		case 1:
			cout << "Division by zero!" << endl;
			break;
		case 2:
			cout << "Negative value under the root!" << endl;
			break;
		}
		cout << "Error catched! Type code : " << er;
	}
	return 0;
}
