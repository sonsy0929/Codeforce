/*
�ð� ���⵵ : O(N)

greedy�ϰ� ������ �غ���, ���� �������� ���� ĭ�� �ǳʰ� �� ������ŭ�� ����� ���̸� �����ϸ鼭
����� ���濡 �־��� ���� operation�� �ϸ鼭 ������ ĭ�� ������ �� �� �ִ��� �����ϸ� �ȴ�.
��������� �� ������ �ߴµ� ������ �̽��� ������ ���� ���� �ִµ� �̷��� ���� ĳġ���� ���ؼ� ������ ���� Ʋ�ȴ�..
�������� ������ �����ѵ� �ϴ� ����������.. �Ӹ��ӿ� �̹� �� ������ ���� B�ε��� �����ϴµ� 30���̳� �ɸ��ٴ�..
�ڵ��������� ���� ������ ���� Ǯ����� �� �� �ϴ�..
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        vector<int> H(n, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &H[i]);
        }
        int bag = m;
        bool possible = true;
        for (int i = 0; i < n - 1; i++) {
            int nxt = max(0, H[i + 1] - k);
            if (H[i + 1] > H[i]) {
                if (H[i + 1] - H[i] > k) {
                    bag -= abs(H[i] - nxt);
                    H[i] = nxt;
                } else {
                    bag += abs(H[i] - nxt);
                    H[i] = nxt;
                }
            } else {
                bag += abs(H[i] - nxt);
                H[i] = nxt;
            }
            possible &= bag >= 0;
        }
        if (possible)
            puts("YES");
        else
            puts("NO");
    }
}