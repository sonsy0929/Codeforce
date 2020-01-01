#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int SIZE = 2 * 1e5 + 1;
int main(){
    int n, v[SIZE]{};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", v + i);
    vector<int> L(SIZE, 1), R(SIZE, 1);
    for (int i = 0; i < n-1; i++){
        if (v[i] < v[i+1]) L[i+1] = L[i] + 1;
    }
    for (int i = n - 1; i > 0; i--){
        if (v[i] > v[i-1]) R[i-1] = R[i] + 1;
    }
    int ans = *max_element(L.begin(), L.end());
    for (int i = 0; i < n - 2; i++){
        if (v[i] < v[i+2]) ans = max(ans, L[i] + R[i+2]);
    }
    printf("%d\n", ans);
}