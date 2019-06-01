#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <random>
#include <ctime>
#include <iterator>

struct RndIntGen {
	RndIntGen(int l, int h) : low(l), high(h) {}
	int operator()() const {
		return low + (rand() % ((high - low) + 1));
	}
private:
	int low;
	int high;
};

struct ICN {
	int iterator = 0;
	int coutner = 0;
	int number = 0;
};

using namespace std;

template <typename VDL>
ICN printAnswer(VDL& array, int N, int x, int y) {
	ICN data;

		for (int i = 0; i < N / 10 + 1; i++) {

			int iter = 0;
			int counter = 0;

			for (int j = x; j <= y; j++) {

				if (array[j] == i) {
					if (counter == 0) iter = j;
					counter++;
				}
			}

			if (counter >= data.coutner) {
				data.number = i;
				data.coutner = counter;
				data.iterator = iter;
			}

		}

	return data;
}

ICN funcForTrash(list<int> array, int N, int x, int y) {
	auto element = array.begin();
	for (int i = 0; i < x; i++) element++;

	int diap = y - x;
	int* temp = new int[diap+1];

	for (int i = 0; i <= diap; i++) {
		temp[i] = *element;
		element++;
	}

	ICN data = printAnswer(temp, N, 0, diap);
	
	delete[] temp;

	return data;
}

void invalidValue(int N, int x, int y) {
	if (N <= 0 || x < 0 || y <=0 || x > y || x > N || y > N) {
		cout << "Incalide value, crash!" << endl;
		exit(0);
	}
}

int main() {
	srand((unsigned int)time(NULL));

	int N, x ,y;

	cout << "Enter length: ";
	cin >> N;
	cout << "Enter range. From ";
	cin >> x;
	cout << " to ";
	cin >> y;

	invalidValue(N, x, y);;

	vector<int> orderVector(N);
	deque<int> orderDeque(N);
	list<int> orderList(N);

	generate(orderVector.begin(), orderVector.end(), RndIntGen(0, N /10));
	generate(orderDeque.begin(), orderDeque.end(), RndIntGen(0, N / 10));
	generate(orderList.begin(), orderList.end(), RndIntGen(0, N / 10));

	cout << "Vector: ";
	copy(orderVector.begin(), orderVector.end(), ostream_iterator<int>(cout, " "));
	cout << endl << endl << "Deque: ";
	copy(orderDeque.begin(), orderDeque.end(), ostream_iterator<int>(cout, " "));
	cout << endl << endl << "List: ";
	copy(orderList.begin(), orderList.end(), ostream_iterator<int>(cout, " "));
	cout << endl << endl;
	
	ICN vect = printAnswer(orderVector, N, x, y);
	ICN deq = printAnswer(orderDeque, N, x, y);
	ICN lis = funcForTrash(orderList, N, x, y);

	cout << "Namber: " << vect.number << ", " << vect.coutner << " times, iter in array: " << vect.iterator << "." << endl;
	cout << "Namber: " << deq.number << ", " << deq.coutner << " times, iter in array: " << deq.iterator << "."<< endl;
	cout << "Namber: " << lis.number << ", " << lis.coutner << " times, iter in array: " << lis.iterator << "." << endl;

	return 0;
}

	








/*struct RndIntGen {
	RndIntGen(int l, int h) : low(l), high(h) {}
	int operator()() const {
		return low + (rand() % ((high - low) + 1));
	}
private:
	int low, high;

};

using namespace std;

void _gen (T & N, int k, int& summ, int& dist) {
	double count = 0;
	double sum = 0;
	for (int n : N)
		if (n % k != 0) {
			count++;
			sum += n;
		}
	sum /= count;
	auto index = find(N.begin(), N.end(), NAN);
	for (;;) {
		index = find(N.begin(), N.end(), (int)sum + 1);
		if (index != N.end())
			break;
	}
	summ = (int)sum;
	dist = distance(N.begin(), index);
} }

int main() {
	srand(time(0));
	int N, var, k;
	double den;
	cout << "Please enetr number of elements(N) and k: " << endl;
	cin >> N >> k;
	den = (double)N / 10.0;
	vector <int> sequence_v(N);
	deque <int> sequence_d(N);
	list <int> sequence_l(N);
	generate(sequence_v.begin(), sequence_v.end(), RndIntGen(0, den));
	generate(sequence_l.begin(), sequence_l.end(), RndIntGen(0, den));
	generate(sequence_d.begin(), sequence_d.end(), RndIntGen(0, den));
	cout << "Вектор:" << endl;
	copy(sequence_v.begin(), sequence_v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	_gen(sequence_v, k, sred1, dist1);
	cout << "Среднее арифметическое чисел не кратных " << k << " равно:" << sred1 << endl << "Номер элемента в исходной последовательности, наиболее близкого к " << sred1 << ": " << dist1 << endl << endl;
	cout << "Двухсвязный список:" << endl;
	copy(sequence_l.begin(), sequence_l.end(), ostream_iterator<int>(cout, " "));
	_gen(sequence_l, k, sred2, dist2);
	cout << endl;
	cout << "Среднее арифметическое чисел не кратных " << k << " равно:" << sred2 << endl << "Номер элемента в исходной последовательности, наиболее близкого к " << sred2 << ": " << dist2 << endl << endl;
	cout << "Двунаправленная очередь:" << endl;
	copy(sequence_d.begin(), sequence_d.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	//_gen(sequence_d, k, sred3, dist3);
	cout << "Среднее арифметическое чисел не кратных " << k << " равно:" << sred3 << endl << "Номер элемента в исходной последовательности, наиболее близкого к " << sred3 << ": " << dist3 << endl << endl;
	return 0;
}

template <typename VDL>
ICN printAnswer(VDL& array, int N, int x, int y) {
	ICN data;
	data.coutner = 0;
	data.iterator = 0;
	data.number = 0;
	for (int i = 0; i < N / 10 + 1; i++) {
		int iter = 0;
		int counter = 0;
		for (int j = x; j <= y; j++) {
			if (array[j] == i) {
				if (counter == 0) iter = j;
				counter++;
			}
		}
		if (counter >= data.coutner) {
			data.number = i;
			data.coutner = counter;
			data.iterator = iter;
		}
	}
	return data;
}	

*/