/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

int calculateHIndex(int* citation, int n);

int calculateHIndex(int* citaion, int n) {
	if (n == 0) return 0;
	int N = n;
	while (n--) {
		for (int i = 0; i < n; i++) {
			if (citaion[i] < citaion[i + 1]) {
				citaion[i] = citaion[i] ^ citaion[i + 1];
				citaion[i + 1] = citaion[i] ^ citaion[i + 1];
				citaion[i] = citaion[i] ^ citaion[i + 1];
			}
		}
	}
	int hIndex = 0;
	for (int i = 0; i < N; i++) {
		if (citaion[i] >= i + 1) {
			hIndex = i + 1; 
		}
		else {
			break;
		}
	}
	return hIndex;
}

int main()
{
	int* citation;
	int n;
	int i;
	cin >> n;

	citation = new int[n];

	for (i = 0; i < n; i++)
		cin >> citation[i];

	cout << calculateHIndex(citation, n);
	return 0;


}
