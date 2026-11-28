#include <stdlib.h>
static int win(int* pre, int r, int l) { return pre[r+1] - pre[r+1-l]; }
static int solve(int* pre, int n, int L, int M) {
    int best=0, res=0;
    for (int i=L+M-1;i<n;i++) {
        int w=win(pre,i-M,L); if(w>best) best=w;
        int r=best+win(pre,i,M); if(r>res) res=r;
    }
    return res;
}
int maxSumTwoNoOverlap(int* nums, int n, int firstLen, int secondLen) {
    int* pre = (int*)calloc(n+1, sizeof(int));
    for (int i=0;i<n;i++) pre[i+1]=pre[i]+nums[i];
    int a=solve(pre,n,firstLen,secondLen), b=solve(pre,n,secondLen,firstLen);
    free(pre);
    return a>b?a:b;
}
