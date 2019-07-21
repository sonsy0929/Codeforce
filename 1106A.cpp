#include <cstdio>
using namespace std;
char s[500][500];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < n; j++) {
			s[i][j] = getchar();
		}
	}
	int ans = 0;
	for (int i = 1; i < n - 1; i++) for (int j = 1; j < n - 1; j++) {
		if (s[i][j] == 'X') {
			if (s[i - 1][j - 1] == s[i][j] &&
				s[i + 1][j + 1] == s[i][j] &&
				s[i - 1][j + 1] == s[i][j] &&
				s[i + 1][j - 1] == s[i][j]) ans++;
		}
	}
	printf("%d\n", ans);
}