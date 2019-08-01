#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string RGB[3] = {"RGB", "GBR", "BRG"};
int main(){
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        string in;
        cin >> in;
        int mn = 1e9;
        for (int d = 0; d < 3; d++) {
            string s = RGB[d];
            for (int i = 0; i < n; i++){
                int cnt = 0;
                for (int j = 0; j < k; j++) {
                    if (s[(i + j) % 3] != in[i + j]) cnt++;
                }
                mn = min(mn, cnt);
            }
        }
        cout << mn << "\n";
    }
}