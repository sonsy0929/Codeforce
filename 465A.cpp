#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int n; char in[101]{};
    scanf("%d", &n);
    scanf(" %s", in);
    int L = strlen(in);
    int ans = 0;
    for (int i = 0; i < L; i++){
        int val = in[i] - '0';
        ans++;
        if (!val) break;
    }
    printf("%d\n", min(ans, L));
}