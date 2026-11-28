#include<stdio.h>
#include<stdlib.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);
// convert 0->-1, count subarrays with sum 0
long long ans=0;int s=0;
int map[2*n+2];for(int i=0;i<2*n+2;i++)map[i]=0;map[n]=1;
for(int i=0;i<n;i++){s+=(a[i]==1?1:-1);ans+=map[s+n];map[s+n]++;}
printf("%lld\n",ans);}
