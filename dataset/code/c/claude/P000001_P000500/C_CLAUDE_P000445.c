#include<stdio.h>
int main(){int r,c,x;scanf("%d %d %d",&r,&c,&x);int mat[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&mat[i][j]);int lo=0,hi=r*c-1;while(lo<=hi){int m=(lo+hi)/2,v=mat[m/c][m%c];if(v==x){printf("Found\n");return 0;}else if(v<x)lo=m+1;else hi=m-1;}printf("Not Found\n");}
