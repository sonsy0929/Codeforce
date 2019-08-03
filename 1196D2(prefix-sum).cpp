/*
prefix-sum을 사용한 풀이
prefix-sum을 이용해서 각 구간의 합을 O(n)만에 구할 수 있다!!
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string RGB[3] = {"RGB", "GBR", "BRG"};
int diff[200'001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        string in;
        cin >> in;
        int mn = 1e9;
        for (int d = 0; d < 3; d++){
            string s = RGB[d];
            for (int i = 0; i < n; i++){
                diff[i + 1] = diff[i] + (in[i] != s[i % 3]);
                if (i >= k - 1) mn = min(mn, diff[i + 1] - diff[i + 1 - k]);
            } 
        }
        cout << mn << '\n';
    }
}