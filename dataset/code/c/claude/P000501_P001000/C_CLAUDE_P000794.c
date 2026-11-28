#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);long long k;scanf("%lld",&k);
long long s=0;int best=0;
for(int i=0;i<n;i++){s=0;for(int j=i;j<n;j++){s+=a[j];if(s==k&&j-i+1>best)best=j-i+1;}}
printf("%d\n",best);}
