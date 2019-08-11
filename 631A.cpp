#include <cstdio>
using namespace std;
int A[1000], B[1000];
int main(){
    int N;
    scanf("%d", &N);
    int orA = 0, orB = 0;
    for (int i = 0; i < 2 * N; i++) {
        if (i < N) {
            scanf("%d", A + i);
            orA |= A[i];
        }
        else {
            scanf("%d", B + i);
            orB |= B[i];
        }
    }
    printf("%d\n", orA + orB);
}