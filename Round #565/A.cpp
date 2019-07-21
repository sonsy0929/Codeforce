#include <cstdio>
using namespace std;
typedef long long ll;
int f(ll param) {
	int ret = 0;
	while (param) {
		if (param == 1) return ret;
		else if (param % 2 == 0) {
			ret++;
			param /= 2;
		}
		else if (param % 3 == 0) {
			ret++;
			param *= 2;
			param /= 3;
		}
		else if (param % 5 == 0) {
			ret++;
			param *= 4;
			param /= 5;
		}
		else return -1;
	}
	return -1;
}
int main() {
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		long long val;
		scanf("%lld", &val);
		printf("%d\n", f(val));
	}
}