#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
void f(int a, int k) {
    if (a > m) return;
    if (a == m) {
        cnt = k;
        return;
    }
    f(a * 2, k + 1);
    f(a * 3, k + 1);
}
int main() {
    scanf("%d %d", &n, &m);
    cnt = 1e9;
    f(n, 0);
    printf("%d\n", cnt != 1e9 ? cnt : -1);
}