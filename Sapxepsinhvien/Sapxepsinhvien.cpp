
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <limits>
#include <string>
#include <string.h>
using namespace std;
#define MAXN 100

struct Ngay {
    int d, m, y;
};
struct SinhVien {
    char MASV[10];
    char HoTen[MAXN];
    Ngay NamSinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
void NhapNgay(Ngay& day) {
    cin >> day.d >> day.m >> day.y;
}
void NhapSinhVien(SinhVien& A) {
    //cin.ignore();
    cin.getline(A.MASV, 10);
    cin.getline(A.HoTen, MAXN);
    NhapNgay(A.NamSinh);
    cin.ignore();
    cin >> A.GioiTinh >> A.DiemToan >> A.DiemLy >> A.DiemHoa;
    A.DTB = (A.DiemToan + A.DiemHoa + A.DiemLy) / 3;

}
void Nhap(SinhVien*& A, int& n) {
    cin >> n;
    A = new SinhVien[n];
    for (int i = 0; i < n; i++) {
        cin >> ws;
        NhapSinhVien(A[i]);
    }
}
void XuatNgay(Ngay day) {
    cout << day.d << "/" << day.m << "/" << day.y;
}
void XuatSinhVien(SinhVien A) {
    cout << A.MASV << "\t" << A.HoTen << "\t";
    XuatNgay(A.NamSinh);
    cout << "\t" << A.GioiTinh << "\t" << A.DiemToan << "\t" << A.DiemLy << "\t" << A.DiemHoa << "\t";
    cout << setprecision(2) << A.DTB;
}
void Xuat(SinhVien* A, int n) {
    if (n == 0) cout << "Empty List.";
    else for (int i = 0; i < n; i++) {
        XuatSinhVien(A[i]);
        cout << endl;
    }
}
void MergeSinhVien(SinhVien* A, int l, int mid, int r) {
    int i = l, j = mid + 1, k = 0;
    SinhVien* merged = new SinhVien[r - l + 1];
    while (i <= mid && j <= r) {
        if (strcmp(A[i].MASV, A[j].MASV) > 0) merged[k++] = A[i++];
        else merged[k++] = A[j++];
    }
    while (i <= mid) merged[k++] = A[i++];
    while (j <= r) merged[k++] = A[j++];
    for (int t = 0; t < k; t++) {
        A[l + t] = merged[t];
    }
    delete[] merged;
}
void TopDownMergeSortSinhVien(SinhVien* A, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        TopDownMergeSortSinhVien(A, l, mid);
        TopDownMergeSortSinhVien(A, mid + 1, r);
        MergeSinhVien(A, l, mid, r);
    }
}
void SapXepGiamTheoMASV(SinhVien* A, int n) {
    TopDownMergeSortSinhVien(A, 0, n - 1);
}

//void SapXepGiamTheoMASV(SinhVien* A, int n) { //Bubble sort
//    while (n--) {
//        for (int i = 0; i < n; i++) {
//            if (strcmp(A[i].MASV, A[i + 1].MASV) < 0) {
//                SinhVien temp = A[i];
//                A[i] = A[i + 1];
//                A[i + 1] = temp;
//            }
//        }
//    }
//}

int main() {
    SinhVien* A;
    int n;
    Nhap(A, n);
    SapXepGiamTheoMASV(A, n);
    Xuat(A, n);
    return 0;
}
