#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n],cnt[200001]={};for(int i=0;i<n;i++){scanf("%d",&a[i]);cnt[a[i]+100000]++;}
int j=0;for(int i=0;i<n;i++)if(cnt[a[i]+100000]==1)a[j++]=a[i];
for(int i=0;i<j;i++)printf("%d%c",a[i],i<j-1?' ':'\n');}
