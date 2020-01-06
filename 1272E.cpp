#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
int n;
vector<int> odd, even, ans;
vector<int> adj[200'000];
void bfs(vector<int> &s, vector<int> &e){
    queue<int> q;
    vector<int> d(n, INF);
    for (int i : s){
        q.push(i);
        d[i] = 0;
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (int next : adj[curr]){
            if (d[next] == INF){
                d[next] = d[curr] + 1;
                q.push(next);
            }
        }
    }
    for (int i : e){
        if (d[i] != INF) ans[i] = d[i];
    }
}
int main(){
    scanf("%d", &n);
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if (a[i] % 2) odd.push_back(i);
        else even.push_back(i);
    }
    for (int i = 0; i < n; i++){
        if (i + a[i] < n) adj[i + a[i]].push_back(i);
        if (i - a[i] >= 0) adj[i - a[i]].push_back(i);
    }
    ans.resize(n, -1);
    bfs(odd, even);
    bfs(even, odd);
    for (int k : ans) printf("%d ", k);
}