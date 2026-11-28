#include<stdio.h>
#include<math.h>
int n,h,piles[10001];
int ok(int k){long long s=0;for(int i=0;i<n;i++)s+=(piles[i]+k-1)/k;return s<=h;}
int main(){scanf("%d %d",&n,&h);int lo=1,hi=0;for(int i=0;i<n;i++){scanf("%d",&piles[i]);if(piles[i]>hi)hi=piles[i];}while(lo<hi){int mid=(lo+hi)/2;if(ok(mid))hi=mid;else lo=mid+1;}printf("%d\n",lo);}
