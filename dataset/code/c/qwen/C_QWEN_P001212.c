#include <stdio.h>
#include <string.h>
long long T[501][501], F[501][501];
int main() {
    char s[501]; scanf("%s", s);
    int n = strlen(s);
    for(int i=0; i<n; i++) {
        T[i][i] = (s[i] == 'T') ? 1 : 0;
        F[i][i] = (s[i] == 'F') ? 1 : 0;
    }
    for(int len=2; len<=n; len+=2) {
        for(int i=0; i<=n-len; i++) {
            int j = i+len-1;
            for(int k=i+1; k<j; k+=2) {
                long long t1 = T[i][k-1], f1 = F[i][k-1], t2 = T[k+1][j], f2 = F[k+1][j];
                if(s[k] == '&') { T[i][j] += t1*t2; F[i][j] += t1*f2 + f1*t2 + f1*f2; }
                else if(s[k] == '|') { T[i][j] += t1*t2 + t1*f2 + f1*t2; F[i][j] += f1*f2; }
                else { T[i][j] += t1*f2 + f1*t2; F[i][j] += t1*t2 + f1*f2; }
            }
        }
    }
    printf("%lld\n", T[0][n-1]);
    return 0;
}
