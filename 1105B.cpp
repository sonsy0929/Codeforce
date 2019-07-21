#include <cstdio>
#include <algorithm>
using namespace std;
char s[200001];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf(" %c", s + i);
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		char c = 'a' + i;
		int ret = 0;
		for (int j = 0; j < n; j++) {
			int m = j, cnt = 0;
			for (; s[m] == c; m++, cnt++);
			if (cnt >= k) ret += cnt / k;
			if (cnt) j = m - 1;
		}
		ans = max(ans, ret);
	}
	printf("%d\n", ans);
}