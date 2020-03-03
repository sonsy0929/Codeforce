/*
시간복잡도 : O(N)

하나의 블록을 삽입해서 모든 블록을 제거하려면 세그먼트 중 가운데에 블록을 넣어 연달아 터지는 방법 밖에 없다.
이러한 점을 생각해보면, 1) 세그먼트는 홀수이어야 하고 2) 터지는 블록끼리 색이 같아야 하며 3) segment[i / 2 + 1] + segment[i / 2 - 1] >= 3 이어야 한다.
이를 만족하면 segement[i / 2] + 1이 모든 블록을 제거하는 경우의 수가 되며, 이외의 경우에는 0을 출력하면 된다.
*/
#include <bits/stdc++.h>
using namespace std;
using p = pair<char, int>;
vector<p> v;
int main() {
    string s;
    cin >> s;
    int cnt = 1;
    char prev = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (prev != s[i]) {
            v.push_back({prev, cnt});
            prev = s[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    v.push_back({prev, cnt});
    int sz = v.size();
    bool possible = true;
    for (int i = 0; i < sz / 2; i++) {
        auto f = v[i];
        auto e = v[sz - i - 1];
        if (f.first != e.first || f.second + e.second < 3) {
            possible = false;
            break;
        }
    }
    possible &= (v.size() % 2) && (v[sz / 2].second >= 2);
    if (!possible)
        puts("0");
    else
        printf("%d\n", v[sz / 2].second + 1);
}