#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int cards[5]{};
	int sum = 0;
	for (int i = 0; i < 5; i++) scanf("%d", &cards[i]);
	for (int i = 0; i < 5; i++) sum += cards[i];
	int n = 0, ans = 1e9;
	for (int i = 0; i < 5; i++) {
		int same = 0, cnt = 0;
		for (int j = i; j < 5; j++) {
			if (cards[i] == cards[j]) cnt++;
		}
		if (cnt > 1) same = min(cnt, 3) * cards[i];
		ans = min(ans, sum - same);
	}
	printf("%d\n", ans);
}