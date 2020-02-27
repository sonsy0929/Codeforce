/*
시간복잡도 : O(n/2 * log(1e9))

파라메트릭 서치라는 사실을 인지도 못한 상태에서 구현을 하였다.
구현을 하다보면 파라메트릭 서치를 사용해도 되었다는 점이 파라메트릭 서치라는 사실을 알고나서야 보였는데, 
캐치하지 못한 상태에서 계속 구현을 하였다. 
median을 x라 하면, 연산의 횟수는 max(0, x - b[i])를 i가 n/2부터 n까지 더한 값이다.
만약, cnt가 k보다 크다면 maximum median이 될 수 없는 경우, 그렇지않다면 maximum medain이다.
이러한 점을 이용해서 파라메트릭 서치를 이용하면 된다.
*/
#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
int n, k;
bool isPossible(long long m) {
    long long cnt = 0;
    for (int i = n / 2; i < n; i++) {
        cnt += max(0LL, m - v[i]);
    }
    return cnt > (long long)k;
}
int main() {
    scanf("%d %d", &n, &k);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
    sort(v.begin(), v.end());
    long long lo = 0, hi = 1e12;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (isPossible(mid))
            hi = mid;
        else
            lo = mid;
    }
    printf("%lld\n", lo);
}