#include <stdio.h>
int main(){int r,c;scanf("%d %d",&r,&c);long long A[r][c],B[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%lld",&A[i][j]);for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%lld",&B[i][j]);for(int i=0;i<r;i++){for(int j=0;j<c;j++)printf("%lld%s",A[i][j]+B[i][j],j<c-1?" ":"\n");}return 0;}
