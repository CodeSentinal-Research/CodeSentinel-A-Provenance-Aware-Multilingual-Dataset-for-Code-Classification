#include<stdio.h>
int n,t,a[1001];
int ok(int d){long long s=0;for(int i=0;i<n;i++)s+=(a[i]+d-1)/d;return s<=t;}
int main(){scanf("%d %d",&n,&t);int hi=0;for(int i=0;i<n;i++){scanf("%d",&a[i]);if(a[i]>hi)hi=a[i];}int lo=1;while(lo<hi){int mid=(lo+hi)/2;if(ok(mid))hi=mid;else lo=mid+1;}printf("%d\n",lo);}
