/*
Sigma n * m <= 4 * 10^5의 의미 파악이 중요
Sigma n * m = Q * n * m
따라서 쿼리당 O(n * m)으로 수행해도, 시간초과가 발생하지 않았음!
이 문제는 '정적 배열'을 선언하기에는 조건이 sigma로 주어져 있어
'동적 배열'로 선언하는 것이 rte없이 정확한 답을 얻을 수 있음
*/
#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        int r, c;
        cin >> r >> c;
        vector<string> map;
        vector<int> R(r), C(c);
        string in;
        for (int i = 0; i < r; i++){
            cin >> in;
            map.push_back(in);
            for (int j = 0; j < c; j++){
                R[i] += map[i][j] == '*';
                C[j] += map[i][j] == '*';
            }
        }
        int ans = 1e9;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                int common = (map[i][j] == '.'); 
                ans = min(ans, r - R[i] + c - C[j] - common);
            }
        }
        printf("%d\n", ans);
    }
}