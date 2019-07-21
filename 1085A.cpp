#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main() {
	string s;
	cin >> s;
	int _len = s.size();
	deque<char> ans;
	int b = 0, e = _len - 1;
	if (_len % 2) {
		for (int i = 0; i < _len; i++) {
			if (i % 2) ans.push_front(s[e--]);
			else ans.push_front(s[b++]);
		}
	}
	else {
		for (int i = 0; i < _len; i++) {
			if (i % 2) ans.push_front(s[b++]);
			else ans.push_front(s[e--]);
		}
	}
	for (char c : ans) cout << c;
}