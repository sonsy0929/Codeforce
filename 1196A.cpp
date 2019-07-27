#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("%lld\n", (a + b + c) / 2);
    }
}