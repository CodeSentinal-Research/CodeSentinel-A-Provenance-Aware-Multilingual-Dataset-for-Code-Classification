#include <stdio.h>
#define MOD 1000000007
int main() {
    int n; scanf("%d", &n);
    long long cur[2][3] = {{1,1,1}, {0,0,0}};
    for(int i=1; i<=n; i++) {
        long long nxt[2][3] = {0};
        for(int j=0; j<2; j++) for(int k=0; k<3; k++) {
            if(!cur[j][k]) continue;
            nxt[j][0] = (nxt[j][0] + cur[j][k]) % MOD;
            if(k<2) nxt[j][k+1] = (nxt[j][k+1] + cur[j][k]) % MOD;
            if(j<1) nxt[j+1][0] = (nxt[j+1][0] + cur[j][k]) % MOD;
        }
        for(int j=0; j<2; j++) for(int k=0; k<3; k++) cur[j][k] = nxt[j][k];
    }
    long long ans = 0;
    for(int j=0; j<2; j++) for(int k=0; k<3; k++) ans = (ans + cur[j][k]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
