#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);
long long tot=0;
for(int i=0;i<n;i++){int mn=a[i],mx=a[i];for(int j=i;j<n;j++){if(a[j]<mn)mn=a[j];if(a[j]>mx)mx=a[j];tot+=mx-mn;}}
printf("%lld\n",tot);}
