#include <cstdio>
using namespace std;
int main() {
	int n, cnt = 0;
	char phone[100]{};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %1c", phone + i);
		if (phone[i] == '8') cnt++;
	}
	if (cnt) {
		int ans = n / 11;
		printf("%d\n", ans > cnt ? cnt : ans);
	}
	else puts("0");
}