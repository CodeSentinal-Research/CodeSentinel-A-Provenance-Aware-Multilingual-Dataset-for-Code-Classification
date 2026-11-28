#include <stdio.h>
int main(){int n;scanf("%d",&n);int A[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&A[i][j]);for(int i=0;i<n/2;i++)for(int j=i;j<n-1-i;j++){int t=A[i][j];A[i][j]=A[n-1-j][i];A[n-1-j][i]=A[n-1-i][n-1-j];A[n-1-i][n-1-j]=A[j][n-1-i];A[j][n-1-i]=t;}for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d%s",A[i][j],j<n-1?" ":"\n");}return 0;}
