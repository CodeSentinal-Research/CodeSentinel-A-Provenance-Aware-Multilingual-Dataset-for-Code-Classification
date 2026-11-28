#include<stdio.h>
int main(){int n;scanf("%d",&n);int A[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&A[i][j]);for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d%c",j<=i?A[i][j]:0,j<n-1?' ':\'\\n');}}
