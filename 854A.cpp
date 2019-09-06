#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}
int main(){
    int n, mx = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n/2; i++){
        if (i == n-i) break;
        if (gcd(i, n-i) == 1){
            mx = max(i, mx);
        }
    }
    printf("%d %d\n", mx, n - mx);
}