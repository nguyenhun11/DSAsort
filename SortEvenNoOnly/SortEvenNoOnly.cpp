
#include <iostream>
using namespace std;

//RUNTIMEERROR

void bubblesort(int* a, int n) {
    while (n--) {
        for (int i = 0; i < n; i++) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}
void sort(int* a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    int soChan[100];
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            soChan[index++] = a[i];
        }
    }
    bubblesort(soChan, count);
    index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            a[i] = soChan[index++];
        }
    }

}

//
int main() {
    cout << "Sort Even No Only. Cin number of element and then the elements\n";
    int* a, n; cin >> n;
    a = new int[n];



    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
