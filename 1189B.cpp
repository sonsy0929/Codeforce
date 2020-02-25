/*
A[n-2], A[n], A[n-1], A[n-3], A[n-4], ...
�̿� ���� form�� �����غ���.
���� ū A[n]�� �����ϰ�� ������ �ͳ��� A[i-1] + A[i+1] > A[i]�� ���� �翬�ϴ�.
����, ���� ū A[n]�� ���ؼ� A[n-2] + A[n-1] > A[n]���� Ȯ���ϰ� �������� �ʴ´ٸ� "NO"�� ���,
�׷��� ���� ��쿣 "YES"�� ����ϰ� �� form�� �״�� ������ָ� �ȴ�.
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