#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int c, a, b;
    scanf("%d %d %d", &c, &a, &b);
    int n;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int in;
        scanf("%d", &in);
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    int left = upper_bound(v.begin(), v.end(), a) - v.begin();
    int right = lower_bound(v.begin(), v.end(), b) - v.begin();
    printf("%d\n", right - left);
}