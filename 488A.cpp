#include <iostream>
using namespace std;
bool isEight(int number) {
	for (; number; number /= 10) {
		if (number % 10 == 8 ||
			number % 10 == -8) return true;
	}
	return false;
}
int main() {
	int num, ans;
	cin >> num;
	for (ans = 1; ans <= 16; ans++) {
		if (isEight(num + ans)) break;
	}
	cout << ans;
}