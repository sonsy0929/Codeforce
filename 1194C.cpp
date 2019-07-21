/*
1. S는 T의 subsequence이어야 한다.
2. f(str, a) : str에서 글자 a가 나타나는 빈도의 수
f(s, a) + f(p, a) >= f(t, a)임을 만족해야 한다.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int Q;
    cin >> Q;
    while(Q--){
        int cnt[26]{};
        string S, T, P;
        cin >> S >> T >> P;
        for (auto c : P) cnt[c - 'a']++;
        int s = 0, t = 0;
        bool possible = true;
        while (s < S.size()){
            if (t == T.size()){
                possible = false;
                break;
            }
            if (S[s] == T[t]){
                s++, t++;
                continue;
            }
            cnt[T[t] - 'a']--;
            t++;
        }
        while (t < T.size()){
            cnt[T[t] - 'a']--;
            t++;
        }
        if (*min_element(cnt, cnt + 26) < 0) possible = false;
        if (possible) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}