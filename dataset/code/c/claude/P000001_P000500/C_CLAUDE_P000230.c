#include<stdio.h>
#include<string.h>
int main(){int r,c;scanf("%d %d",&r,&c);int A[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&A[i][j]);int first=1;for(int v=0;v<=10000;v++){int inAll=1;for(int i=0;i<r;i++){int found=0;for(int j=0;j<c;j++)if(A[i][j]==v){found=1;break;}if(!found){inAll=0;break;}}if(inAll){if(!first)printf(" ");printf("%d",v);first=0;}}printf("\n");}
