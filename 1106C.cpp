#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int V[300000];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", V + i);
	sort(V, V + n);
	ll ans = 0;
	for (int i = 0, k = 0; i < n / 2; i++, k++) {
		ll ret = V[k] + V[n - k - 1];
		ret *= ret;
		ans += ret;
	}
	printf("%lld\n", ans);
}