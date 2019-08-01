/*
모든 로봇이 도달 가능한 (X, Y) 중 아무거나 출력해도 되는 문제였는데,
답이 하나로 정해져 있는 문제인 줄 알고 계속 문제를 읽어봄...
영어 해석능력이 부족한건지,,, 아니면 디스크립션을 이해하는 능력이 부족한건지,,,

로봇이 각 command를 이행하지 못함에 따라 생기는 제약을 이용해서 풀 수 있는 문제였다.
 */
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e5;
int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        int n;
        scanf("%d", &n);
        int X[2] = {-INF, INF}, Y[2] = {-INF, INF};
        for (int i = 0; i < n; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            for (int j = 0; j < 4; j++) {
                int f;
                scanf("%d", &f);
                if (j == 0 && !f) X[0] = max(X[0], x);
                if (j == 1 && !f) Y[1] = min(Y[1], y);
                if (j == 2 && !f) X[1] = min(X[1], x);
                if (j == 3 && !f) Y[0] = max(Y[0], y);  
            }
        }
        if (X[0] > X[1] || Y[0] > Y[1]) puts("0");
        else printf("1 %d %d\n", X[1], Y[1]);
    }
}