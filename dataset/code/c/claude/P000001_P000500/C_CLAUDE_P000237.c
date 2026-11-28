#include<stdio.h>
int main(){int r,c,k;scanf("%d %d %d",&r,&c,&k);k%=c;for(int i=0;i<r;i++){int row[c];for(int j=0;j<c;j++)scanf("%d",&row[j]);for(int j=0;j<c;j++)printf("%d%c",row[(j+k)%c],j<c-1?' ':\'\\n');}}
