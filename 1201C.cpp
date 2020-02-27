/*
�ð����⵵ : O(n/2 * log(1e9))

�Ķ��Ʈ�� ��ġ��� ����� ������ ���� ���¿��� ������ �Ͽ���.
������ �ϴٺ��� �Ķ��Ʈ�� ��ġ�� ����ص� �Ǿ��ٴ� ���� �Ķ��Ʈ�� ��ġ��� ����� �˰����� �����µ�, 
ĳġ���� ���� ���¿��� ��� ������ �Ͽ���. 
median�� x�� �ϸ�, ������ Ƚ���� max(0, x - b[i])�� i�� n/2���� n���� ���� ���̴�.
����, cnt�� k���� ũ�ٸ� maximum median�� �� �� ���� ���, �׷����ʴٸ� maximum medain�̴�.
�̷��� ���� �̿��ؼ� �Ķ��Ʈ�� ��ġ�� �̿��ϸ� �ȴ�.
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