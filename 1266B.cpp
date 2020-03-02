#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        long long in;
        scanf("%lld", &in);
        int R = in % 14;
        if (in <= 14)
            puts("NO");
        else if (R > 6 || !R)
            puts("NO");
        else
            puts("YES");
    }
}