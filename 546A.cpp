#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int k, n, w;
    scanf("%d %d %d", &k, &n, &w);
    int sum = 0;
    for (int i = 1; i <= w; i++){
        sum += i * k;
    }
    printf("%d\n", sum > n ? sum - n : 0);
}