#include <iostream>
#include <climits>
//#include <bits/stdc++.h>
#define MAXN 150000

void NhapMang(int A[], int& N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}


void merge_2_Sorted_subArray(int a[], int l, int  middle, int r) {
    int* merged = new int[r + 1 - l];
    int i = l, j = middle + 1, k = 0;
    while (i <= middle && j <= r) {
        if (a[i] < a[j]) {
            merged[k] = a[i];
            i++;
            k++;
        }
        else
        {
            merged[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= middle) {
        merged[k] = a[i];
        i++;
        k++;
    }
    while (j <= r) {
        merged[k] = a[j];
        j++;
        k++;
    }
    for (int x = 0; x < k; x++) {
        a[l + x] = merged[x];
    }
    delete[] merged;
}



void XuatMang(int A[], const int& N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    int l = 0, r = n - 1, middle = (l + r) / 2;
    merge_2_Sorted_subArray(a, l, middle, r);

    XuatMang(a, n);

    return 0;
}
