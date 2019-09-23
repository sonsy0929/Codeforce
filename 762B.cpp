#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
using p = pair<int,int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, l;
    cin >> a >> b >> c >> l;
    priority_queue<p> pq;
    for (int i = 0; i < l; i++){
        int val;
        string s;
        cin >> val >> s;
        if (s == "USB") pq.push({-val, 0});
        else pq.push({-val, 1});
    }
    int cnt = 0;
    long long price = 0;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        if (top.second == 0){
            if (a) a--;
            else if (c) c--;
            else continue;
            cnt++;
            price += top.first;
        }
        else{
            if (b) b--;
            else if (c) c--;
            else continue;
            cnt++;
            price += top.first;
        }
    }
    cout << cnt << " " << -price << "\n";
}