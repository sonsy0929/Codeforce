#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, A[100]{};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", A + i);
	sort(A, A + n);
	int sum = 0, cnt = 0;
	double avg = 0;
	for (int i = 0; i < n; i++) sum += A[i];
	avg = (double)sum / (double)n;
	if (avg >= 4.5) {
		puts("0");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		A[i] = 5;
		int t_sum = 0;
		for (int j = 0; j < n; j++) t_sum += A[j];
		avg = (double)t_sum / (double)n;
		cnt++;
		if (avg >= 4.5) break;
	}
	printf("%d\n", cnt);
}