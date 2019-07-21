#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int x[200000], y[200000];
int main() {
	int n, m, k;
	vector<int> v[20000];
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int val;
			scanf("%d", &val);
			if (val) v[i].push_back(j);
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		x[a - 1]++, y[b - 1]++;
	}
	for (int i = 0; i < n; i++) {
		int ans = 0;
		for (int k : v[i]) ans += y[k];
		ans -= x[i];
		printf("%d ", ans);
	}
}