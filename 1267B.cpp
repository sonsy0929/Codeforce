/*
�ð����⵵ : O(N)

�ϳ��� ����� �����ؼ� ��� ����� �����Ϸ��� ���׸�Ʈ �� ����� ����� �־� ���޾� ������ ��� �ۿ� ����.
�̷��� ���� �����غ���, 1) ���׸�Ʈ�� Ȧ���̾�� �ϰ� 2) ������ ��ϳ��� ���� ���ƾ� �ϸ� 3) segment[i / 2 + 1] + segment[i / 2 - 1] >= 3 �̾�� �Ѵ�.
�̸� �����ϸ� segement[i / 2] + 1�� ��� ����� �����ϴ� ����� ���� �Ǹ�, �̿��� ��쿡�� 0�� ����ϸ� �ȴ�.
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