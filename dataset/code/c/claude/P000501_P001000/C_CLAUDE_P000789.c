#include<stdio.h>
#include<stdlib.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int k;scanf("%d",&k);
// O(n^2)
long long ans=0;
for(int i=0;i<n;i++){long long s=0;for(int j=i;j<n;j++){s+=a[j];if(s==k)ans++;}}
printf("%lld\n",ans);}
