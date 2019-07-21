#include <cstdio>
using namespace std;
char card[5][3];
int main() {
	char table[3]{};
	scanf("%s", table);
	for (int i = 0; i < 5; i++) scanf("%s", card[i]);
	bool flag = false;
	for (int i = 0; i < 5; i++) {
		if (card[i][0] == table[0]) flag = true;
		if (card[i][1] == table[1]) flag = true;
	}
	puts(flag ? "YES" : "NO");
}