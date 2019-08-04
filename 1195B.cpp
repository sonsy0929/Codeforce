/*
i(i + 1) / 2 - (n - i) = k인 i를 찾자!
binary search로도 가능하고, 
k가 최대 1e9라는 것은 n은 아무리 커봐야 최대 1e5라는 것을 의미
이를 통해 i < 1e5까지 반복문 돌리면서 해당 조건을 만족하는지 확인
 */
#include <cstdio>
using namespace std;
using ll = long long;
ll f(ll k){
    return k * (k + 1) / 2;
}
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int i = 1;
    for (; i < 100'000; i++){
        if (f(ll(i)) - (n - i) == k) break;
    }
    printf("%d\n", n - i);
}