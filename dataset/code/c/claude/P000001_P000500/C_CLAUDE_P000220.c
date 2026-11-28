#include<stdio.h>
int main(){int n;scanf("%d",&n);int M[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&M[i][j]);int c=0;for(int i=1;i<n;i++)if(M[c][i])c=i;for(int i=0;i<n;i++)if(i!=c&&(M[c][i]||!M[i][c])){printf("-1\n");return 0;}printf("%d\n",c);}
