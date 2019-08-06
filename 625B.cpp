#include <cstdio>
#include <cstring>
using namespace std;
char s[100'001], k[31];
int main(){
    scanf("%s %s", s, k);
    int sLen = strlen(s), kLen = strlen(k);
    int ans = 0, i = 0;
    while (i < sLen) {
        bool match = true;
        for (int j = 0; j < kLen; j++){
            if (s[i + j] != k[j]) {
                match = false;
                break;
            }
        }
        if(match) ans++, i += kLen;
        else i++; 
    }
    printf("%d\n", ans);
}