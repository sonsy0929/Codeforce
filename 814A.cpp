#include <cstdio>
using namespace std;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int A[100], B[100]{};
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	for (int i = 0; i < k; i++) scanf("%d", &B[i]);
	if (k == 1) {
		for (int i = 0; i < n; i++) if (!A[i]) A[i] = B[0];
		bool flag = false;
		for (int i = 0; i < n - 1; i++) {
			if (A[i] >= A[i + 1]) flag = true;
		}
		if (flag) puts("Yes");
		else puts("No");
	}
	else puts("Yes");
}