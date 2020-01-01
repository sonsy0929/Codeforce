#include <cstdio>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;
using ll = long long;
function<int(int)> f[3] = {
    [](int x) {return x + 1;},
    [](int x) {return x - 1;},
    [](int x) {return x;}
};
int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        ll minVal = 1e18;
        for (int i = 0; i < 3; i++){
            ll ai = f[i](a);
            for (int j = 0; j < 3; j++){
                ll bj = f[j](b);
                for (int k = 0; k < 3; k++){
                    ll ck = f[k](c);
                    minVal = min(minVal, abs(ai - bj) + abs(ai - ck) + abs(bj - ck));
                }
            }
        }
        printf("%lld\n", minVal);
    }
}