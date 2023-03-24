#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void shiftVacRec(int idx, int val) {
	if (idx == 0) {
		v[idx] = val;
	}
	else if (val < v[idx-1]) {
		v[idx] = v[idx - 1];
		shiftVacRec(idx-1, val);
	}
	else {
		v[idx] = val;
	}
}

int main() {

	srand(time(NULL));

	cout << "배열 오름차순 정렬 전 : ";
	for (int i = 0; i < 15; i++) {
		v.push_back(rand() % 100);
		cout << v[i] << " ";
	}
	cout << "\n";

	for (int i = 1; i < 15; i++) {
		shiftVacRec(i, v[i]);
	}

	cout << "\n배열 오름차순 정렬 후 : ";
	for (int i = 0; i < 15; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";

	return 0;
}