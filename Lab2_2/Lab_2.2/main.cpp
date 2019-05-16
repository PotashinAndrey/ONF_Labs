#include <iostream>
#include <math.h>
#include "C_Circle.h"
#include "C_Circle_Color.h"


using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	C_Circle *fObj = new C_Circle();
	C_Circle* sObj = new C_Circle(3, 10, 5);

	C_Circle_Color* ffObj = new C_Circle_Color();
	C_Circle_Color* ssObj = new C_Circle_Color(1, 1, 1, 22, 33, 44);

	fObj->alert();
	sObj->alert();

	ffObj->alert();
	ssObj->alert();

	return 0;
}