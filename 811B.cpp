#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(n,0);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    for (int i = 0; i < m; i++){
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        l--,x--;
        int small = 0, B = r - l;
        for (int j = l; j < r; j++){
            if (v[j] < v[x]) small++;
        }
        if (small + l == x) puts("Yes");
        else puts("No");
    }
}