/*
well-known dp
boj에 있는 스티커랑 같은 문제
Editorial에는 메모리를 쓰지않고 구하는 방법이 소개됨

This dynamic programming can be calculated almost without using memory 
because we need only the i−1th row to calculate the i-th row of this dp.
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 100'000;
int N, v[MAX][2];
ll dp[MAX][3];
ll f(int c, int prev){
    if (c == N) return 0;
    ll &ret = dp[c][prev];
    if (ret != -1) return ret;
    ret = f(0, c + 1);
    if (prev != 1) ret = max(ret, f(c + 1, 1) + v[c][0]);
    if (prev != 2) ret = max(ret, f(c + 1, 2) + v[c][1]);
    return ret;
}
int main(){
    scanf("%d", &N);
    for (int k = 0; k < 2; k++){
        for (int i = 0; i < N; i++){
            int in;
            scanf("%d", &in);
            v[i][k] = in;
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", f(0, 0));
}