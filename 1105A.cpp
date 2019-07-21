#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int V[1000];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", V + i);
	int minVal = 1e9, ans;
	for (int i = 1; i <= 100; i++) {
		int t = i;
		int ret = 0;
		for (int j = 0; j < n; j++) {
			int diff = abs(V[j] - t);
			if (diff <= 1) continue;
			if (V[j] < t) ret += abs(V[j] - (t - 1));
			else ret += abs(V[j] - (t + 1));
		}
		if (minVal > ret) {
			minVal = ret;
			ans = t;
		}
	}
	printf("%d %d\n", ans, minVal);
}