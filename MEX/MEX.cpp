#include <iostream>
using namespace std;


void Merge(int* a, int l, int mid, int r) {
	int i = l, j = mid + 1, k = 0;
	int* merged = new int[r - l + 1];
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) merged[k++] = a[i++];
		else merged[k++] = a[j++];
	}
	while (i <= mid) merged[k++] = a[i++];
	while (j <= r)merged[k++] = a[j++];
	for (int t = 0; t < k; t++) {
		a[l + t] = merged[t];
	}
	delete[] merged;
}
void TopDownMergeSort(int* a, int l, int r) {
	if (l < r) {
		int mid = (r + l) / 2;
		TopDownMergeSort(a, l, mid);
		TopDownMergeSort(a, mid + 1, r);
		Merge(a, l, mid, r);
	}
}



int FindMEX(int* a, int n) {
	TopDownMergeSort(a, 0, n - 1);
	int expect = 0;
	for (int i = 0; i < n; i++) {
		
		if (expect - a[i] == 1) expect--;
		if (a[i] != expect) {

			return expect;
		}
		expect++;
	}
	return expect;

}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << FindMEX(a, n);
	delete[]a;
}