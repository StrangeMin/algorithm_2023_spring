#include <iostream>
#include <cmath>
#define LEFT 0
#define RIGHT 1
using namespace std;

int applicant[100001];
int N;
int swapCnt;

void swap(int& parent, int& child) {
	int tmp = parent;
	parent = child;
	child = tmp;
	swapCnt++;
}

int getMaxChild(int left, int right) {
	if (left > right)
		return LEFT;
	else
		return RIGHT;
}

void bubbleUpHeap(int root, int vacant) {
	if (vacant == root)
		return;

	int parent = vacant / 2;

	if (applicant[parent] < applicant[vacant]) {
		swap(applicant[parent], applicant[vacant]);
		bubbleUpHeap(root, parent);
	}
}
int promote(int hStop, int vacant, int h) {
	int vacStop;
	int left = vacant * 2;
	int right = vacant * 2 + 1;
	if (h <= hStop) { // 끝까지 내려갔으면
		vacStop = vacant;
	}
	else if (right <= N) { // 양쪽에 자식이 있는 경우
		if (getMaxChild(applicant[left], applicant[right]) == LEFT) { // 큰 값이 left이면
			swap(applicant[vacant], applicant[left]);
			vacStop = promote(hStop, left, h - 1);
		}
		else {
			swap(applicant[vacant], applicant[right]);
			vacStop = promote(hStop, right, h - 1);
		}
	}
	else if (left <= N) {
		swap(applicant[vacant], applicant[left]);
		vacStop = promote(hStop, left, h - 1);
	}
	return vacStop;
}

void downHeap(int vacant, int h) {
	if (h == 0)
		return;
	else if (h == 1) {
		int left = vacant * 2;
		int right = vacant * 2 + 1;

		if (right <= N) { // 양쪽에 자식이 있는 경우
			if (getMaxChild(applicant[left], applicant[right]) == LEFT) { // 큰 값이 left이면
				if (applicant[vacant] < applicant[left]) {
					swap(applicant[vacant], applicant[left]);
				}
			}
			else {
				if (applicant[vacant] < applicant[right]) {
					swap(applicant[vacant], applicant[right]);
				}
			}
		}
		else if (left <= N) {
			if (applicant[vacant] < applicant[left]) {
				swap(applicant[vacant], applicant[left]);
			}
		}
		return;
	}

	int hStop = h / 2;
	int vacStop = promote(hStop, vacant, h);
	int vacParent = vacStop / 2;

	if (applicant[vacParent] < applicant[vacStop]) { // 내가 부모보다 더 크다면
		swap(applicant[vacParent], applicant[vacStop]);
		bubbleUpHeap(vacant, vacParent); // downHeap을 처음 호출한 vacant를 root로 
	}
	else
		downHeap(vacStop, hStop);
}

void constructHeap(int idx) {
	if (idx > N)
		return;
	constructHeap(idx * 2);
	constructHeap(idx * 2 + 1);
	downHeap(idx, log2(N) - log2(idx));
};

void deleteMax() {
	if (N != 1) {
		swap(applicant[1], applicant[N]);
	}
	N--;

	if (N >= 2)
		downHeap(1, log2(N));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> applicant[i];
		}

		constructHeap(1);

		for (int i = 1; i <= N; i++) {
			cout << applicant[i] << " ";
		}
		cout << "\n";

		swapCnt = 0;

		int loopCnt = N;
		for (int i = 1; i <= loopCnt; i++)
			deleteMax();

		cout << swapCnt << "\n";

	}

}