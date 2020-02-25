#include <bits/stdc++.h>
using namespace std;
string input[3];
int kontsuCnt() {
    int cnt = 2;
    sort(input, input + 3);
    for (int i = 0; i < 2; i++) {
        if (input[i] == input[i + 1]) cnt--;
    }
    return cnt;
}
int shuntsuCnt() {
    int cnt = 2;
    sort(input, input + 3, [](const string &u, const string &v) {
        if (u[1] != v[1]) return u[1] < v[1];
        return u[0] < v[0];
    });
    bool noDraw = true;
    for (int i = 0; i < 2; i++) {
        noDraw &= input[i + 1][1] == input[i][1];
        noDraw &= input[i + 1][0] - input[i][0] == 1;
    }
    if (noDraw) return 0;
    for (int i = 0; i < 2; i++) {
        if (input[i + 1][1] != input[i][1]) continue;
        int diff = input[i + 1][0] - input[i][0];
        if (diff == 1 || diff == 2) return 1;
    }
    return 2;
}
int main() {
    for (int i = 0; i < 3; i++) {
        cin >> input[i];
    }
    printf("%d\n", min(shuntsuCnt(), kontsuCnt()));
}