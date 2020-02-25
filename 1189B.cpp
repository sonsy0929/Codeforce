/*
A[n-2], A[n], A[n-1], A[n-3], A[n-4], ...
이와 같은 form을 생각해보자.
제일 큰 A[n]을 제외하고는 인접한 것끼리 A[i-1] + A[i+1] > A[i]인 것은 당연하다.
따라서, 제일 큰 A[n]에 대해서 A[n-2] + A[n-1] > A[n]인지 확인하고 성립하지 않는다면 "NO"를 출력,
그렇지 않은 경우엔 "YES"를 출력하고 위 form을 그대로 출력해주면 된다.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int maxSum = v[n - 2] + v[n - 3];
    if (maxSum <= v.back()) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0; i < n; i++) {
            if (i == n - 2) continue;
            printf("%d ", v[i]);
        }
        printf("%d\n", v[n - 2]);
    }
}