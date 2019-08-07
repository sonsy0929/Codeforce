/*
디스크립션을 제대로 파악하자... ㅠㅠㅠ
중복 여부를 확인하는 것이 아닌, 순서가 유지되는지 확인하는 것이 문제에서 요구하는 사항이었음..
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char in[501];
int main(){
    scanf("%s", in);
    int _len = strlen(in);
    bool used[26]{};
    bool ret = true;
    int order = 0;
    for (int i = 0; i < _len; i++) {
        int k = in[i] - 'a';
        if (used[k]) continue;
        if (order != k) ret = false;
        if (!used[k]) order++;
        used[k] = true;
    }
    if (ret) puts("YES");
    else puts("NO");
}