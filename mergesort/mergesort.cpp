#include <iostream>
//#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

void NhapMang(int* a, int& n) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void XuatMang(int A[], const int& N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}


void Merge(int a[], int l, int mid, int r) {
    int i = l, j = mid + 1, k = 0;
    int* merged = new int[r - l + 1];
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) {
            merged[k++] = a[i++];
        }
        else merged[k++] = a[j++];
    }
    while (i <= mid) merged[k++] = a[i++];
    while (j <= r) merged[k++] = a[j++];
    for (int t = 0; t < k; t++) {
        a[t + l] = merged[t];
    }
    delete[] merged;
}
void TopDownMergeSort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        TopDownMergeSort(a, l, mid);
        TopDownMergeSort(a, mid + 1, r);
        Merge(a, l, mid, r);
    }
}
void MergeSort(int a[], int n) {
    TopDownMergeSort(a, 0, n - 1);
}


int main() {
    int n, a[MAXN];
    NhapMang(a, n);

    MergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
