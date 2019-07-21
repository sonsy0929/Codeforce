#include <cstdio>
using namespace std;
int a[15], n;
bool flag;
void f(int pos, int curr) {
	if (pos == n) {
		if (!curr || !(curr % 360)) flag = true;
		return;
	}
	f(pos + 1, curr + a[pos]);
	f(pos + 1, curr - a[pos]);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	f(0, 0);
	puts(flag ? "YES" : "NO");
}