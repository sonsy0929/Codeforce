/*
Note that rk is always n but you should print it anyway.

Ȧ + Ȧ = ¦
Ȧ + ¦ = Ȧ
¦ + ¦ = ¦

������ 2k(¦��)��� �־��� Ȧ���� ������ ¦���̾�� �Ѵ�.
���� ������ 2k + 1(Ȧ��)��� �־��� Ȧ���� ���� ���� Ȧ���̾� �Ѵ�.
(�� ������ ���� Ȧ���̷���, �� ������ �־�� �� Ȧ���� ������ Ȧ���̾�� �ϱ� ������)
 */
#include <cstdio>
#include <vector>
using namespace std;
int in[2 * 100000];
int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) scanf("%d", in + i);
        int oddCnt = 0;
        for (int i = 0; i < n; i++) {
            if (in[i] % 2) oddCnt++;
        }
        if (oddCnt < k || oddCnt % 2 != k % 2) puts("NO");
        else {
            puts("YES");
            for (int i = 0; i < n; i++){
                if (in[i] % 2 == 0) continue;
                if (k > 1) {
                    printf("%d ", i + 1);
                    k--;
                }
            }
            printf("%d\n", n);
        }
    }
}