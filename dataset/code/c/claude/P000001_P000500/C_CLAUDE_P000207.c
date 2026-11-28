#include <stdio.h>
#include <limits.h>
int main(){
    int r,c; scanf("%d %d",&r,&c);
    int A[r][c];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) scanf("%d",&A[i][j]);
    long long best=LLONG_MIN;
    for(int i=0;i+2<r;i++) for(int j=0;j+2<c;j++){
        long long s=A[i][j]+A[i][j+1]+A[i][j+2]+A[i+1][j+1]+A[i+2][j]+A[i+2][j+1]+A[i+2][j+2];
        if(s>best) best=s;
    }
    printf("%lld\n",best);
}
