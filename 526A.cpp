/*
하... 디스크립션을 제대로 읽지 않아서
맞왜틀 5번은 넘게 했던 문제
그냥 jump 4번해서 *를 5번 밟으면 되는 문제
 */
#include <cstdio>
using namespace std;
char in[101];
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %c", in + i);
    }
    bool possible = false;
    for (int l = 1; l < N; l++){
        for (int i = 0; i < N; i++) {
            if (in[i] != '*') continue;
            int cnt = 0, curr = i;
            while (curr < N) {
                if (in[curr] == '*') cnt++;
                else break;
                curr += l;
            }
            if (cnt == 5) possible |= true;    
        }
    }
    puts(possible ? "yes" : "no");
}