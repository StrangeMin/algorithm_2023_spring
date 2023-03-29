#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

vector<int> quickSort(vector<int> seq) {
	if (seq.size()==1) {
		return seq;
	}
	vector<int> l, e, g;
	int pivot = seq.back(); 
	seq.pop_back();
	e.push_back(pivot);

	while (seq.size()) {
		int cur = seq.back();
		seq.pop_back();

		if (cur < pivot) {
			l.push_back(cur);
		}
		else if (cur == pivot) {
			e.push_back(cur);
		}
		else {
			g.push_back(cur);
		}
	}

	if(l.size())
		l = quickSort(l);
	if(g.size())
		g = quickSort(g);

	l.insert(l.end(), e.begin(), e.end());
	l.insert(l.end(), g.begin(), g.end());
	return l;
}


int main() {

	srand(time(NULL));

	cout << "배열 오름차순 정렬 전 : ";
	for (int i = 0; i < 15; i++) {
		v.push_back(rand() % 100);
		cout << v[i] << " ";
	}
	cout << "\n";


	v = quickSort(v);


	cout << "\n배열 오름차순 정렬 후 : ";
	for (int i = 0; i < 15; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";

	return 0;
}