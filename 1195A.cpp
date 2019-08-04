/*
good : 좋아하는 음료수를 먹을 수 있는 사람
bad : 좋아하는 음료수를 먹을 수 없는 사람
answer = good + [bad / 2]
 */
#include <cstdio>
#include <map>
using namespace std;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        int in;
        scanf("%d", &in);
        mp[in]++;
    }
    int cnt = 0, ans = 0;
    for (auto p : mp){
        if (p.second % 2) cnt++;
        ans += p.second / 2 * 2;
    }
    ans += (cnt + 1) / 2;
    printf("%d\n", ans);
}