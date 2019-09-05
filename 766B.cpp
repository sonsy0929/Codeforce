#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; i++){
        int in;
        scanf("%d", &in);
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 2; i++){
        if (v[i] + v[i+1] > v[i+2]){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}