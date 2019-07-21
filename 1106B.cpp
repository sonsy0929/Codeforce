#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int cost[100000], remain[100000];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", remain + i);
	for (int i = 0; i < n; i++) scanf("%d", cost + i);
	priority_queue<p, vector<p>, greater<p>> pq;
	for (int i = 0; i < n; i++) pq.push({ cost[i], i });
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; ll ans = 0;
		if (remain[a] >= b) {
			remain[a] -= b;
			ans += 1LL * b * cost[a];
		}
		else {
			int diff = b - remain[a];
			ans += 1LL * remain[a] * cost[a];
			remain[a] = 0;
			while (!pq.empty() && diff) {
				while (!pq.empty() && remain[pq.top().second] == 0) pq.pop();
				if (pq.empty()) break;
				int c = pq.top().first, idx = pq.top().second;
				pq.pop();
				if (remain[idx] >= diff) {
					ans += 1LL * diff * c;
					remain[idx] -= diff;
					diff = 0;
					pq.push({ c, idx });
				}
				else {
					ans += 1LL * remain[idx] * c;
					diff -= remain[idx];
					remain[idx] = 0;
				}
			}
			if (pq.empty()) ans = 0;
		}
		printf("%lld\n", ans);
	}
}