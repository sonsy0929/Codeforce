#include <cstdio>
using namespace std;
int n;
int main() {
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &n);
		char s[301]{};
		for (int i = 0; i < n; i++) scanf(" %c", s + i);
		int a = s[0] - '0';
		int b = s[1] - '0';
		if (n == 2 && a >= b) puts("NO");
		else {
			puts("YES");
			puts("2");
			printf("%c %s\n", s[0], s + 1);
		}
	}
}