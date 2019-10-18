/*
기존의 수열은 모르는 상태에서 변화량('q(i) = p(i) - p(i-1)')이 주어지면, 이를 토대로 기존의 수열을 복원하는 문제

p(1)을 x라 하면, 
p(2) = p(1) + q(1) 
p(3) = p(1) + q(1) + q(2)
p(4) = p(1) + q(1) + q(2) + q(3)
...
p(k) = p(1) + sigma q(n) (1 <= n < k)

따라서 x의 값만 구하면, 기존의 수열로 복원을 할 수 있다.
q'(n) = sigam q(n)이라 하고, q'(n) 중 가장 작은 값을 k라 한다면
k + x = 1을 만족해야 한다. (기존의 수열 중 가장 작은 값은 1이기 때문에)
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, pSum[200'001], d[200'001];
int main(){
    scanf("%d", &N);
    for (int i = 1; i < N; i++) scanf("%d", d+i);
    for (int i = 1; i < N; i++){
        pSum[i] = pSum[i-1] + d[i];
    }
    int minVal = *min_element(pSum, pSum + N);
    for (int i = 0; i < N; i++){
        pSum[i] += 1 - minVal;
    }
    bool possible = true;
    bool used[200'001]{};
    for (int i = 0; i < N; i++){
        if (pSum[i] <= 0 || pSum[i] > N){
            possible = false;
            break;
        }
        if (used[pSum[i]]) possible = false;
        used[pSum[i]] = true;
    }
    if (possible){
        for (int i = 0; i < N; i++) printf("%d ", pSum[i]);
    }
    else puts("-1");
}