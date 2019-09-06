#include <cstdio>
using namespace std;
using ll = long long;
int main(){
    ll n, prev;
    scanf("%lld", &n);
    n--;
    if (n % 2) printf("%lld\n", n/2+1);
    else printf("%lld\n", -n/2-1);
}