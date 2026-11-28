#include <stdio.h>
int main(){int r,c;scanf("%d %d",&r,&c);int A[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&A[i][j]);for(int j=0;j<c;j++){for(int i=0;i<r;i++)printf("%d%s",A[i][j],i<r-1?" ":"\n");}return 0;}
