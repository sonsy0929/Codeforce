#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
multiset<p> cnt, cnt2;
const int INF = 1e9;
int idx[128];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, a, b;
	long long ans = 0, zcnt = 0;
	idx['('] = 1, idx[')'] = -1;
	for (cin >> N; N; N--) {
		string s;
		int k = 0, val = INF;
		cin >> s;
		for (auto c : s) {
			k += idx[c];
			val = min(val, k);
		}
		if (k > 0) cnt.insert({ k, val });
		else if (k < 0) cnt2.insert({ k, val });
		else if (val == 0) zcnt++;
	}
	ans = zcnt / 2;
	for (auto pCurr : cnt) {
		int a = pCurr.first, b = pCurr.second;
		auto it = cnt2.lower_bound({ -a, -a });
		if (b >= 0 && it != cnt2.end() && it->first == -a) {
			ans++;
			cnt2.erase(it);
		}
	}
	cout << ans << '\n';
}