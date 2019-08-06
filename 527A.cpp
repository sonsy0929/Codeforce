#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ll a, b;
    scanf("%lld %lld", &a, &b);
    ll ans = 0, tmp;
    do {
        tmp = b;
        ans += a / b;
        b = a % b;
        a = tmp;
    } while(b);
    printf("%lld\n", ans);
}