/*
two-pointer를 사용한 풀이
[0, in.end()]에서 RGBRGBRGB~는 [1, in.end()]에서 GBRGBRGBR~과 같다
이 점에 착안하여, 미리 전처리 과정을 거쳐 RGB, GBR, BRG로 diff배열을 형성
이후, [left, right].length() = k인 two-pointer를 이용해서 답을 구할 수 있다. 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string RGB[3] = {"RGB", "GBR", "BRG"};
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
            vector<int> diff(n, 0);
            for (int i = 0; i < n; i++){
                if (s[i % 3] != in[i]) diff[i]++;
            }
            int left = 0, right = left + k - 1;
            int sum = 0;
            for (int i = 0; i < k; i++) sum += diff[i];
            while (right < n){
                mn = min(mn, sum);
                sum -= diff[left++];
                sum += diff[++right];
            }
        }
        cout << mn << '\n';
    }
}