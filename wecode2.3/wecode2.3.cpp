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
int min(int a, int b) {
    return (a < b) ? a : b;
}
void BottomUpMergeSort(int a[], int n) {
    for (int width = 1; width < n; width *= 2) {
        for (int i = 0; i < n; i += 2 * width) {
            int l = i;
            int mid = min(i + width - 1, n - 1);
            int r = min(i + 2 * width - 1, n - 1);
            if (mid < r) Merge(a, l, mid, r);
        }
    }
}
void MergeSort(int* a, int n) {
    BottomUpMergeSort(a, n);
}

int main() {
    int n, a[MAXN];
    NhapMang(a, n);

    MergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
