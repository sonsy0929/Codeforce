/*
Sigma n * m <= 4 * 10^5�� �ǹ� �ľ��� �߿�
Sigma n * m = Q * n * m
���� ������ O(n * m)���� �����ص�, �ð��ʰ��� �߻����� �ʾ���!
�� ������ '���� �迭'�� �����ϱ⿡�� ������ sigma�� �־��� �־�
'���� �迭'�� �����ϴ� ���� rte���� ��Ȯ�� ���� ���� �� ����
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