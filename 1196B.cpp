/*
Note that rk is always n but you should print it anyway.

홀 + 홀 = 짝
홀 + 짝 = 홀
짝 + 짝 = 짝

구역이 2k(짝수)라면 주어진 홀수의 개수도 짝수이어야 한다.
만약 구역이 2k + 1(홀수)라면 주어진 홀수의 개수 또한 홀수이어 한다.
(각 구간의 합이 홀수이려면, 그 구간에 넣어야 할 홀수의 개수가 홀수이어야 하기 때문에)
 */
#include <cstdio>
#include <vector>
using namespace std;
int in[2 * 100000];
int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) scanf("%d", in + i);
        int oddCnt = 0;
        for (int i = 0; i < n; i++) {
            if (in[i] % 2) oddCnt++;
        }
        if (oddCnt < k || oddCnt % 2 != k % 2) puts("NO");
        else {
            puts("YES");
            for (int i = 0; i < n; i++){
                if (in[i] % 2 == 0) continue;
                if (k > 1) {
                    printf("%d ", i + 1);
                    k--;
                }
            }
            printf("%d\n", n);
        }
    }
}