#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d\n",&n);char w[n][1001];for(int i=0;i<n;i++){fgets(w[i],1001,stdin);w[i][strcspn(w[i],"\n")]=0;}int mi=0;for(int i=1;i<n;i++)if(strlen(w[i])<strlen(w[mi]))mi=i;printf("%d\n",mi);}
