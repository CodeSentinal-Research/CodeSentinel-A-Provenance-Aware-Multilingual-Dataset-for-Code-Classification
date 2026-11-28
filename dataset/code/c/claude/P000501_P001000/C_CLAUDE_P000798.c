#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);
int mp[2*n+2];for(int i=0;i<2*n+2;i++)mp[i]=-2;mp[n]=-1;
int s=0,best=0;
for(int i=0;i<n;i++){s+=(a[i]==1?1:-1);if(mp[s+n]==-2)mp[s+n]=i;else if(i-mp[s+n]>best)best=i-mp[s+n];}
printf("%d\n",best);}
