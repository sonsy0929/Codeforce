#include <iostream>
#include <string>
using namespace std;
int n, A[1000], B[1000], C[1000];
bool confirm(int *p) {
	bool t[1001]{};
	for (int i = 0; i < n; i++) {
		if (t[p[i]]) return false;
		t[p[i]] = true;
	}
	return true;
}
void print() {
	for (int i = 0; i < n; i++) cout << C[i] << ' ';
	return;
}
int main() {
	int cnt = 0, idx[2]{};
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];
	for (int i = 0, k = 0; i < n; i++) {
		if (A[i] != B[i]) {
			cnt++;
			idx[k++]= i;
			continue;
		}
		C[i] = A[i];
	}
	if (cnt > 1) {
		C[idx[0]] = A[idx[0]];
		C[idx[1]] = B[idx[1]];
		if (confirm(C)) print();
		else {
			C[idx[0]] = B[idx[0]];
			C[idx[1]] = A[idx[1]];
			print();
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			C[idx[0]] = i;
			if (confirm(C)) break;
		}
		print();
	}
}