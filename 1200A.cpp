#include <bits/stdc++.h>
using namespace std;
int N, v[10];
int main() {
    cin >> N;
    string command;
    cin >> command;
    for (char c : command) {
        if (c == 'L') {
            int i = 0;
            while (i < 10 && v[i]) i++;
            v[i] = 1;
        } else if (c == 'R') {
            int i = 9;
            while (i >= 0 && v[i]) i--;
            v[i] = 1;
        } else {
            v[c - '0'] = 0;
        }
    }
    for (int curr : v) printf("%d", curr);
}