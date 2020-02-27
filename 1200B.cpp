/*
시간 복잡도 : O(N)

greedy하게 생각을 해보면, 현재 지점에서 다음 칸을 건너갈 수 있을만큼만 블록의 높이를 유지하면서
블록을 가방에 넣었다 빼는 operation을 하면서 마지막 칸에 도착을 할 수 있는지 조사하면 된다.
여기까지는 잘 생각을 했는데 구현의 미스와 음수가 생길 수도 있는데 이러한 점을 캐치하지 못해서 굉장히 많이 틀렸다..
구현력이 굉장히 부족한듯 하다 ㅋㅋㅋㅋㅋ.. 머리속에 이미 다 생각한 것을 B인데도 구현하는데 30분이나 걸리다니..
코드포스에서 구현 문제를 많이 풀어봐야 할 듯 하다..
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