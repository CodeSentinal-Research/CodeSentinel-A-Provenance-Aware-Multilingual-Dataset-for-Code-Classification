#include<stdio.h>
int main(){int m;scanf("%d",&m);int target[m];for(int i=0;i<m;i++)scanf("%d",&target[i]);int n;scanf("%d",&n);int cur=1;for(int i=0;i<m;i++){while(cur<target[i]){printf("Push\nPop\n");cur++;}printf("Push\n");cur++;}}
